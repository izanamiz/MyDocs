package udp;

import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Arrays;
import java.util.List;

public class UDP {

    public static String address = "10.21.135.64";
    public static int port = 2208;

    private static void send(DatagramSocket socket, String request) throws IOException {
        InetAddress address = InetAddress.getByName(UDP.address);
        byte[] buffer = request.getBytes();
        socket.send(new java.net.DatagramPacket(buffer, buffer.length, address, port));
    }

    private static String receive(DatagramSocket socket) throws IOException {
        byte[] buffer = new byte[1024];
        java.net.DatagramPacket packet = new java.net.DatagramPacket(buffer, buffer.length);
        socket.receive(packet);
        return new String(packet.getData());
    }

    // Viết hoa chữ cái đầu tiên tất cả các từ trong câu
    /*public static void main(String[] args) throws IOException {
        String request = ";B20DCCN535;932";
        DatagramSocket socket = new DatagramSocket();

        send(socket, request);
        String resp = receive(socket);
        String requestId = resp.split(";")[0];
        String data = resp.split(";")[1];
        data = String.join(",", Arrays.stream(data.split("\\s")).map(it -> it.substring(0, 1).toUpperCase() + it.substring(1).toLowerCase()).toList());
        send(socket, requestId + ";" + data);
        socket.close();
    }*/

    // Mã hoá caesar
    /*public static void main(String[] args) throws IOException {
        String request = ";B20DCCN535;934";
        DatagramSocket socket = new DatagramSocket();

        send(socket, request);
        String resp = receive(socket);
        String requestId = resp.split(";")[0];
        String strEncode = resp.split(";")[1];
        String s = resp.split(";")[2];

        // caesar decrypting, with s is offset int
        int offset = Integer.parseInt(s);
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < strEncode.length(); i++) {
            char c = strEncode.charAt(i);
            if (Character.isUpperCase(c)) {
                result.append((char) ('A' + (c - 'A' + offset) % 26));
            } else {
                result.append((char) ('a' + (c - 'a' + offset) % 26));
            }
        }
        send(socket, requestId + ";" + result.toString());
        socket.close();
    }*/

    // Loại bỏ chữ cái xuất hiện trong chuỗi sau
    /*public static void main(String[] args) throws IOException {
        String request = ";B20DCCN535;936";
        DatagramSocket socket = new DatagramSocket();

        send(socket, request);
        String resp = receive(socket);
        String str1 = resp.split(";")[0];
        String str2 = resp.split(";")[1];
        for (String c : str2.split("")) {
            str1 = str1.replace(c, "");
        }
        send(socket, str1);
        socket.close();
    }*/

    // phải dùng class
    /*public static class Product937 implements Serializable {
        private static final long serialVersionUID = 937L;
        public String id;
        public String code;
        public String name;
        public int quantity;

        public Product937(String id, String code, String name, int quantity) {
            this.id = id;
            this.code = code;
            this.name = name;
            this.quantity = quantity;
        }
    }

    public static void main(String[] args) throws IOException {
        String request = ";B20DCCN535;937";
        DatagramSocket socket = new DatagramSocket();

        send(socket, request);
        DatagramPacket packet = new DatagramPacket(new byte[1024], 1024);
        socket.receive(packet);
        ByteArrayInputStream bais = new ByteArrayInputStream(packet.getData());
        ObjectInputStream ois = new ObjectInputStream(bais);
        UDP.Product937 product = null;
        try {
            product = (UDP.Product937) ois.readObject();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        assert product != null;
        String quantity = String.valueOf(product.quantity);
        String reversed = new StringBuilder(quantity).reverse().toString();
        product.quantity = Integer.parseInt(reversed);
        List<String> names = Arrays.stream(product.name.split(" ")).toList();
        String tmp = names.get(0);
        names.set(0, names.get(names.size() - 1));
        names.set(names.size() - 1, tmp);
        product.name = String.join(" ", names);
//        ByteArrayOutputStream baos = new ByteArrayOutputStream();
//        ObjectOutputStream oos = new ObjectOutputStream(baos);
//        oos.writeObject(product);
//        oos.flush();
//        byte[] buffer = baos.toByteArray();
//        socket.send(new DatagramPacket(buffer, buffer.length, packet.getAddress(), packet.getPort()));
        socket.close();
    }*/
}
