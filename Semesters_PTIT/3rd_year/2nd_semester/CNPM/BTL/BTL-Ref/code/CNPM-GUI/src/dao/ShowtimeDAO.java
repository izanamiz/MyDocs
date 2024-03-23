/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.util.ArrayList;
import model.Showtime;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import model.Cinema;
import model.CinemaRoom;
import model.Movie;

/**
 *
 * @author ngahn
 */
public class ShowtimeDAO extends DAO {

    public ShowtimeDAO() {
        super();
    }

    public ArrayList<Showtime> SearchByMovieName(String key) {
        ArrayList<Showtime> lst = new ArrayList<Showtime>();
        String sql = "SELECT tblCinemaRoom.ID, tblShowtime.ID, tblMovie.Name, tblMovie.type, tblMovie.runtime, tblShowtime.start, tblCinemaRoom.type, tblShowtime.price FROM tblMovie, tblShowtime, tblCinemaRoom WHERE tblMovie.Name LIKE ? AND tblMovie.ID = tblShowtime.MovieID AND tblCinemaRoom.ID = tblShowtime.CinemaRoomID";
        try {
            PreparedStatement ps = con.prepareStatement(sql);
            ps.setString(1, "%" + key + "%");
            ResultSet res = ps.executeQuery();

            while (res.next()) {
                Showtime st = new Showtime();
                st.setId(res.getString("tblShowtime.ID"));
                st.setStart(res.getTimestamp("tblShowtime.start"));
                Movie m = new Movie();
                m.setName(res.getString("tblMovie.Name"));
                m.setRuntime(res.getInt("tblMovie.runtime"));
                m.setType(res.getString("tblMovie.type"));
                st.setMovie(m);
                CinemaRoom room = new CinemaRoom();
                room.setId(res.getString("tblCinemaRoom.id"));
                room.setType(res.getString("tblCinemaRoom.type"));
                st.setRoom(room);
                st.setPrice(res.getDouble("tblShowtime.price"));
                lst.add(st);

            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return lst;
    }

    public ArrayList<Showtime> SearchByCinemaRoom(String key) {
        ArrayList<Showtime> lst = new ArrayList<>();
        String sql = "SELECT tblCinemaRoom.ID, tblShowtime.ID, tblMovie.Name, tblMovie.type, tblMovie.runtime, tblShowtime.start, tblCinemaRoom.Type FROM tblMovie, tblShowtime, tblCinemaRoom WHERE tblCinemaRoom.Type LIKE ? AND tblMovie.ID = tblShowtime.MovieID AND tblCinemaRoom.ID = tblShowtime.CinemaRoomID";
        try {
            PreparedStatement ps = con.prepareStatement(sql);
            ps.setString(1, "%" + key + "%");
            ResultSet res = ps.executeQuery();

            while (res.next()) {
                Showtime st = new Showtime();
                st.setId(res.getString("tblShowtime.ID"));
                st.setStart(res.getTimestamp("tblShowtime.start"));
                Movie m = new Movie();
                m.setName(res.getString("tblMovie.Name"));
                m.setRuntime(res.getInt("tblMovie.runtime"));
                m.setType(res.getString("tblMovie.type"));
                st.setMovie(m);
                CinemaRoom room = new CinemaRoom();
                room.setId(res.getString("tblCinemaRoom.id"));
                room.setType(res.getString("tblCinemaRoom.type"));
                st.setRoom(room);
                lst.add(st);

            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return lst;
    }
}
