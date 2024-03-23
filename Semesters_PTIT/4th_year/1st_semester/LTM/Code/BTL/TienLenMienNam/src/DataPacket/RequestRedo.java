package DataPacket;

import java.io.Serializable;

public class RequestRedo extends DataPacket implements Serializable {
	private String accountName; // Người chơi yêu cầu đi lại
	public static String tag = "RequestRedo";

	public RequestRedo() {
		super(tag);
	}

	public RequestRedo(String accountName) {
		super(tag);
		this.accountName = accountName;
	}

	public String getAccountName() {
		return accountName;
	}

	public void setAccountName(String accountName) {
		this.accountName = accountName;
	}
}
