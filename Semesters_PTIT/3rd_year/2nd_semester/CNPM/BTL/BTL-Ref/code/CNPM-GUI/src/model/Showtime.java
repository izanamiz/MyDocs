/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import java.io.Serializable;
import java.sql.Timestamp;

/**
 *
 * @author ngahn
 */
public class Showtime implements Serializable {

    private String id;
    private Timestamp start;
    private double price;
    private Movie movie;
    private CinemaRoom room;

    public Showtime() {
        super();
    }

    public Showtime(String id, Timestamp start, double price, Movie movie, CinemaRoom room) {
        super();
        this.id = id;
        this.start = start;
        this.price = price;
        this.movie = movie;
        this.room = room;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public Timestamp getStart() {
        return start;
    }

    public void setStart(Timestamp start) {
        this.start = start;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public Movie getMovie() {
        return movie;
    }

    public void setMovie(Movie movie) {
        this.movie = movie;
    }

    public CinemaRoom getRoom() {
        return room;
    }

    public void setRoom(CinemaRoom room) {
        this.room = room;
    }

    public Object[] toObject() {
        return new Object[]{
            id, movie.getName(),  movie.getRuntime(), start, movie.getType(), room.getType()
        };
    }
}
