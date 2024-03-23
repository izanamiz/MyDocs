package model;

public class TheBanDoc075 extends BanDoc075 {
	private int id;

	public TheBanDoc075() {
		super();
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public int getReaderID() {
		return super.getId();
	}

	public void setReaderID(int readerID) {
		super.setId(readerID);
	}

	public String toString() {
		return "readerID " + getReaderID() + " ";
	}
}