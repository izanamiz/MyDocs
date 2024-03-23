package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;

import model.ThanhVien075;

public class ThanhVienDAO075 extends BaseDAO075 {

	public ThanhVienDAO075() {
		super();
		// TODO Auto-generated constructor stub
	}

	public boolean validate(ThanhVien075 tv) {
		boolean status = false;
		String sql = "select * from tblthanhvien where username = ? and password = ?";

		try {
			PreparedStatement ps = connection.prepareStatement(sql);
			ps.setString(1, tv.getUsername());
			ps.setString(2, tv.getPassword());

			ResultSet rs = ps.executeQuery();
			
			while (rs.next()) {
				tv.setId(rs.getInt("id"));
				tv.setName(rs.getString("name"));
				tv.setRole(rs.getString("role"));
				tv.setEmail(rs.getString("email"));
				tv.setDob(rs.getDate("dob"));
				tv.setAddress(rs.getString("address"));
				tv.setPhone(rs.getString("phone"));

				System.out.println(tv.toString());
				status = true;
			}
			ps.close();

		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
			System.out.println("SQLException: " + e.getMessage());
		}
		return status;
	}
}
