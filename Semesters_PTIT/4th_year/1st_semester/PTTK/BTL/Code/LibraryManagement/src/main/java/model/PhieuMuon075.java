package model;

public class PhieuMuon075 extends TheBanDoc075 {
	private int id;
	private String date;

	public PhieuMuon075(String date) {
		super();
		this.date = date;
	}

	public PhieuMuon075() {
		super();
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getDate() {
		return date;
	}

	public void setDate(String date) {
		this.date = date;
	}

	public int getCardID() {
		return super.getId();
	}

	public void setCardID(int cardID) {
		super.setId(cardID);
	}
}
