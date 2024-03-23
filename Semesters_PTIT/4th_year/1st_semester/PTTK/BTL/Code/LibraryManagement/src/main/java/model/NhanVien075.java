package model;

import java.util.Date;

public class NhanVien075 extends ThanhVien075 {
	private String position;

	public NhanVien075() {
		super();
		// TODO Auto-generated constructor stub
	}

	public NhanVien075(int id, String name, String username, String password, String email, String role, Date dob,
			String address, String phone) {
		super(id, name, username, password, email, role, dob, address, phone);
		// TODO Auto-generated constructor stub
	}

	public NhanVien075(String position) {
		super();
		this.position = position;
	}

	public String getPosition() {
		return position;
	}

	public void setPosition(String position) {
		this.position = position;
	}
}
