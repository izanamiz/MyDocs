package Client;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TimerExample extends JFrame {
	private static TimerExample instance;
	private JLabel timerLabel;
	private Timer timer;

	private TimerExample(ClientGameplay clientGameplay) {
		setTitle("Countdown Timer");
		setSize(300, 200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		timerLabel = new JLabel("Time remaining: 20 seconds", SwingConstants.CENTER);
		timerLabel.setFont(new Font("Arial", Font.BOLD, 16));
		add(timerLabel, BorderLayout.CENTER);

		initializeTimer(20, clientGameplay);
	}

	private void initializeTimer(int seconds, ClientGameplay clientGameplay) {
		if (timer != null) {
			timer.stop();
		}

		timer = new Timer(1000, new ActionListener() {
			int secondsRemaining = seconds;

			@Override
			public void actionPerformed(ActionEvent e) {
				secondsRemaining--;
				if (secondsRemaining >= 0) {
					timerLabel.setText("Time remaining: " + secondsRemaining + " seconds");
				} else {
					((Timer) e.getSource()).stop();
					dispose();
					// Thêm các hành động sau khi đếm ngược kết thúc ở đây
					clientGameplay.autoPlay();
				}
			}
		});

		timer.start();
	}

	public void closeFrame() {
		dispose();
	}

	public static void closeExistingFrame() {
		for (Frame frame : Frame.getFrames()) {
			if (frame instanceof TimerExample) {
				((TimerExample) frame).closeFrame();
			}
		}
	}

	public static void openFrame(ClientGameplay clientGameplay) {
		instance = new TimerExample(clientGameplay);
		instance.setVisible(true);
	}

}
