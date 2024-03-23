package dao;

import java.sql.PreparedStatement;

import model.TheBanDoc075;

public class DKTheBanDocDAO075 extends BaseDAO075 {

	public DKTheBanDocDAO075() {
		super();
		// TODO Auto-generated constructor stub
	}

	public boolean saveLibCard(TheBanDoc075 card) {
		System.out.println(card.toString());
		boolean status = false;
		String sql = "INSERT INTO tblthebandoc (readerID) VALUES (?);";

		try {
			PreparedStatement ps = connection.prepareStatement(sql);
			ps.setInt(1, card.getReaderID());
			ps.executeUpdate();
			
			status = true;
			
			ps.close();
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
			System.out.println("SQLException: " + e.getMessage());
		}
		return status;
	}
}
