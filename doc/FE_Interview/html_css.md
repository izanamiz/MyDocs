# HTML, CSS

- Html là chữ viết tắt của Hypertext Markup Language. Nó giúp người dùng tạo và cấu trúc các thành phần trang web hoặc ứng dụng, phân chia các đoạn văn, heading, links, blockquotes, v.v...
  - Văn bản thông thường chỉ đọc được chữ, hình ảnh
  - Khi xây dựng website thì website chính là siêu văn bản, có thể tương tác, play video, âm thanh
    => siêu văn bản
- Css là ngôn ngữ tạo phong cách cho trang web - Cascading Style Sheet Language. Nó dùng để tạo phong cách và định kiểu cho những yếu tố được viết dưới dạng ngôn ngữ đánh dấu, như là Html

- A. HTML

  - **1. Cấu trúc file Html**
  - **2. Thẻ Html thông dụng**
    - _2.1. h1-h6_
    - _2.2. p_
      - Html Display
      - br
      - hr
      - pre
    - _2.3. img_
    - _2.4. a_
    - _2.5. ul, li_
    - _2.6. table_
    - _2.7. input_
    - _2.8. button_
    - _2.9. div_
  - **3. Attribute trong Html**
  - **4. Sử dụng Css trong Html**
    - _4.1. Internal_
    - _4.2. External_
    - _4.3. Inline_
    - _4.4. Html Styles_
  - **5. Html Text Formatting**
  - **6. Block and Inline**
  - **7. Html Forms**
  - **8.HTTP Messages, HTTP Methos**

- B. Css
  - **1. Css Selectors**
    - _1.1. Id và Claas_
    -
  - **2. Độ ưu tiên trong Css**
    - _2.1. Internal, External_
    - _2.2. Inline - 1000_
    - _2.3. #id - 100_
    - _2.4. .class - 10_
    - _2.5. tag_ - 1
    - _2.6. Equal specificity_
    - _2.7. Universal selector and inherited - 0_
    - _2.8. !important_
  - **3. Đặt biến trong Css**
  - **4. Css Units**
    - _4.1. Absolute units (px, ...)_
    - _4.2. Relative units (%, rem, em, vw, vh, ...)_
  - **5. Css Padding**
  - **6. Css Border**
  - **7. Css Margin**
  - **8. Css Box-sizing**
  - **9. Css Background**
    - _9.1. Background-clip_
    - _9.2. Background-image_
    - _9.3. Background-size keywords_
    - _9.4. Background origin_
    - _9.5. Background position_
    - _9.6. Background shorthand_
  - **10. Css Functions**
  - **11. Css Pseudo**
    - _11.1. Pseudo classes_
    - _11.2. Pseudo elements_
  - **12. Css Position**
  - **13. Css Display**
    - _13.1. Flexbox_
  - **14. Css BEM**

## A. HTML

### 1. Cấu trúc file Html

- Đặt tên file là `index.html` do sau này khi đăng tải website lên trên hosting thì đa phần các hosting được cấu hình là mặc định tự động truy cập vào `file index`
  => thường dùng `file index` để code trang chủ website
- 1 văn bản html đơn giản

  ```html
  <!DOCTYPE html>
  <html>
    <head>
      <title>Page Title</title>
    </head>
    <body>
      <h1>My First Heading</h1>
      <p>My first paragraph.</p>
    </body>
  </html>
  ```

  - The `<!DOCTYPE html>` declaration defines that this document is an HTML5 document
  - The `<html>` element is the root element of an HTML page
  - The `<head>` element contains meta information about the HTML page
  - The `<title>` element specifies a title for the HTML page (which is shown in the browser's title bar or in the page's tab)
  - The `<body>` element defines the document's body, and is a container for all the visible contents, such as headings, paragraphs, images, hyperlinks, tables, lists, etc.
  - The `<h1>` element defines a large heading
  - The `<p>` element defines a paragraph

### 2. Thẻ Html thông dụng

#### 2.1. h1-h6

- ```html
  <h1>This is heading</h1>
  ```
- HTML headings are titles or subtitles that you want to display on a webpage.
  > Browsers automatically add some white space (a margin) before and after a heading.
