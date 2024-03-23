package dao;

import java.sql.Connection;
import java.sql.DriverManager;

public class BaseDAO075 {
	public static Connection connection;

	public BaseDAO075() {
		if (connection == null) {
			String dbUrl = "jdbc:mysql://localhost:3306/libman?autoReconnect=true&useSSL=false";
			String dbClass = "com.mysql.cj.jdbc.Driver";
			try {
				Class.forName(dbClass);
				connection = DriverManager.getConnection(dbUrl, "root", "888888");
				System.out.println("Connect successfully!");
			} catch (Exception e) {
				e.printStackTrace();
				System.out.println("SQLException: " + e.getMessage());
			}
		}
	}
}
