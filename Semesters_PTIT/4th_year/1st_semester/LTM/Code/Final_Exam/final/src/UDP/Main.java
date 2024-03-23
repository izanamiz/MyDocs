package UDP;

import java.io.*;
import java.net.*;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        String msv = "";
        String host = "";
        int port = 2207;
        InetAddress IPAddress = InetAddress.getByName(host);

        DatagramSocket client = new DatagramSocket();

        client.send(new DatagramPacket(msv.getBytes(), msv.length(), IPAddress, port));

        byte[] receiveBuff = new byte[1024];
        DatagramPacket dp = new DatagramPacket(receiveBuff, receiveBuff.length);
        client.receive(dp);

        ByteArrayInputStream bis = new ByteArrayInputStream(dp.getData());
        ObjectInputStream ois = new ObjectInputStream(bis);

        Student933 st1 = (Student933) ois.readObject();

        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(bos);

        oos.writeObject(st1);
        byte[] sendBuff = bos.toByteArray();
        client.send(new DatagramPacket(sendBuff, sendBuff.length, IPAddress, port));


        client.close();
    }
}
