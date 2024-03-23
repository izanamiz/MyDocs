package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;

import model.PhieuMuon075;
import model.TaiLieu075;

public class TaiLieuPhieuMuonDAO075 extends BaseDAO075 {
	public ArrayList<PhieuMuon075> viewDetails(String docID, String start, String end, TaiLieu075 tl) {
		String sql = "SELECT t.id, t.name, p.id AS pID, p.date, r.id as cardID, v.name as readerName\r\n"
				+ "FROM libman.tbltailieu AS t\r\n"
				+ "LEFT JOIN libman.tbltailieuphieumuon AS tp ON t.id = tp.docID\r\n"
				+ "LEFT JOIN libman.tblphieumuon AS p ON tp.receiptID = p.id\r\n"
				+ "LEFT JOIN libman.tblthebandoc AS r ON p.cardID = r.id\r\n"
				+ "LEFT JOIN libman.tblthanhvien AS v ON v.id = r.readerID\r\n"
				+ "WHERE t.id = ? AND p.date BETWEEN ? AND ?";

		ArrayList<PhieuMuon075> ans = null;

		try {
			PreparedStatement ps = connection.prepareStatement(sql);
			ps.setString(1, docID);
			ps.setString(2, start);
			ps.setString(3, end);

			ResultSet rs = ps.executeQuery();
			while (rs.next()) {
				if (ans == null)
					ans = new ArrayList<PhieuMuon075>();

				PhieuMuon075 pm = new PhieuMuon075();
				pm.setId(rs.getInt("pID"));
				pm.setDate(rs.getString("date"));
				pm.setCardID(rs.getInt("cardID"));
				pm.setName(rs.getString("readerName"));

				ans.add(pm);

				tl.setId(rs.getInt("id"));
				tl.setName(rs.getString("name"));
			}

			ps.close();
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
			System.out.println("SQLException: " + e.getMessage());
			ans = null;
		}
		return ans;
	}
}
