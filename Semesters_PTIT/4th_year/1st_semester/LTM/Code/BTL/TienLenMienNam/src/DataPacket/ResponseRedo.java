package DataPacket;

import java.io.Serializable;

public class ResponseRedo extends DataPacket implements Serializable {

	// gói này để server gửi về client yeeu caauf di lai
	public static String tag = "ResponseRedo";
	public String accountName;

	public ResponseRedo(String accountName) {
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