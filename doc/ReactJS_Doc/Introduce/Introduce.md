# **ReactJs**

- React là một thư viện JavaScript để xây dựng giao diện người dùng.
- React được sử dụng để xây dựng các ứng dụng một trang (SPA - Single Page Application)
- React cho phép tạo các thành phần UI có thể tái sử dụng.

## 1. Virtual DOM
- React tạo ra một DOM ảo trong bộ nhớ. Thay vì thao tác trực tiếp với DOM của trình duyệt, React tạo ra một DOM ảo trong bộ nhớ, nơi mà nó thực hiện các thao tác cần thiết, trước khi thực hiện các thay đổi trong trình duyệt DOM

- Công nghệ DOM ảo giúp tăng hiệu năng cho ứng dụng. Việc chỉ node gốc mới có trạng thái và khi nó thay đổi sẽ tái cấu trúc lại toàn bộ, đồng nghĩa với việc DOM tree cũng sẽ phải thay đổi một phần, điều này sẽ ảnh hưởng đến tốc độ xử lý. React JS sử dụng Virtual DOM (DOM ảo) để cải thiện vấn đề này. Virtual DOM là một object Javascript, mỗi object chứa đầy đủ thông tin cần thiết để tạo ra một DOM, khi dữ liệu thay đổi nó sẽ tính toán sự thay đổi giữa object và tree thật, điều này sẽ giúp tối ưu hoá việc re-render DOM tree thật.

![](https://images.viblo.asia/aee6d47d-8205-43b0-a80b-1fbdfd1d8efc.png)

- React sử dụng cơ chế one-way data binding – luồng dữ liệu 1 chiều. Dữ liệu được truyền từ parent đến child thông qua props. Luồng dữ liệu đơn giản giúp chúng ta dễ dàng kiểm soát cũng như sửa lỗi.

![](https://images.viblo.asia/bd680633-21a9-44a7-9cb7-3df1731ebd12.png)

- Với các đặc điểm ở trên, React dùng để xây dựng các ứng dụng lớn mà dữ liệu của chúng thay đổi liên tục theo thời gian. Dữ liệu thay đổi thì hầu hết kèm theo sự thay đổi về giao diện. Ví dụ như Facebook: trên Newsfeed của bạn cùng lúc sẽ có các status khác nhau và mỗi status lại có số like, share, comment liên tục thay đổi. Khi đó React sẽ rất hữu ích để sử dụng.

## 2. JSX
### 2.1 JSX là gì
- JSX là viết tắt của JavaScript XML. 
- JSX cho phép viết HTML trong React. 
- JSX giúp viết và thêm HTML dễ dàng hơn trong React.
### 2.2 Coding JSX
- JSX không phải HTML, cần phải có Javascript, Babel để dùng JSX
- JSX cho phép viết các phần tử HTML trong JavaScript và đặt chúng vào DOM mà không cần bất kỳ phương thức createdEement () và/hoặc appendChild ().
- Với JSX, bạn có thể viết các biểu thức bên trong `{}`. Biểu thức có thể là một biến React, hoặc thuộc tính hoặc bất kỳ biểu thức JavaScript hợp lệ nào khác. JSX sẽ thực thi biểu thức và trả về kết quả
- Inserting a Large Block of HTML
- Mã HTML phải được bọc trong một phần tử cấp cao nhất. Vì vậy, nếu bạn thích viết hai đoạn văn, bạn phải đặt chúng vào trong một phần tử cha, giống như một element div
 - Ngoài ra, bạn có thể sử dụng `Fragment` để wrap nhiều dòng. Điều này sẽ ngăn chặn thêm các nút thêm vào DOM một cách không cần thiết

## 3. Components

- Các Component giống như các function trả về các element HTML
- Các Component là các bit mã độc lập và có thể tái sử dụng. Chúng phục vụ cùng mục đích với các function JavaScript, nhưng hoạt động trong sự cô lập và trả lại HTML. 
- Các component có hai loại:
  - Class Component
  - Function Component

## 4. Props

- React Elements
  - Sử dụng props giống như với attribute của thẻ HTML
  - 2 props class, for => className, htmlFor
  - Phải tuân theo quy ước có sẵn
- React Components 
  - Sử dụng props giống như đối số cho Component 
  - Tự do đặt tên props 
  - Đặt theo camelCase 
  - Có thể bao gồm dấu gạch ngang
  > Chú ý:
  >
  > - Prop "key" là prop đặc biệt
  > - Props cơ bản là đối số cho Component
  >   => Props có thể là bất cứ kiểu dữ liệu gì
  > - Sử dụng destruction
