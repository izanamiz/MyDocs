package model;

import java.util.Date;

public class ThanhVien075 {
	private int id;
	private String name;
	private String username;
	private String password;
	private String email;
	private String role;
	private Date dob;
	private String address;
	private String phone;

	public ThanhVien075() {
		super();
	}

	public ThanhVien075(int id, String name, String username, String password, String email, String role, Date dob,
			String address, String phone) {
		super();
		this.id = id;
		this.name = name;
		this.username = username;
		this.password = password;
		this.email = email;
		this.role = role;
		this.dob = dob;
		this.address = address;
		this.phone = phone;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getRole() {
		return role;
	}

	public void setRole(String role) {
		this.role = role;
	}

	public Date getDob() {
		return dob;
	}

	public void setDob(Date dob) {
		this.dob = dob;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public String toString() {
		return this.name + " " + this.email + " " + this.dob + " " + this.address + " " + this.phone + " ";
	}
}