- Search engines use the headings to index the structure and content of your web pages.
- Users often skim a page by its headings. It is important to use headings to show the document structure.

#### 2.2. p

- ```html
  <p>This is paragraph</p>
  ```
- The HTML `<p>` element defines a paragraph.
- A paragraph always starts on a new line, and browsers automatically add some white space (a margin) before and after a paragraph.

##### 2.2.1. Html Display

- You cannot be sure how HTML will be displayed.
- Large or small screens, and resized windows will create different results.
- With HTML, you cannot change the display by adding extra spaces or extra lines in your HTML code.
- The browser will automatically remove any extra spaces and lines when the page is displayed:

##### 2.2.2. `<br>`:

- The HTML `<br>` element defines a line break.
- Use `<br>` if you want a line break (a new line) without starting a new paragraph:
- <p>This is<br>a paragraph<br>with line breaks.</p>
- The `<br>` tag is an empty tag, which means that it has no end tag.

##### 2.2.3. `<hr>`:

- The `<hr>` tag defines a thematic break in an HTML page, and is most often displayed as a horizontal rule.
- <h1>This is heading 1</h1>
  <p>This is some text.</p>
  <hr>
- The `<hr>` tag is an empty tag, which means that it has no end tag.

##### 2.2.4. `<pre>`:

- The HTML `<pre>` element defines preformatted text.
- The text inside a `<pre>` element is displayed in a fixed-width font (usually Courier), and it preserves both spaces and line breaks:
- <pre>
  My Bonnie lies over the ocean.

My Bonnie lies over the sea.

My Bonnie lies over the ocean.

Oh, bring back my Bonnie to me.

  </pre>

> Summary:
> | Tag | Description |
> | ------- | ---------------------------------------- |
> | `<p>` | Defines a paragraph |
> | `<hr>` | Defines a thematic change in the content |
> | `<br>` | Inserts a single line break |
> | `<pre>` | Defines pre-formatted text |

#### 2.3. img

```html
<img src="" alt="" />
```

- src(source)
- alt(alternative): thuộc tính không bắt buộc, chỉ hiển thị khi ảnh bị lỗi/ lỗi mạng
- The <img> tag is used to embed an image in an HTML page. The src attribute specifies the path to the image to be displayed:
- There are two ways to specify the URL in the src attribute:

  - 1. Absolute URL - Links to an external image that is hosted on another website. Example: src="https://www.w3schools.com/images/img_girl.jpg".

  Notes: External images might be under copyright. If you do not get permission to use it, you may be in violation of copyright laws. In addition, you cannot control external images; it can suddenly be removed or changed.

  - 2. Relative URL - Links to an image that is hosted within the website. Here, the URL does not include the domain name. If the URL begins without a slash, it will be relative to the current page. Example: src="img_girl.jpg". If the URL begins with a slash, it will be relative to the domain. Example: src="/images/img_girl.jpg".

> Tip: It is almost always best to use relative URLs. They will not break if you change domain.

#### 2.4. a

```html
<a href=""></a>
```

- a(anchor: mỏ neo(nghĩa đen), liên kết)
- The `<a>` tag defines a hyperlink. The href attribute specifies the URL of the page the link goes to:

#### 2.5. ul, li

- ul, li(unorderd list, list item)
- ```html
  <ul>
    <li></li>
  </ul>
  ```

- <ul>
      <li>1. a</li>
      <li>2. b</li>
      <li>3. c</li>
      <li>4. d</li>
  </ul>

#### 2.6. table

- ```html
  <table>
    <thead>
      <th></th>
    </thead>
    <tbody>
      <tr>
        <td></td>
      </tr>
    </tbody>
  </table>
  ```
- <table>
    <thead>
      <th>STT</th>
      <th>Tên</th>
      <th>Địa chỉ</th>
    </thead>
    <tbody>
      <tr>
        <td>1</td>
        <td>Hải Phòng</td>
        <td>Vân Anh</td>
      </tr>
    </tbody>
  </table>

#### 2.7. input

- ```html
  <input type="text" />
  <input type="checkbox" />
  <input name="" type="radio" />
  ```

