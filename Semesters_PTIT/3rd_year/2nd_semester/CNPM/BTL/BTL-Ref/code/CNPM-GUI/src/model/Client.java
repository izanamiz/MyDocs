/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import dao.ClientDAO;
import java.io.Serializable;
import java.sql.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author ngahn
 */
public class Client implements Serializable {

    private String id;
    private String name;
    private String DOB;
    private String phone;
    private String rank;
    private int memberpoint;

    public Client() {
        super();
    }

    public Client(String name, String DOB, String phone) throws ParseException {
        super();
        this.id = "";
        this.name = name;
        this.DOB = DOB;
        this.phone = phone;
        this.rank = "Adult";
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        java.util.Date dob;
        dob = formatter.parse(DOB);
        if (2022 - (dob.getYear()+1900) <= 22) {
            this.rank = "U22";
        }
        this.memberpoint = 0;
    }

    public Client(String id, String name, String DOB, String phone, String rank, int memberpoint) {
        super();
        this.id = id;
        this.name = name;
        this.DOB = DOB;
        this.phone = phone;
        this.rank = rank;
        this.memberpoint = memberpoint;
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

    public String getDOB() {
        return DOB;
    }

    public void setDOB(String DOB) {
        this.DOB = DOB;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public String getRank() {
        return rank;
    }

    public void setRank(String rank) {
        this.rank = rank;
    }

    public int getMemberpoint() {
        return memberpoint;
    }

    public void setMemberpoint(int memberpoint) {
        this.memberpoint = memberpoint;
    }

    public Object[] toObject() {
        return new Object[]{id, name, DOB, phone, rank, memberpoint
        };
    }
}
