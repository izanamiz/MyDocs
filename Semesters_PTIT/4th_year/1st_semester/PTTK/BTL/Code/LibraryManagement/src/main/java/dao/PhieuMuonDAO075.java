package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;

import model.PhieuMuon075;
import model.TaiLieu075;

public class PhieuMuonDAO075 extends BaseDAO075 {
	public ArrayList<TaiLieu075> viewReceipt(String receiptID, PhieuMuon075 pm) {
		String sql = "SELECT t.id, t.name, t.author, p.id AS pID, p.date, p.id AS cardID, v.name AS readerName\r\n"
				+ "FROM libman.tbltailieu AS t\r\n"
				+ "LEFT JOIN libman.tbltailieuphieumuon AS tp ON t.id = tp.docID\r\n"
				+ "LEFT JOIN libman.tblphieumuon AS p ON tp.receiptID = p.id\r\n"
				+ "LEFT JOIN libman.tblthebandoc AS r ON p.cardID = r.id\r\n"
				+ "LEFT JOIN libman.tblthanhvien AS v ON v.id = r.readerID\r\n" + "WHERE p.id = ?";

		ArrayList<TaiLieu075> ans = null;

		try {
			PreparedStatement ps = connection.prepareStatement(sql);
			ps.setString(1, receiptID);

			ResultSet rs = ps.executeQuery();
			while (rs.next()) {
				if (ans == null)
					ans = new ArrayList<TaiLieu075>();

				TaiLieu075 doc = new TaiLieu075();

				doc.setId(rs.getInt("id"));
				doc.setName(rs.getString("name"));
				doc.setAuthor(rs.getString("author"));

				ans.add(doc);

				pm.setId(rs.getInt("pID"));
				pm.setDate(rs.getString("date"));
				pm.setCardID(rs.getInt("cardID"));
				pm.setName(rs.getString("readerName"));
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
