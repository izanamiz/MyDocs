package DataPacket;

import java.io.Serializable;

public class ResponseAccept extends DataPacket implements Serializable {

	// gói này để server gửi về da dong y di lai
	public static String tag = "ResponseAccept";
	public String accountName;

	public ResponseAccept(String accountName) {
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