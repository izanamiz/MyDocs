package DataPacket;

import java.io.Serializable;

public class RequestAccept extends DataPacket implements Serializable {
	private String accountName; // Người chơi chap nhan yeu cau di lai
	private boolean isAccept;
	public static String tag = "RequestAccept";

	public RequestAccept() {
		super(tag);
	}

	public RequestAccept(String accountName, boolean isAccept) {
		super(tag);
		this.accountName = accountName;
		this.isAccept = isAccept;
	}

	public String getAccountName() {
		return accountName;
	}

	public void setAccountName(String accountName) {
		this.accountName = accountName;
	}

	public boolean isAccept() {
		return isAccept;
	}

	public void setAccept(boolean isAccept) {
		this.isAccept = isAccept;
	}
	
}
