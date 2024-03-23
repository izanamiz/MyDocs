CREATE TABLE `libman`.`tblbandoc` (
	`id` INT NOT NULL,
	FOREIGN KEY (`id`) REFERENCES libman.tblthanhvien(id)
  );
  
  CREATE TABLE `libman`.`tblnhanvien` (
	`id` INT NOT NULL,
    `position` VARCHAR(45),
	FOREIGN KEY (`id`) REFERENCES libman.tblthanhvien(id)
  );
  
CREATE TABLE `libman`.`tblthebandoc` (
	`id` INT NOT NULL AUTO_INCREMENT,
	`readerID` INT NOT NULL,
	PRIMARY KEY (`id`),
	FOREIGN KEY (`readerID`) REFERENCES libman.tblthanhvien(id)
  );
  


CREATE TABLE `libman`.`tbltailieu` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NOT NULL,
  `author` VARCHAR(45) NOT NULL,
  `category` VARCHAR(45) NOT NULL,
  `desc` VARCHAR(255) NULL,
  `img` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`id`)
  );
  
CREATE TABLE `libman`.`tblphieumuon` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `date` DATE NOT NULL,
  `cardID` INT NOT NULL,
  PRIMARY KEY (`id`),
  FOREIGN KEY (`cardID`) REFERENCES libman.tblthebandoc(id)
  );

CREATE TABLE `libman`.`tbltailieuphieumuon` (
	`id` INT NOT NULL AUTO_INCREMENT,
	`docID` INT NOT NULL,
	`receiptID` INT NOT NULL,
	PRIMARY KEY (`id`),
    FOREIGN KEY (`docID`) REFERENCES libman.tbltailieu(id),
    FOREIGN KEY (`receiptID`) REFERENCES libman.tblphieumuon(id)
    );
  
SELECT t.*, COUNT(p.id) AS numBorrows
FROM libman.tbltailieu AS t
LEFT JOIN libman.tbltailieuphieumuon AS tp ON t.id = tp.docID
LEFT JOIN libman.tblphieumuon AS p ON tp.receiptID = p.id
WHERE p.date BETWEEN '2023-11-02' AND '2023-11-05'
GROUP BY t.id, t.name, t.author, t.category
ORDER BY numBorrows DESC;

SELECT t.id, t.name, p.id AS pID, p.date, r.id as cardID, v.name as readerName
FROM libman.tbltailieu AS t
LEFT JOIN libman.tbltailieuphieumuon AS tp ON t.id = tp.docID
LEFT JOIN libman.tblphieumuon AS p ON tp.receiptID = p.id
LEFT JOIN libman.tblthebandoc AS r ON p.cardID = r.id
LEFT JOIN libman.tblthanhvien AS v ON v.id = r.readerID
WHERE t.id = 2 AND p.date BETWEEN '2023-11-02' AND '2023-11-05';

SELECT t.id, t.name, t.author, p.id AS pID, p.date, p.id AS cardID, v.name AS readerName
FROM libman.tbltailieu AS t
LEFT JOIN libman.tbltailieuphieumuon AS tp ON t.id = tp.docID
LEFT JOIN libman.tblphieumuon AS p ON tp.receiptID = p.id
LEFT JOIN libman.tblthebandoc AS r ON p.cardID = r.id
LEFT JOIN libman.tblthanhvien AS v ON v.id = r.readerID
WHERE p.id = 2;

INSERT INTO libman.tblthebandoc (readerID) VALUES (1);

INSERT INTO `libman`.`tbltailieu` (`id`, `name`, `author`, `category`, `desc`, `img`) VALUES ('1', 'Đồi gió hú', 'Emily Bronte', 'Tiểu thuyết', '\"Đồi gió hú là tiểu thuyết duy nhất của Emily Brontë, người đã chết ngay sau khi tác phẩm được xuất bản, ở tuổi ba mươi. Một câu chuyện u sầu vùng Yorrkshire về một mối tình mạnh hơn cả cái chết, cũng là một cái nhìn dữ dội về dục vọng siêu hình mà theo đó, cả thiên đường, địa ngục, thiên nhiên và xã hội cùng gắn bó mãnh liệt. Độc nhất, huyền bí, với một văn phong phi thời, tiểu thuyết đã trở thành tác phẩm kinh điển của văn học Anh.”', 'https://cdn0.fahasa.com/media/catalog/product/d/i/dinh_gio_hu_bia_cung_1_2020_05_27_15_12_47.jpg');
INSERT INTO `libman`.`tbltailieu` (`id`, `name`, `author`, `category`, `desc`, `img`) VALUES ('2', 'Nhà giả kim', 'Paulo Coelho', 'Tiểu thuyết', 'Nhà giả kim (tựa gốc tiếng Bồ Đào Nha: O Alquimista) là tiểu thuyết được xuất bản lần đầu ở Brasil năm 1988, và là cuốn sách nổi tiếng nhất của nhà văn Paulo Coelho. Tác phẩm đã được dịch ra 67 ngôn ngữ và bán ra tới 95 triệu bản (theo thống kê ngày 19 tháng 5 năm 2008), trở thành một trong những cuốn sách bán chạy nhất mọi thời đại', 'https://cdn0.fahasa.com/media/catalog/product/n/h/nha-gia-kim-b.jpg');
INSERT INTO `libman`.`tbltailieu` (`id`, `name`, `author`, `category`, `desc`, `img`) VALUES ('3', 'Cây cam ngọt của tôi', 'José Mauro de Vasconcelos', 'Tiểu thuyết', '“Vị chua chát của cái nghèo hòa trộn với vị ngọt ngào khi khám phá ra những điều khiến cuộc đời này đáng số một tác phẩm kinh điển của Brazil.”', 'http://static.nhanam.com.vn/thumb/0x320/crop/Books/Images/2020/12/7/ZO8WK5R7.jpg');
INSERT INTO `libman`.`tbltailieu` (`id`, `name`, `author`, `category`, `desc`, `img`) VALUES ('4', 'Doraemon - Chú Mèo Máy Đến Từ Tương Lai', 'Fujiko F. Fujio', 'Truyện tranh', 'Doraemon (tiếng Nhật: ドラえもん [doɾaemoɴ]) là một series manga của Nhật Bản do Fujiko F. Fujio và đồng tác giả Motoo Abiko sáng tác từ tháng 12 năm 1969 đến tháng 4 năm 1996 đăng trên tạp chí CoroCoro Comic của nhà xuất bản Shogakukan.', 'https://salt.tikicdn.com/media/catalog/product/t/a/tap-20.jpg');
INSERT INTO `libman`.`tbltailieu` (`id`, `name`, `author`, `category`, `desc`, `img`) VALUES ('5', 'Sherlock Holmes ', ' Arthur Conan Doyle', 'Trinh thám', 'Sherlock Holmes (/ˈʃɜːlɒk ˈhoʊmz/) là một nhân vật thám tử tư hư cấu, do nhà văn người Anh Arthur Conan Doyle sáng tạo nên. Tự coi mình là \"thám tử tư vấn\" trong các câu chuyện, Holmes nổi danh với khả năng quan sát, diễn dịch, khoa học pháp y điêu luyện và suy luận logic tuyệt vời, những yếu tố mà anh áp dụng khi điều tra các vụ án của nhiều dạng khách hàng, bao gồm cả Scotland Yard.', 'https://www.khaitam.com/Data/Sites/1/Product/1190/sherlock-holmes-tap-1.jpg');

  