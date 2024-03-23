package Server;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

import DataPacket.AnnouncementFirstBeginRound;
import DataPacket.DataPacket;
import DataPacket.DeclareWinner;
import DataPacket.DestroyFirstBeginRound;
import DataPacket.RegistrationAccountName;
import DataPacket.RequestAccept;
import DataPacket.RequestEndTurn;
import DataPacket.RequestRedo;
import DataPacket.RequestSendFileData;
import DataPacket.RequestSendMessenger;
import DataPacket.RequestTheFirstBeginRound;
import DataPacket.ResponseAccept;
import DataPacket.ResponseCardOnTable;
import DataPacket.ResponseClientTurn;
import DataPacket.ResponseDeckShuffled;
import DataPacket.ResponseIdRoom;
import DataPacket.ResponseRedo;
import DataPacket.ResponseSendMessenger;
import DataPacket.ResponseTheFirstBeginRound;
import DataPacket.ResponseWinner;
import ModelCard.Card;
import ModelCard.CardFactory;

public class HandleThread extends Thread {

	public int idRoom;

	public ArrayList<HandleThread> handleThreadList;

	public String accountName;
	public Socket socket;

	public ObjectInputStream objectInputStream;
	public ObjectOutputStream objectOutputStream;

	public String whoIsFristBeginRound;
	public int intIndexOfWhoIsFirstBeginRound;

	public String numberOne;
	public String numberTwo;
	public String numberThree;
	public String numberFour;
	private int acceptCount = 0;
	private boolean isAccept;
	private String accountRequestRedo;

	public void setObjectOutputStream(ObjectOutputStream objectOutputStream) {
		this.objectOutputStream = objectOutputStream;
	}

	public ObjectOutputStream getObjectOutputStream() {
		return objectOutputStream;
	}

	@Override
	public void run() {
		super.run();

		handleThreadList = Server.roomList.get(idRoom);
		int numPlayers = handleThreadList.size();
		System.out.println("hiện tại phòng này đang có số người là: " + numPlayers);

		// gửi số phòng về client.
		ResponseIdRoom responseIdRoom = new ResponseIdRoom(idRoom);
		DataPacket providerIdRoom = (DataPacket) responseIdRoom;
		doWrite(providerIdRoom);

		while (true) {
			doRead();
		}
	}

