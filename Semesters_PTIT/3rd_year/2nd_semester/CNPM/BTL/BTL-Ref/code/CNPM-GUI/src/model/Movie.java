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
public class Movie implements Serializable {

    private String id;
    private String name;
    private String type;
    private int runtime;

    public Movie() {
        super();
    }

    public Movie(String id, String name, String type, int runtime) {
        super();
        this.id = id;
        this.name = name;
        this.type = type;
        this.runtime = runtime;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getRuntime() {
        return runtime;
    }

    public void setRuntime(int runtime) {
        this.runtime = runtime;
    }

    
}
