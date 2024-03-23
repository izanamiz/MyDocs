package model;

public class TaiLieuPhieuMuon075 {
	private TaiLieu075 doc;
	private PhieuMuon075 receipt;

	public TaiLieuPhieuMuon075() {

	}

	public TaiLieuPhieuMuon075(TaiLieu075 doc, PhieuMuon075 receipt) {
		this.doc = doc;
		this.receipt = receipt;
	}

	public TaiLieu075 getDoc() {
		return doc;
	}

	public void setDoc(TaiLieu075 doc) {
		this.doc = doc;
	}

	public PhieuMuon075 getReceipt() {
		return receipt;
	}

	public void setReceipt(PhieuMuon075 receipt) {
		this.receipt = receipt;
	}
	
}
