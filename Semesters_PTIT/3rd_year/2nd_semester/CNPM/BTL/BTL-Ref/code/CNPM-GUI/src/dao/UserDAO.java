/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import model.User;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

/**
 *
 * @author ngahn
 */
public class UserDAO extends DAO {

    public UserDAO() {
        super();
    }

    public boolean checkLogin(User user) {
        boolean r = false;
        String sql = "SELECT * FROM tblUser WHERE username = ? AND password = ?";
        try {
            PreparedStatement ps = con.prepareStatement(sql);
            ps.setString(1, user.getUsername());
            ps.setString(2, user.getPassword());
            ResultSet res = ps.executeQuery();
            if (res.next()) {
                user.setId(res.getString("ID"));
                user.setRole(res.getString("role"));
                r = true;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return r;
    }
}
