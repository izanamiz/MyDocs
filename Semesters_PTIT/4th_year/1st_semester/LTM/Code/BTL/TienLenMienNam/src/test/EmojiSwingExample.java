package test;

import javax.swing.*;
import java.awt.*;

public class EmojiSwingExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Emoji in Java Swing");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);
        frame.setLayout(new FlowLayout());

        // Sử dụng font hỗ trợ emoji
        Font emojiFont = new Font("Segoe UI Emoji", Font.PLAIN, 24);

        // Hiển thị emoji trong JLabel
        JLabel emojiLabel = new JLabel("\uD83D\uDE00"); // Unicode của emoji 😄
        emojiLabel.setFont(emojiFont);
        frame.add(emojiLabel);

        frame.setVisible(true);
    }
}
