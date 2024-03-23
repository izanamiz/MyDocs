/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.util.ArrayList;
import model.Seat;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import model.CinemaRoom;
import model.Ticket;

/**
 *
 * @author ngahn
 */
public class SeatDAO extends DAO {

    public SeatDAO() {
        super();
    }

    public ArrayList<Seat> showSeats(String CinemaRoomID) {
        ArrayList<Seat> lst = new ArrayList<>();
        String sql = "SELECT * FROM tblSeat WHERE CinemaRoomID like ?";
        try {
            PreparedStatement ps = con.prepareStatement(sql);
            ps.setString(1, "%" + CinemaRoomID + "%");
            ResultSet res = ps.executeQuery();
            while (res.next()) {
                Seat s = new Seat();
                s.setId(res.getString("id"));
                s.setPrice(res.getDouble("price"));
                if (res.getInt("isavailable") == 1) {
                    s.setIsAvailable(true);
                } else {
                    s.setIsAvailable(false);
                }
                CinemaRoom room = new CinemaRoom();
                room.setId(CinemaRoomID);
                s.setRoom(room);
                lst.add(s);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return lst;
    }

    public Ticket ChooseSeat(Seat seat) {
        //create new ticket
        Ticket ticket = new Ticket();
        int count = 0;
        String sql = "SELECT * FROM tblTicket";
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
        String id = "T" + String.format("%0" + 3 + "d", count);
        ticket.setId(id);
        return ticket;
    }
}
