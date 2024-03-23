/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import org.junit.Assert;
import org.junit.Test;
import java.sql.Connection;
import java.sql.SQLException;
import java.text.ParseException;
import java.util.ArrayList;
import model.Client;

/**
 *
 * @author ngahn
 */
public class ClientDAOTest {

    ClientDAO cd = new ClientDAO();
    Connection con = DAO.con;

    @Test
    public void testSearchAccountException() {
        String name = "Dao Ngoc Anh";
        String phone = "028409324";
        String DOB = "26/06/2001";
        ArrayList<Client> lst = cd.SearchAccount(name, DOB, phone);
        Assert.assertNotNull(lst);
        Assert.assertEquals(0, lst.size());
    }

    @Test
    public void testSearchAccountStandard() {
        String name = "Dao Ngoc Anh";
        String phone = "034883206";
        String DOB = "26/06/2001";
        ArrayList<Client> lst = cd.SearchAccount(name, DOB, phone);
        Assert.assertNotNull(lst);
        Assert.assertEquals(1, lst.size());
        Assert.assertEquals(lst.get(0).getName(), "Dao Ngoc Anh");
        Assert.assertEquals(lst.get(0).getMemberpoint(), 20);
    }

    @Test
    public void testAddAccount1() {
        String newname = "Dao Hoang Anh";
        String newDOB = "02/01/1994";
        String newPhone = "0293480223";
        try {
            Client client = new Client(newname, newDOB, newPhone);
            con.setAutoCommit(false);
            cd.AddAccount(client);
            ArrayList<Client> lst = cd.SearchAccount(newname, newDOB, newPhone);
            Assert.assertNotNull(lst);
            Assert.assertEquals(1, lst.size());
            Assert.assertEquals(lst.get(0).getId(), "C005");
            Assert.assertEquals(lst.get(0).getName(), "Dao Hoang Anh");
            Assert.assertEquals(lst.get(0).getMemberpoint(), 0);
            Assert.assertTrue(lst.get(0).getRank().equals("Adult"));
        } catch (ParseException e) {
            e.printStackTrace();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                con.rollback();
                con.setAutoCommit(true);
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    @Test
    public void testAddAccount2() {
        String newname = "Dao Hoang Anh";
        String newDOB = "02/01/2007";
        String newPhone = "0293480223";
        try {
            Client client = new Client(newname, newDOB, newPhone);
            con.setAutoCommit(false);
            cd.AddAccount(client);
            ArrayList<Client> lst = cd.SearchAccount(newname, newDOB, newPhone);
            Assert.assertNotNull(lst);
            Assert.assertEquals(1, lst.size());
            Assert.assertEquals(lst.get(0).getId(), "C005");
            Assert.assertEquals(lst.get(0).getName(), "Dao Hoang Anh");
            Assert.assertEquals(lst.get(0).getMemberpoint(), 0);
            Assert.assertTrue(lst.get(0).getRank().equals( "U22"));
        } catch (ParseException e) {
            e.printStackTrace();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                con.rollback();
                con.setAutoCommit(true);
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
