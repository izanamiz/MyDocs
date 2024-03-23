/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import model.Bill;
import model.Client;
import model.UsedMemberpoint;

/**
 *
 * @author ngahn
 */
public class ClientDAO extends DAO {

    public ClientDAO() {
        super();
    }

    public ArrayList<Client> SearchAccount(String name, String dob, String phone) {
        ArrayList<Client> lst = new ArrayList<>();
        String sql = "SELECT * FROM tblClient WHERE name = ? AND dob = ? AND phone = ?";
        try {
            PreparedStatement ps = con.prepareStatement(sql);
            ps.setString(1, name);
            ps.setString(2, dob);
            ps.setString(3, phone);
            ResultSet res = ps.executeQuery();
            while (res.next()) {
                Client c = new Client();
                c.setId(res.getString("id"));
                c.setName(res.getString("name"));
                c.setDOB(res.getString("dob"));
                c.setPhone(res.getString("phone"));
                c.setMemberpoint(res.getInt("memberpoint"));
                c.setRank(res.getString("rank"));
                lst.add(c);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return lst;
    }

    public void AddAccount(Client client) {
        int count = 0;
        String sql = "SELECT * FROM tblClient";
        try {
            PreparedStatement ps = con.prepareStatement(sql);
            ResultSet res = ps.executeQuery();
            while (res.next()) {
                ++count;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        count += 1;
        String id = "C" + String.format("%0" + 3 + "d", count);
        client.setId(id);

        sql = "INSERT INTO tblClient(ID, name, DOB, phone, rank, memberpoint) VALUES (?, ?, ?, ?, ?, ?)";
        try {
            PreparedStatement ps = con.prepareStatement(sql);
            ps.setString(1, client.getId());
            ps.setString(2, client.getName());
            ps.setString(3, client.getDOB());
            ps.setString(4, client.getPhone());
            ps.setString(5, client.getRank());
            ps.setInt(6, client.getMemberpoint());
            ps.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
