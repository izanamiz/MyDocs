/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import java.io.Serializable;

/**
 *
 * @author ngahn
 */
public class Seat implements Serializable{
    private String id;
    private boolean isAvailable;
    private double price;
    private CinemaRoom room;

    public Seat() {
        super();
    }

    public Seat(String id, boolean isAvailable, double price, CinemaRoom room) {
        super();
        this.id = id;
        this.isAvailable = isAvailable;
        this.price = price;
        this.room = room;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public boolean isIsAvailable() {
        return isAvailable;
    }

    public void setIsAvailable(boolean isAvailable) {
        this.isAvailable = isAvailable;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public CinemaRoom getRoom() {
        return room;
    }

    public void setRoom(CinemaRoom room) {
        this.room = room;
    }
    
    public Object[] toObject() {
        return new Object[]{
            id, price, isAvailable
        };
    }
}
