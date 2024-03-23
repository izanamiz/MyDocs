package model;

public class TaiLieu075 {
	private int id;
	private String name;
	private String author;
	private String category;
	private String desc;
	private String img;
	private int numBorrows;

	public TaiLieu075() {
		super();
	}

	public TaiLieu075(int id, String name, String author, String category, String desc, String img) {
		super();
		this.id = id;
		this.name = name;
		this.author = author;
		this.category = category;
		this.desc = desc;
		this.img = img;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getAuthor() {
		return author;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public String getCategory() {
		return category;
	}

	public void setCategory(String category) {
		this.category = category;
	}

	public String getDesc() {
		return desc;
	}

	public void setDesc(String desc) {
		this.desc = desc;
	}

	public String getImg() {
		return img;
	}

	public void setImg(String img) {
		this.img = img;
	}

	public int getNumBorrows() {
		return numBorrows;
	}

	public void setNumBorrows(int numBorrows) {
		this.numBorrows = numBorrows;
	}

	
}
