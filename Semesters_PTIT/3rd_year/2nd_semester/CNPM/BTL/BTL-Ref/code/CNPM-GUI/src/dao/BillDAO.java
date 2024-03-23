/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import static dao.DAO.con;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.time.LocalDate;
import java.time.ZoneId;
import java.util.ArrayList;
import model.Bill;
import model.Client;
import model.Ticket;
import model.UsedMemberpoint;

/**
 *
 * @author ngahn
 */
public class BillDAO extends DAO {

    public BillDAO() {
        super();
    }
    
    public void Save(Bill bill, Client client, ArrayList<Ticket> tickets, UsedMemberpoint used) {
        Timestamp timestamp = new Timestamp(System.currentTimeMillis());
        bill.setTime(timestamp);
        for (Ticket ticket : tickets) {
            ticket.setBill(bill);
        }
        int count = 0;
        String sql = "SELECT * FROM tblBill";
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
        String bid = "B" + String.format("%0" + 3 + "d", count);
        bill.setId(bid);
        // add to tblBill
        sql = "INSERT INTO tblBill(ID, time, UserID) VALUES (?, ?, ?)";
        try {
            PreparedStatement ps = con.prepareStatement(sql);
            ps.setString(1, bill.getId());
            ps.setTimestamp(2, bill.getTime());
            ps.setString(3, bill.getUser().getId());
            ps.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        // update poitns
        count = 0;
        sql = "SELECT * FROM tblUsedMemberpoint";
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
        String id = "P" + String.format("%0" + 3 + "d", count);
        used.setId(id);
        int[] options = used.getExchangeoption();
        used.setAmount(25 * options[0] + 30 * options[1]);
        client.setMemberpoint(client.getMemberpoint() - used.getAmount());
        used.setBill(bill);

        for (Ticket ticket : tickets) {
            // add to tblTicket
            sql = "INSERT INTO tblTicket(ID, BillID, SeatID, ShowtimeID) VALUES (?, ?, ?, ?)";
            try {
                PreparedStatement ps = con.prepareStatement(sql);
                ps.setString(1, ticket.getId());
                ps.setString(2, bill.getId());
                ps.setString(3, ticket.getSeat().getId());
                ps.setString(4, ticket.getShowtime().getId());
                ps.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
            // update seats' status
            ticket.getSeat().setIsAvailable(false);
            sql = "UPDATE tblSeat SET isAvailable = ? WHERE tblSeat.ID = ?";
            try {
                PreparedStatement ps = con.prepareStatement(sql);
                ps.setInt(1, 0);
                ps.setString(2, ticket.getSeat().getId());
                ps.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        //update client's points
        sql = "UPDATE tblclient SET memberpoint = ? WHERE tblClient.ID = ?";
        try {
            PreparedStatement ps = con.prepareStatement(sql);
            double total = 0;
            for (Ticket ticket : tickets) {
                total += ticket.getCost();
            }
            int points = (int) (total / 30000);
            if (client.getRank().equals("U22")) {
                points += (int) points / 10;
            }
            points += client.getMemberpoint();
            ps.setDouble(1, points);
            ps.setString(2, client.getId());
            ps.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        // add to tblUsedMemberpoint
        sql = "INSERT INTO tblUsedMemberpoint(ID, amount, exchangeoption, ClientID, BillID) VALUES (?, ?, ?, ?, ?)";
        try {
            PreparedStatement ps = con.prepareStatement(sql);
            ps.setString(1, used.getId());
            ps.setInt(2, used.getAmount());
            String option = String.valueOf(options[0]) + " ve 2D " + String.valueOf(options[1]) + " ve 3D";
            ps.setString(3, option);
            ps.setString(4, used.getClient().getId());
            ps.setString(5, used.getBill().getId());
            ps.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
