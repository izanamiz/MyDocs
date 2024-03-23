package Server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class Server {
	public int countRoom = 0;
	public static ArrayList<ArrayList<HandleThread>> roomList = new ArrayList<ArrayList<HandleThread>>();

	ServerSocket serverSocket;

	public void go() {
		try {
			serverSocket = new ServerSocket(9999);

			int countThreadBeat = 0;
			roomList.add(new ArrayList<HandleThread>());

			while (true) {
				Socket socket = serverSocket.accept();
				countThreadBeat++;

				if (countThreadBeat > 4) {
					countThreadBeat = 1;
					countRoom++;
					roomList.add(new ArrayList<HandleThread>());
				}

				HandleThread handleThread = new HandleThread(socket, countRoom);
				roomList.get(countRoom).add(handleThread);
				handleThread.start();
			}

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	// private long countdownTimer = 0;
	// private boolean gameStarted = false;
	// public int countRoom = 0;
	// public static ArrayList<ArrayList<HandleThread>> roomList = new ArrayList<ArrayList<HandleThread>>();

	// ServerSocket serverSocket;

	// public void go() {
	// 	try {
	// 		serverSocket = new ServerSocket(9999);
	// 		int countThreadBeat = 0;
	// 		roomList.add(new ArrayList<HandleThread>());
	// 		startTimer();
	// 		while (true) {
	// 			Socket socket = serverSocket.accept();
	// 			countThreadBeat++;

	// 			if (countThreadBeat > 4) {
	// 				countThreadBeat = 1;
	// 				countRoom++;
	// 				roomList.add(new ArrayList<HandleThread>());
	// 			}

	// 			HandleThread handleThread = new HandleThread(socket, countRoom);
	// 			roomList.get(countRoom).add(handleThread);
	// 			handleThread.start();

	// 			// Check and start countdown when a player joins
	// 			checkAndStartCountdown();
	// 		}
	// 	} catch (IOException e) {
	// 		e.printStackTrace();
	// 	}
	// }
	// private void checkCountdown() {
	// 	if (countdownTimer > 0) {
	// 		countdownTimer--;
	// 		if (countdownTimer == 0) {
	// 			startGameIfEnoughPlayers();
	// 		}
	// 	}
	// }
	// private void startGameIfEnoughPlayers() {
	// 	if (getTotalPlayers() >= 2 && !gameStarted) {
	// 		System.out.println("Game started!");
	// 		gameStarted = true;
	// 	}
	// }
	// private int getTotalPlayers() {
	// 	int totalPlayers = 0;
	// 	for (ArrayList<HandleThread> room : roomList) {
	// 		totalPlayers += room.size();
	// 	}
	// 	return totalPlayers;
	// }
	// private void resetTimer() {
	// 	countdownTimer = 10; // Set your countdown time in seconds
	// }
	// private void startTimer() {
	// 	new Thread(() -> {
	// 		while (true) {
	// 			try {
	// 				Thread.sleep(1000);
	// 				checkCountdown();
	// 			} catch (InterruptedException e) {
	// 				e.printStackTrace();
	// 			}
	// 		}
	// 	}).start();
	// }
	// public void playerJoined() {
	// 	resetTimer();
	// }
	// // New method to check and start countdown when a player joins
	// private void checkAndStartCountdown() {
	// 	int totalPlayers = getTotalPlayers();

	// 	if (totalPlayers == 1 || totalPlayers == 2 || totalPlayers == 3) {
	// 		// Start countdown if the room has 1, 2, or 3 players
	// 		resetTimer();
	// 	} else if (totalPlayers == 4) {
	// 		// If the room has 4 players, start the game immediately
	// 		startGameIfEnoughPlayers();
	// 	}
	// }
	
	public static void main(String[] args) {
		Server server = new Server();
		server.go();
	}
}