- <input type="text">
- <input type="checkbox">
- <input name="gender" type="radio" />
  <input name="gender" type="radio" />
  <input name="gender" type="radio" />

- type: text(default)

#### 2.8. button

- ```html
  <button>Submit</button>
  ```

- <button>Submit</button>

#### 2.9. div

- ```html
  <div><button>Submit</button></div>
  ```

- div: tạo khối bao quanh phần tử khác

### 3. Attribute trong Html

- All HTML elements can have attributes
- Attributes provide additional information about elements
- Attributes are always specified in the start tag
- Attributes usually come in name/value pairs like: name="value"
- `The title` Attribute

  - The title attribute defines some extra information about an element.

  - The value of the title attribute will be displayed as a tooltip(chú giải) when you mouse over the element:
  - ```html
    <p title="I'm a tooltip">This is a paragraph.</p>
    ```

- Summary:
  - All HTML elements can have attributes
  - The href attribute of `<a>` specifies the URL of the page the link goes to
  - The src attribute of `<img>` specifies the path to the image to be displayed
  - The width and height attributes of `<img>` provide size information for images
  - The alt attribute of `<img>` provides an alternate text for an image
  - The style attribute is used to add styles to an element, such as color, font, size, and more
  - The lang attribute of the `<html>` tag declares the language of the Web page
  - The title attribute defines some extra information about an element

### 4. Sử dụng Css trong Html

3 cách:

- Internal
- External
- Inline

#### 4.1. Internal

- An internal CSS is used to define a style for a single HTML page.

- Sử dụng 1 cặp thẻ `<style></style>` trong file html và viết css trong cặp thẻ style đó

```html
<style>
  h1 {
    color: red;
  }
</style>
```

#### 4.2. External

- An external style sheet is used to define the style for many HTML pages.
- Tạo 1 file css ở bên ngoài và sử dụng thẻ `<link />` để dẫn đến file css đó
- `style.css`

  ```css
  h1 {
    color: red;
  }
  ```

- `index.html`

  ```html
  <link rel="stylesheet" href="style.css" />
  ```

#### 4.3. Inline

- An inline CSS is used to apply a unique style to a single HTML element.
- Sử dụng attribute `style` trong thẻ mở của html và các thuộc tính css vào
- ```html
  <h1 style="color: red; font-size: 16px">Css in Html</h1>
  ```

#### 4.4. Html Styles

- Use the `style` attribute for styling HTML elements
- Use `background-color` for background color
- Use `color` for text colors
- Use `font-family` for text fonts
- Use `font-size` for text sizes
- Use `text-align` for text alignment(defines the horizontal text alignment for an HTML element)

### 5. Html Text Formatting

Formatting elements were designed to display special types of text:

| Tag        | Description                                                                    |
| ---------- | ------------------------------------------------------------------------------ |
| `<b>`      | Defines bold text                                                              |
| `<em>`     | Defines emphasized text                                                        |
| `<i>`      | Defines a part of text in an alternate voice or mood                           |
| `<small>`  | Defines smaller text                                                           |
| `<strong>` | Defines important text                                                         |
| `<sub>`    | Defines subscripted text                                                       |
| `<sup>`    | Defines superscripted text                                                     |
| `<ins>`    | Defines inserted text. Browsers will usually underline inserted text           |
| `<del>`    | Defines deleted text. Browsers will usually strike a line through deleted text |
| `<mark>`   | Defines marked/highlighted text                                                |

### 6. Block and Inline

- There are two display values: block and inline
- A block-level element always starts on a new line and takes up the full width available
- An inline element does not start on a new line and it only takes up as much width as necessary
- The <div> element is a block-level and is often used as a container for other HTML elements
- The <span> element is an inline container used to mark up a part of a text, or a part of a document
  > An inline element cannot contain a block-level element!

#### 7. Html Forms

#### 8.HTTP Messages, HTTP Methos

## B. Css

### 1. Css Selectors

#### 1.1. Id và Class

- Chỉ có 1 id
  - The id attribute is used by CSS and JavaScript to style/select a specific element
- Có nhiều classes
  - HTML elements can belong to more than one class.
  - Different HTML elements can point to the same class name.
  - Classes are used by CSS and JavaScript to select and access specific elements

