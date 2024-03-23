/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.sql.Connection;
import java.util.ArrayList;
import model.Showtime;
import org.junit.Assert;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author ngahn
 */
public class ShowtimeDAOTest {

    ShowtimeDAO std = new ShowtimeDAO();
    Connection con = DAO.con;

    @Test
    public void testSearchByMovieName() {
        String movie = "Kingsman";
        ArrayList<Showtime> showtimes = std.SearchByMovieName(movie);
        for (Showtime st : showtimes) {
            Assert.assertTrue(st.getMovie().getName().toLowerCase().contains(movie.toLowerCase()));
        }
              
    }

    @Test
    public void testSearchByCinemaRoom() {
        String room = "VIP";
        ArrayList<Showtime> showtimes = std.SearchByCinemaRoom(room);
        for (Showtime st : showtimes) {
            Assert.assertTrue(st.getRoom().getType().toLowerCase().contains(room.toLowerCase()));
        }
    }

}
