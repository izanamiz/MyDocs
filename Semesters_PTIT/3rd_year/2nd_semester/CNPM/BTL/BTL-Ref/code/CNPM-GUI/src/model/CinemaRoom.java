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
public class CinemaRoom implements Serializable {

    private String id;
    private String type;
    private Cinema cinema;

    public CinemaRoom() {
        super();
    }
    public CinemaRoom(String id, String type, Cinema cinema) {
        super();
        this.id = id;
        this.type = type;
        this.cinema = cinema;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public Cinema getCinema() {
        return cinema;
    }

    public void setCinema(Cinema cinema) {
        this.cinema = cinema;
    }

    

    
}