### 2. Độ ưu tiên trong Css

#### 2.1. Internal, External

- Không có sự ưu tiên giữa internal và external mà khác nhau ở cách gọi ra để sử dụng, cái nào được gọi sau(mới hơn) thì sẽ được ưu tiên

#### 2.2. Inline - 1000

#### 2.3. #id - 100

#### 2.4. .class - 10

#### 2.5. tag - 1

#### 2.6. Equal specificity

- Hiểu đơn giản là gọi tới cùng 1 selector
- Cái nào mới hơn sẽ được ưu tiên hơn

#### 2.7. Universal selector and inherited - 0

- Universal - 0
  ```css
  * {
    color: red;
  }
  li {
    color: black;
  }
  ```
  - `li{color: black}` được ưu tiên hơn
- Inherited - 0
  ```css
  html {
    color: violet;
  }
  li {
    color: red;
  }
  ```
  - Tất cả thẻ con của html được thừa hưởng thuộc tính của thẻ cha
  - `li{color: black}` được ưu tiên hơn

> - tag#id.class > #id.class > #id _(111 > 110 > 100)_
> - ghi đè

#### 2.8. !important

### 3. Đặt biến trong Css

- Biến toàn cục

  ```css
  :root {
    --text-color: red;
  }
  h1 {
    color: var(--text-color);
  }
  h2 {
    color: var(--text-color);
  }
  ```

- Biến cục bộ

  ```css
  :root {
    --text-color: red;
  }
  h1 {
    --my-color: green;
    color: var(--my-color);
  }
  h2 {
    color: var(--text-color);
  }
  ```

### 4. Đơn vị trong Css

#### 4.1. Absolute units (px, pt, cm, mm, inch, pc)

- px:
  - 1px ~ 1 điểm ảnh trên màn hình (màn hình phân giải thấp)
  - 1px ~ nhiểu điểm ảnh trên màn hình (màn hình phân giải cao)
  - Ví dụ
    ```css
    .box {
      width: 100px;
      height: 100px;
      background-color: red;
    }
    ```
  - Đặc tính của giá trị tuyệt đối này là kích thước sẽ không đổi khi các yếu tố xung quanh tác động lên nó thay đổi

#### 4.2. Relative units (%, rem, em, vw, vh, vmin, vmax, ex, ch)

- Kích thước không cố định, thay đổi khi kích thước cái nó phụ thuộc thay đổi
- %: Phụ thuộc vào thẻ chứa nó
- rem: Phụ thuộc vào font-size của thẻ html
- em: Phụ thuộc thẻ cha gần nhất có thuộc tính font-size
  > Thường sử dụng rem để dễ kiểm soát. Thực tế thường để `font-size: 100%` (nghĩa là 100px)
- vw, vh (viewport-width, height)
  - viewport-width: hiểu là độ rộng của trình duyệt
  - 100vw: 100% chiều ngang của trình duyệt

### 5. Css Padding

- ```css
  div {
    padding: 25px 50px 75px 100px;
  }
  ```

- Shorhand

  - all four paddings: top, right, bottom, left

  ```css
  .div {
    padding: 10px;
  }
  ```

  - top, right and left, bottom
    ```css
    div {
      padding: 25px 50px 75px;
    }
    ```
  - top and bottom, right and left
    ```css
    div {
      padding: 25px 50px;
    }
    ```

### 6. Css Border

- Shorthand
  - border-width
  - border-style (required)
  - border-color
  - ```css
    p {
      border: 5px solid red;
    }
    ```

### 7. Css Margin

- Shorthand: Tương tự padding

> Margin -> Border -> Padding

### 8. Css Box-sizing

- Ví dụ

  - 100x100 -> 132x132 do padding

    ```css
    .box {
      width: 100px;
      height: 100px;
      color: #fff;
      background-color: darkorchid;
      padding: 16px;
    }
    ```

    => Muốn giữ kích thước 100x100 thì phải giảm width và height

  - 100x100 -> 104x104 do border

    ```css
    .box {
      width: 68px;
      height: 68px;
      color: #fff;
      background-color: darkorchid;
      padding: 16px;
      border: 2px solid #333;
    }
    ```

    => phải tiếp tục giảm width và height

