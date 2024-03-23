package UDP;

import java.io.*;
import java.net.*;

public class UDPSyntax {
    public static void main(String[] args) throws IOException, ClassNotFoundException {

        String msv = "";
        String host = "";
        int port = 2207;
        InetAddress IPAddress = InetAddress.getByName("");

        DatagramSocket client = new DatagramSocket();

        // Data
        client.send(new DatagramPacket(msv.getBytes(), msv.length(), IPAddress, port));

        byte[] buff = new byte[1024];
        DatagramPacket dp = new DatagramPacket(buff, buff.length);
        client.receive(dp);

        String receive = new String(dp.getData());

        String res = "";
        client.send(new DatagramPacket(res.getBytes(), res.length(), IPAddress, port));

        // Object

        // Chuyển đổi đối tượng thành mảng byte rồi gửi đi
        Customer cus = new Customer();

        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(bos);
        oos.writeObject(cus);
        byte[] sendBuf = bos.toByteArray();
        client.send(new DatagramPacket(sendBuf, sendBuf.length, IPAddress, port));

        // Nhận dữ liệu
        byte[] receiveBuf = new byte[1024];
        DatagramPacket packet = new DatagramPacket(receiveBuf, receiveBuf.length);
        client.receive(packet);

        ByteArrayInputStream bis = new ByteArrayInputStream(packet.getData());
        ObjectInputStream ois = new ObjectInputStream(bis);
        Customer kh = (Customer) ois.readObject();

        bos = new ByteArrayOutputStream();
        oos = new ObjectOutputStream(bos);
        oos.writeObject(kh);
        sendBuf = bos.toByteArray();
        client.send(new DatagramPacket(sendBuf, sendBuf.length, IPAddress, port));

        //
        client.close();
    }
}