	public HandleThread(Socket socket, int idRoom) {
		this.socket = socket;
		this.idRoom = idRoom;

		try {
			objectInputStream = new ObjectInputStream(socket.getInputStream());
			objectOutputStream = new ObjectOutputStream(socket.getOutputStream());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public synchronized void doRead() {
		try {
			DataPacket dataPacket = (DataPacket) objectInputStream.readObject();

			String tag = dataPacket.getTag();

			switch (tag) {
			case "registrationAccountName":
				RegistrationAccountName registrationAccountName = (RegistrationAccountName) dataPacket;

				accountName = registrationAccountName.getAccountName();
				System.out.println("nguoi dung thu: " + accountName);

				if (handleThreadList.size() == 4) {

					for (int i = 0; i < handleThreadList.size(); i++) {
						System.out.println("client ten la: " + handleThreadList.get(i).accountName);
					}
					System.out.println("full slot 4 player, game begin");

					// tạo index cho 52 lá bài
					ArrayList<Integer> deck = new ArrayList<Integer>();
					for (int i = 0; i < 52; i++) {
						deck.add(i);
					}

					// xao bai
					Collections.shuffle(deck);
					System.out.println("index bo bai 52 la, sau khi xao bai");
					System.out.println(deck);

					for (int i = 0; i < handleThreadList.size(); i++) {

						ArrayList<String> nameOfAnotherPlayer = new ArrayList<String>();
						for (int j = 0; j < handleThreadList.size(); j++) {
							if (!handleThreadList.get(j).accountName.equals(handleThreadList.get(i).accountName)) {
								nameOfAnotherPlayer.add(handleThreadList.get(j).accountName);
							}
						}

						ArrayList<Integer> deckShuffled = new ArrayList<Integer>();
						for (int x = 0; x < 13; x++) {
							// lấy ra 13 lá sau khi xáo bài
							deckShuffled.add(deck.get(x));

						}

						System.out.println("13 la bai cho client so " + (i + 1) + " do la:");
						System.out.println(deckShuffled);

						for (int y = 0; y < 13; y++) {
							// xóa những lá đã lấy ra khỏi bộ bài
							deck.remove(deckShuffled.get(y));
						}

						System.out.println("nhung la bai con lai trong deck la:");
						System.out.println(deck);

						// gửi những 13 lá bài đến 4 client và set thứ tự đánh cho các client trong ván
						// game
						ResponseDeckShuffled responseDeckShuffled = null;
						ResponseTheFirstBeginRound responseTheFirstBeginRound = null;
						if (i == 0) {

							whoIsFristBeginRound = handleThreadList.get(0).accountName;
							// client đầu tiên trong danh sách sẽ là người có lượt đầu tiên và là người bắt
							// đầu round đầu tiên
							responseDeckShuffled = new ResponseDeckShuffled(deckShuffled, nameOfAnotherPlayer, true,
									true);
							// đã tích hợp nội dung isFristBeginRound vào gói tin ở trên
						} else {

							responseDeckShuffled = new ResponseDeckShuffled(deckShuffled, nameOfAnotherPlayer, false,
									false);
							// đã tích hợp nội dung isFristBeginRound vào gói tin ở trên
						}

						DataPacket dataPacket2 = (DataPacket) responseDeckShuffled;

						if (accountName == handleThreadList.get(i).accountName) {
							// gửi chính client của thread này

							doWrite(dataPacket2);
							System.out.println("da gui den: " + handleThreadList.get(i).accountName);

						} else {
							// gửi đến 3 client còn lại
							Socket socket2 = handleThreadList.get(i).socket;

							handleThreadList.get(i).doWrite(dataPacket2);

							System.out.println("da gui den: " + handleThreadList.get(i).accountName);
						}

					}

				}
				break;

			case "RequestEndTurn":
				// thực thi chuyển turn cho các client
				RequestEndTurn requestEndTurn = (RequestEndTurn) dataPacket;

				// kiểm tra có kèm deckShuffled (list bài mà client này gửi cho các client khác)
				if (requestEndTurn.getDispatchDeck() == null || requestEndTurn.getDispatchDeck().size() == 0) {
					// nếu không có, có nghĩa là client này bỏ qua lượt
					System.out.println("client " + accountName + " bo luot");

					// lấy ra tên của client muốn bỏ qua lượt này
					String thisClientWantEndTurn = requestEndTurn.getClientWantEndTurn();

					// ResponseClientTurn responseClientTurn = new ResponseClientTurn(isYourTurn);

					for (int i = 0; i < handleThreadList.size(); i++) {
						if (thisClientWantEndTurn == handleThreadList.get(i).accountName) {
							// bỏ qua element này, client này đã tự đánh dấu thuộc isYourTurn của chính
							// client là false

							ResponseClientTurn responseClientTurn = new ResponseClientTurn(true);
							DataPacket dataPacket3 = (DataPacket) responseClientTurn;
							if (i == (handleThreadList.size() - 1)) {
								handleThreadList.get(0).doWrite(dataPacket3);
							} else {
								handleThreadList.get(i + 1).doWrite(dataPacket3);
							}

							break;
						}
					}
				} else {
					System.out.println("client " + accountName + " danh cac la bai co index sau:");
					System.out.println(requestEndTurn.getDispatchDeck());
					// nếu gói tin này có đi kèm thông số về các lá bài mà client chọn đánh
					// thì gửi những thông số lá bài đó đến các client còn lại
					// không cần phải lo lắng về tính hợp lệ của các lá bài đó, bởi vì
					// tính hợp lệ của những lá bài đó đã được client kiểm tra trước khi gửi đến
					// server

					// lấy ra tên của client đã đánh bài ở lượt này
					String thisClientWantGoToEndTurn = requestEndTurn.getClientWantEndTurn();

					// để nhường lượt cho client kế tiếp
					for (int i = 0; i < handleThreadList.size(); i++) {
						if (thisClientWantGoToEndTurn == handleThreadList.get(i).accountName) {
							// bỏ qua element này, client này đã tự đánh dấu thuộc isYourTurn của chính
							// client là false

							ResponseClientTurn responseClientTurn = new ResponseClientTurn(true);
							DataPacket dataPacket3 = (DataPacket) responseClientTurn;
							if (i == (handleThreadList.size() - 1)) {
								handleThreadList.get(0).doWrite(dataPacket3);
							} else {
								handleThreadList.get(i + 1).doWrite(dataPacket3);
							}

							break;
						}
					}

					ResponseCardOnTable responseCardOnTable = new ResponseCardOnTable(requestEndTurn.getDispatchDeck(),
							thisClientWantGoToEndTurn);
					DataPacket dataPacket4 = (DataPacket) responseCardOnTable;

					int count = 0;
					// gửi cho tất cả client còn lại về thông số những lá bài mà client này chọn để
					// đánh lên
					for (int i = 0; i < handleThreadList.size(); i++) {
						if (handleThreadList.get(i).accountName != thisClientWantGoToEndTurn) {
							handleThreadList.get(i).doWrite(dataPacket4);
							count++;
						}
					}
					System.out.println(count);
				}

				break;

			case "RequestTheFirstBeginRound":
				// thực thi chuyển quyền firstBeginRound giữa các client
				RequestTheFirstBeginRound requestTheFirstBeginRound = (RequestTheFirstBeginRound) dataPacket;

				String clientSentThisRequest = requestTheFirstBeginRound.getAccountName();

				for (int i = 0; i < handleThreadList.size(); i++) {
					if (clientSentThisRequest == handleThreadList.get(i).accountName) {
						// bỏ qua element này, client này đã tự đánh dấu thuộc isFirstBeginRound của
						// chính client là false

						ResponseTheFirstBeginRound responseTheFirstBeginRound = new ResponseTheFirstBeginRound(true);
						DataPacket dataPacket5 = (DataPacket) responseTheFirstBeginRound;
						if (i == (handleThreadList.size() - 1)) {
							handleThreadList.get(0).doWrite(dataPacket5);
						} else {
							handleThreadList.get(i + 1).doWrite(dataPacket5);
						}
						break;
					}

				}

				break;
			case "AnnouncementFirstBeginRound":
				// gói này có nhiệm vụ truyên bố client mà đã yêu cầu chức này, chính là client
				// đang "phù hợp"
				// để trở thành một FirstBeginRound
				AnnouncementFirstBeginRound announcementFirstBeginRound = (AnnouncementFirstBeginRound) dataPacket;
				whoIsFristBeginRound = announcementFirstBeginRound.getAccountName();
				for (int i = 0; i < handleThreadList.size(); i++) {
					if (handleThreadList.get(i).accountName != whoIsFristBeginRound) {
						// thông báo đến các thread khác rằng nay đã có whoIsFristBeginRoung mới
						handleThreadList.get(i).whoIsFristBeginRound = whoIsFristBeginRound;

						// yêu cầu những client khác với client tại vị, yêu cầu hủy tư cách
						// FristBeginRound
						DestroyFirstBeginRound destroyFirstBeginRound = new DestroyFirstBeginRound();
						DataPacket dataPacket6 = (DataPacket) destroyFirstBeginRound;

						handleThreadList.get(i).doWrite(dataPacket6);

					}
				}

				for (int i = 0; i < handleThreadList.size(); i++) {
					System.out.println("FristBeginRound of Client " + handleThreadList.get(i).accountName + "is "
							+ handleThreadList.get(i).whoIsFristBeginRound);
				}

				break;

			case "RequestSendMessenger":
				// thực hiện nhận một tin nhắn từ client nào đó, và gửi đến những client còn lại
				RequestSendMessenger requestSendMessenger = (RequestSendMessenger) dataPacket;

				String whoSendThisMessenger = requestSendMessenger.getAccountName();

				ResponseSendMessenger responseSendMessenger = new ResponseSendMessenger(whoSendThisMessenger,
						requestSendMessenger.getContentMessenger());

				for (int i = 0; i < handleThreadList.size(); i++) {
					if (!whoSendThisMessenger.equals(handleThreadList.get(i).accountName)) {
						DataPacket dataPacket10 = (DataPacket) responseSendMessenger;
						handleThreadList.get(i).doWrite(dataPacket10);
					}
				}

				break;

			case "DeclareWinner":
				DeclareWinner declareWinner = (DeclareWinner) dataPacket;

				String whoDeclareWinner = declareWinner.getAccountName();

				if (numberOne.isEmpty()) {
					numberOne = whoDeclareWinner;
					ResponseWinner responseWinner = new ResponseWinner(numberOne, null, null, null);
					DataPacket dataPacketResponseWinner = (DataPacket) responseWinner;
					doWrite(dataPacketResponseWinner);

				} else if (numberTwo.isEmpty() && numberOne.isEmpty() == false) {
					numberTwo = whoDeclareWinner;
					ResponseWinner responseWinner = new ResponseWinner(numberOne, numberTwo, null, null);
					DataPacket dataPacketResponseWinner = (DataPacket) responseWinner;
					doWrite(dataPacketResponseWinner);
				} else if (numberThree.isEmpty() && numberTwo.isEmpty() == false) {
					numberThree = whoDeclareWinner;
					ResponseWinner responseWinner = new ResponseWinner(numberOne, numberTwo, numberThree, null);
					DataPacket dataPacketResponseWinner = (DataPacket) responseWinner;
					doWrite(dataPacketResponseWinner);
				} else if (numberFour.isEmpty() && numberThree.isEmpty() == false) {
					numberFour = whoDeclareWinner;
					ResponseWinner responseWinner = new ResponseWinner(numberOne, numberTwo, numberThree, numberFour);
					DataPacket dataPacketResponseWinner = (DataPacket) responseWinner;
					doWrite(dataPacketResponseWinner);
				}

				break;

			case "RequestSendFileData":
				RequestSendFileData requestSendFileData = (RequestSendFileData) dataPacket;
				File file = new File("D:\\Downloads\\" + requestSendFileData.getFile().getName());
				byte[] content = requestSendFileData.getContent();
				doWrite(content, file);
				break;

			// choi lai
			case "RequestRedo":
				// nhận yêu cầu chơi lại từ 1 client và gửi đến các client khác
				RequestRedo requestRedo = (RequestRedo) dataPacket;
				String accountName = requestRedo.getAccountName();
				System.out.println("Server nhan yeu cau di lai cua nguoi choi");

				this.acceptCount = 0;
				this.accountRequestRedo = accountName;
				ResponseRedo responseRedo = new ResponseRedo(accountName);
				for (int i = 0; i < handleThreadList.size(); i++) {
					if (!accountName.equals(handleThreadList.get(i).accountName)) {
						DataPacket dataPacket10 = (DataPacket) responseRedo;
						handleThreadList.get(i).doWrite(dataPacket10);
						System.out.println("Gui yeu cau di lai den nguoi choi con lai");
					}
				}

				break;

			case "RequestAccept":
				// Nhận phản hồi của các client khác về việc có dc đi lại ko
				RequestAccept requestAccept = (RequestAccept) dataPacket;
				String accountNameAccept = "";

				boolean isAccepted = requestAccept.isAccept();
				if (isAccepted)
					this.acceptCount = 1;

				int countAccept = 0;

				for (int i = 0; i < handleThreadList.size(); i++) {
					if (handleThreadList.get(i).acceptCount != 0) {
						countAccept++;
					} else {
						accountNameAccept = handleThreadList.get(i).accountName;
					}

				}
				for (int i = 0; i < handleThreadList.size(); i++) {
					if (handleThreadList.get(i).acceptCount == 0) {
						accountNameAccept = handleThreadList.get(i).accountName;
						break;
					}

				}

				System.out.println("So nguoi chap nhận là : " + countAccept);
				System.out.println("Người muốn đi lại: " + accountNameAccept);
				if (countAccept == 3) {
					for (int i = 0; i < handleThreadList.size(); i++) {
						// set turn cho client yêu cầu đi lại
						if (handleThreadList.get(i).accountName == accountNameAccept) {
							ResponseClientTurn responseClientTurn = new ResponseClientTurn(true);
							DataPacket dataPacket3 = (DataPacket) responseClientTurn;
							handleThreadList.get(i).doWrite(dataPacket3);
							ResponseClientTurn responseClientTurn1 = new ResponseClientTurn(false);
							DataPacket dataPacket4 = (DataPacket) responseClientTurn1;
							handleThreadList.get(i+1).doWrite(dataPacket4);
							break;
						}
					}
				}

				break;

			}
		} catch (ClassNotFoundException | IOException e) {
			e.printStackTrace();
		}
	}

	public void doWrite(DataPacket dataPacket) {
		try {
			objectOutputStream.writeObject(dataPacket);
			objectOutputStream.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	FileOutputStream fos;

	public void doWrite(byte[] content, File file) {
		try {
			System.out.println(file.getAbsolutePath());
			fos = new FileOutputStream(file);
			fos.write(content);
			fos.flush();
			fos.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void sendDeckShuffledTo(ArrayList<Integer> deckShuffled) {
		try {
			objectOutputStream.writeObject(deckShuffled);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public int getIntIndexFromStringIndex(String accountname) {
		for (int i = 0; i < handleThreadList.size(); i++) {
			if (accountname == handleThreadList.get(i).accountName) {
				return i;
			}
		}

		return -1;
	}

}
