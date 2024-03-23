package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;

import org.apache.catalina.tribes.transport.RxTaskPool;

import model.TaiLieu075;

public class TKTaiLieuDAO075 extends BaseDAO075 {

	public TKTaiLieuDAO075() {
		super();
		// TODO Auto-generated constructor stub
	}

	public ArrayList<TaiLieu075> countDocsByBorrows(String start, String end) {
		String sql = "SELECT t.*, COUNT(p.id) AS numBorrows\r\n" + "FROM libman.tbltailieu AS t\r\n"
				+ "LEFT JOIN libman.tbltailieuphieumuon AS tp ON t.id = tp.docID\r\n"
				+ "LEFT JOIN libman.tblphieumuon AS p ON tp.receiptID = p.id\r\n" + "WHERE p.date BETWEEN ? AND ?\r\n"
				+ "GROUP BY t.id, t.name, t.author, t.category\r\n" + "ORDER BY numBorrows DESC;";
		
		ArrayList<TaiLieu075> ans = null;

		try {
			PreparedStatement ps = connection.prepareStatement(sql);
			ps.setString(1, start);
			ps.setString(2, end);

			ResultSet rs = ps.executeQuery();
			while (rs.next()) {
				if (ans == null)
					ans = new ArrayList<TaiLieu075>();
				TaiLieu075 doc = new TaiLieu075();

				doc.setId(rs.getInt("id"));
				doc.setName(rs.getString("name"));
				doc.setAuthor(rs.getString("author"));
				doc.setCategory(rs.getString("category"));
				doc.setDesc(rs.getString("desc"));
				doc.setImg(rs.getString("img"));
				doc.setNumBorrows(rs.getInt("numBorrows"));

				ans.add(doc);
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
