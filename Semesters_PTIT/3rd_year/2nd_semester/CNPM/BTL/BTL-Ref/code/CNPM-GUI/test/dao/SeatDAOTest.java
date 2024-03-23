/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.sql.Connection;
import java.sql.SQLException;
import java.util.ArrayList;
import model.Seat;
import model.Ticket;
import org.junit.Assert;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author ngahn
 */
public class SeatDAOTest {

    SeatDAO sd = new SeatDAO();
    Connection con = DAO.con;

    public SeatDAOTest() {
    }

    @Test
    public void testShowSeats1() {
        String roomid = "R01";
        ArrayList<Seat> seats = sd.showSeats(roomid);
        for (Seat s : seats) {
            Assert.assertTrue(s.getRoom().getId().equals(roomid));
        }
    }

    @Test
    public void testShowSeats2() {
        String roomid = "R02";
        ArrayList<Seat> seats = sd.showSeats(roomid);
        for (Seat s : seats) {
            Assert.assertTrue(s.getRoom().getId().equals(roomid));
        }
    }

    @Test
    public void testShowSeatsException() {
        String roomid = "R05";
        ArrayList<Seat> seats = sd.showSeats(roomid);
        Assert.assertNotNull(seats);
        Assert.assertEquals(0, seats.size());
    }

    @Test
    public void testChooseSeat() {
        String roomid = "R03";
        ArrayList<Seat> seats = sd.showSeats(roomid);
        Assert.assertTrue(seats.size() > 0);
        Ticket ticket = sd.ChooseSeat(seats.get(0));
        Assert.assertNotNull(ticket);
        Assert.assertEquals(ticket.getId(), "T004");
    }

}