- Cách giải quyết
  ```css
  .box {
    width: 100px;
    height: 100px;
    color: #fff;
    background-color: darkorchid;
    padding: 16px;
    border: 2px solid #333;
    box-sizing: border-box;
  }
  ```
- When you set the width/height of an element
  - width + padding + border = actual width of an element
  - height + padding + border = actual height of an element
- `Box-sizing`: Defines how the width and height of an element are calculated: should they include padding and borders, or not
  - `width tự điều chỉnh` + padding + border = width of an element `(you set)`
  - Thuộc tính mặc định: `box-sizing: content-box;`

### 9. Css Background

#### 9.1. Background-clip

- background-clip: quyết định background được đổ từ ranh giới nào (border-box, padding-box, content-box, ...)
- Default: `background-clip: border-box`
- ```css
  .header {
    width: 100%;
    height: 100px;
    background-color: #333;
    padding: 20px;
    box-sizing: border-box;
    border: 10px dashed red;
    background-clip: content-box;
  }
  ```

#### 9.2. Background-image

- ```css
  background-image: url(), url();
  background-image: linear-grandient(direction, color-stop1, color-stop2, ...);
  ```

- `background-repeat`
  - default: repeat
  - no-repeat, repeat-x, repeat-y, ...
- `linear-gradient(degree, )`

#### 9.3. Background-size keywords

#### 9.4. Background origin

#### 9.5. Background position

#### 9.6. Background shorthand

### 10. Css Functions

### 11. Css Pseudo

#### 11.1. Pseudo classes

#### 11.2. Pseudo elements

### 12. Css Position

### 13. Css Display

#### 13.1. Flexbox

### 14. Css BEM

## C. 1 số điều lưu ý

### 1. Hyperlink vs Link

#### 1.1. `<link>`

- The `<link>` tag defines the relationship between the current document and an external resource.

- The `<link>` tag is most often used to link to external style sheets or to add a favicon to your website.

- The `<link>` element is an empty element, it contains attributes only.

#### 1.2. `<a>`

- The `<a>` tag defines a hyperlink, which is used to link from one page to another.

- The most important attribute of the `<a>` element is the href attribute, which indicates the link's destination.

- Html Links - Hyperlinks

  - HTML links are hyperlinks.

  - You can click on a link and jump to another document.

  - When you move the mouse over a link, the mouse arrow will turn into a little hand.
  - A link does not have to be text. A link can be an image or any other HTML element!

> - Hiểu đơn giản là `<link>` chỉ đến một external Css file (file css bên ngoài) và sử dụng file đó.
>   Còn `<a>` dẫn tới một page khác.
> - ```html
>   <a href="url">link text</a>
>   ```

> - `<link>` là phần tử rỗng, chỉ có thuộc tính, không hiển thị với người đọc. Còn nội dung thẻ `<a>` là phần mà sẽ được hiển thị tới người đọc.

```

```

### 2. Client-side vs Server side

### 3. GET vs POST
#### 3.1. GET
- Phương thức GET rất dễ nhận thấy đó là trên URL sẽ kèm theo dữ liệu mà chúng ta muốn gửi
- Client gửi lên
  - Phương thức GET là phương thức gửi dữ liệu thông qua đường dẫn URL nằm trên thanh địa chỉ của Browser. Server sẽ nhận đường dẫn đó và phân tích trả về kết quả cho bạn. Server sẽ phân tích tất cả những thông tin đằng sau dấu hỏi (?) chính là phần dữ liệu mà Client gửi lên.
#### 3.2. POST
- Phương thức POST có tính bảo mật hơn vì dữ liệu gửi phải thông qua một form HTML nên nó bị ẩn, nghĩa là chúng ta không thể thấy các giá trị đó được.
- Client gửi Lên
  - Với phương thức GET thì dữ liệu được thấy trên URL thì phương thức POST thì hoàn toàn ngược lại, POST sẽ gửi dữ liệu qua một cái form HTML và các giá trị sẽ được định nghĩa trong các input gồm các kiểu (textbox, radio, checkbox, password, textarea, hidden) và được nhận dang thông qua tên (name) của các input đó.