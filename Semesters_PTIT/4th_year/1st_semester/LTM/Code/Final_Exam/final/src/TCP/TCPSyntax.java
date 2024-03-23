package TCP;

import java.io.*;
import java.net.Socket;

public class TCPSyntax {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        String host = "";
        int port = 2207;

        Socket socket = new Socket(host, port);

        // DataInputStream/DataOutputStream
        // Hỗ trợ read/write kiểu dữ liệu nguyên thuỷ

        DataInputStream dis = new DataInputStream(socket.getInputStream());
        DataOutputStream dos = new DataOutputStream(socket.getOutputStream());


        String sendData1 = "";
        dos.writeUTF(sendData1);

        int receive1 = dis.readInt();
        int res1 = 0;
        dos.writeInt(res1);


        // BufferReader/BufferWriter
        // Hỗ trợ read/write kiểu dữ liệu nguyên thuỷ
        BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));

        String sendData2 = "";
        bw.write(sendData2);

        //  bw.flush giúp xoá bộ nhớ đệm để đẩy dữ liệu đi (bw.write) ngay cả khi chưa đủ kích thước của bộ đệm
        bw.newLine();
        bw.flush();

        String receive2 = br.readLine();
        String res2 = "";
        bw.write(res2);

        bw.flush();

        // InputStream/OutputStream
        // Không hỗ trợ kiểu dữ liệu nguyên thuỷ, chỉ làm việc với kiểu dữ liệu byte
        InputStream is = new DataInputStream(socket.getInputStream());
        OutputStream os = new DataOutputStream(socket.getOutputStream());

        String sendData3 = "";

        os.write(sendData3.getBytes());

        byte[] buff = new byte[1024];
        is.read(buff);
        String receive3 = new String(buff);

        String res3 = "";
        os.write(res3.getBytes());

        // ObjectInputStream/ObjectOutputStream

        ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
        ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());

        // dùng writeObject
        String sendData4 = "";
        oos.writeObject(sendData4);

        // nhớ ép kiểu
        Student st = (Student) ois.readObject();
        oos.writeObject(st);
        ois.close();
        oos.close();

        //
        socket.close();
    }
}
