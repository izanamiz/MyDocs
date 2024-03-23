/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import java.io.Serializable;
import static java.lang.Double.max;

/**
 *
 * @author ngahn
 */
public class Ticket implements Serializable {

    private String id;
    private Bill bill;
    private Seat seat;
    private Showtime showtime;

    public Ticket() {
        super();
    }

    public Ticket(String id, Bill bill, Seat seat, Showtime showtime) {
        super();
        this.id = id;
        this.bill = bill;
        this.seat = seat;
        this.showtime = showtime;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public Bill getBill() {
        return bill;
    }

    public void setBill(Bill bill) {
        this.bill = bill;
    }

    public Seat getSeat() {
        return seat;
    }

    public void setSeat(Seat seat) {
        this.seat = seat;
    }

    public Showtime getShowtime() {
        return showtime;
    }

    public void setShowtime(Showtime showtime) {
        this.showtime = showtime;
    }

    public double getCost() {
        return seat.getPrice();
    }

}
