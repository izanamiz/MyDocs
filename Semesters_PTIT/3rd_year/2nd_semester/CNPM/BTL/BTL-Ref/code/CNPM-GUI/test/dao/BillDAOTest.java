/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.sql.Connection;
import java.sql.SQLException;
import java.util.ArrayList;
import model.Bill;
import model.Client;
import model.Seat;
import model.Showtime;
import model.Ticket;
import model.UsedMemberpoint;
import model.User;
import org.junit.Assert;
import org.junit.Test;

/**
 *
 * @author ngahn
 */
public class BillDAOTest {

    UserDAO ud = new UserDAO();
    BillDAO bd = new BillDAO();
    ClientDAO cd = new ClientDAO();
    SeatDAO sd = new SeatDAO();
    ShowtimeDAO std = new ShowtimeDAO();
    Connection con = DAO.con;

    @Test
    public void testSave1() {
        User user = new User();
        user.setUsername("bookingclerk");
        user.setPassword("bookingclerk");
        Assert.assertTrue(ud.checkLogin(user));
        String roomid = "R03";
        ArrayList<Seat> seats = sd.showSeats(roomid);
        Showtime showtime = std.SearchByCinemaRoom("3D").get(0);
        ArrayList<Ticket> tickets = new ArrayList<>();
        tickets.add(sd.ChooseSeat(seats.get(1)));
        tickets.get(0).setShowtime(showtime);
        tickets.get(0).setSeat(seats.get(1));
        String name = "Dao Ngoc Anh";
        String phone = "034883206";
        String DOB = "26/06/2001";
        Client client = cd.SearchAccount(name, DOB, phone).get(0);
        int[] option = new int[2];
        option[0] = 0;
        option[1] = 0;
        UsedMemberpoint used = new UsedMemberpoint(0, option, client);
        Bill bill = new Bill();
        bill.setUser(user);
        try {
            con.setAutoCommit(false);
            bd.Save(bill, client, tickets, used);
            Assert.assertTrue(bill.getId().equals("B004"));
            Assert.assertEquals(client.getMemberpoint(), 20);
            Assert.assertTrue(used.getId().equals("P003"));
            Assert.assertTrue(tickets.get(0).getBill().getId().equals(bill.getId()));
            Assert.assertFalse(tickets.get(0).getSeat().isIsAvailable());
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                con.rollback();
                con.setAutoCommit(true);
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

}
