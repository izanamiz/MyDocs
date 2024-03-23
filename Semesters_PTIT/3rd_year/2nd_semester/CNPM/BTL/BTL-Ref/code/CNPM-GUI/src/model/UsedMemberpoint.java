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
public class UsedMemberpoint implements Serializable {

    private String id;
    private int amount;
    private int[] exchangeoption;
    private Client client;
    private Bill bill;

    public UsedMemberpoint() {
        super();
    }

    public UsedMemberpoint(int amount, int[] exchangeoption, Client client) {
        this.id = "";
        this.amount = amount;
        this.exchangeoption = exchangeoption;
        this.client = client;
        this.bill = null;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public int getAmount() {
        return amount;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }

    public int[] getExchangeoption() {
        return exchangeoption;
    }

    public void setExchangeoption(int[] exchangeoption) {
        this.exchangeoption = exchangeoption;
    }

    public Client getClient() {
        return client;
    }

    public void setClient(Client client) {
        this.client = client;
    }

    public Bill getBill() {
        return bill;
    }

    public void setBill(Bill bill) {
        this.bill = bill;
    }

}
