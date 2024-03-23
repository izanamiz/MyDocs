
# Bộ câu hỏi phỏng vấn

- <a href="#item1">Html</a>
- <a href="#item2">Css</a>
- <a href="#item3">Js</a>
- <a href="#item4">Reactjs</a>

## <div id="item1"> I. Html</div>

- <a href="#html1">1. Elements</a>
- <a href="#html2">2. Attributes</a>
- <a href="#html3">3. Block & Inline</a>
- <a href="#html4">4. Class & Id </a>
- <a href="#html5">5. Layout</a>
- <a href="#html6">6. Semantic elements</a>
- <a href="#html7">7. File paths</a>

### <div id="html1"> 1. Elements</div>

### <div id="html2"> 2. Attributes</div>

### <div id="html3"> 3. Block & Inline </div>

### <div id="html4"> 4. Class & Id </div>

### <div id="html5"> 5. Layout</div>

### <div id="html6"> 6. Semantic elements</div>

### <div id="html7"> 7. File paths</div>

## <div id="item2">II. Css</div>

- <a href="#css1">1. BEM</a>
- <a href="#css2">2. Inline, Block, Inline-Block</a>
- <a href="#css3">3. Flex box & Grid</a>
- <a href="#css4">4. Box model</a>
- <a href="#css5">5. Position</a>
- <a href="#css6">6. Phân biệt các đơn vị</a>
- <a href="#css7">7. Css Selector</a>
- <a href="#css8">8. Pseudo class</a>
- <a href="#css9">9. Responsive</a>

### <div id="css1">1. BEM</div>

### <div id="css2">2. Inline, Block, Inline-Block</div>

### <div id="css3">3. Flex box & Grid</div>

### <div id="css4">4. Box model</div>

### <div id="css5">5. Position</div>

### <div id="css6">6. Phân biệt các đơn vị</div>

### <div id="css7">7. Css selector</div>

### <div id="css8">8. Pseudo class</div>

### <div id="css9">9. Responsive</div>

## <div id="item3">II. Js</div>

- <a href="#js1">1. DOM</a>
- <a href="#js2">2. var, let, const</a>
- <a href="#js3">3. Promise, Callback</a>
- <a href="#js4">4. Async, await</a>
- <a href="#js5">5. Cookies, session, local storage</a>
- <a href="#js6">6. Hoisting</a>
- <a href="#js7">7. API</a>
- <a href="#js8">8. ES6</a>
- <a href="#js9">9. Node package manager</a>

### <div id="js1">1. DOM</div>

### <div id="js2">2. var, let, const</div>

### <div id="js3">3. Promise, Callback</div>

### <div id="js4">4. Async, await</div>

### <div id="js5">5. Cookies, session, local storage</div>

### <div id="js6">6. Hoisting</div>

### <div id="js7">7. API</div>

### <div id="js8">8. ES6</div>

### <div id="js9">9. Node package manager</div>

## <div id="item4">IV. Reactjs</div>

- <a href="#react1">1. JSX</a>
- <a href="#react2">2. Virtual DOM</a>
- <a href="#react3">3. State & Lifecycle</a>
- <a href="#react4">4. Higher order component</a>
- <a href="#react5">5. Redux</a>
- <a href="#react6">6. Router</a>

### <div id="react1">1. JSX</div>

### <div id="react2">2. Virtual DOM</div>

### <div id="react3">3. State & Lifecycle</div>

### <div id="react4">4. Higher order component</div>

### <div id="react5">5. Redux</div>

### <div id="react6">6. Router</div>

## V. Bonus

### 1. JS

- Toán tử hợp nhất(??) - Nullish Coalescing Operator
  - Được sử dụng để kiểm tra và trả về giá trị không null hoặc undefined
  - x ?? y: nếu x là null hoặc undefined, thì giá trị của y sẽ được trả về. Ngược lại, nếu x không phải là null hoặc undefined, giá trị của x sẽ được trả về.
- null vs undefined:
  - null được coi là 1 giá trị rỗng được gán cho biến hoặc thuộc tính
  - undefined chỉ xảy ra khi chưa gán giá trị cho biến hoặc thuộc tính
- Toán tử Logic Not (!)

  - Bạn có thể sử dụng toán tử Logic Not (!) để ép kiểu một giá trị về kiểu boolean. Toán tử này sẽ đảo ngược giá trị của biểu thức thành giá trị boolean đối lập.
    -
    ```js
    const x = 5;
    const booleanValue = !!x;
    console.log(booleanValue); // Output: true
    ```

- true, false
  - Lưu ý rằng trong JavaScript, các giá trị sau sẽ được ép kiểu về false: false, 0, null, undefined, NaN, '' (chuỗi rỗng)
  - Tất cả các giá trị còn lại sẽ được ép kiểu về true.
- NaN
  - NaN là một giá trị đặc biệt trong JavaScript, viết tắt của "Not a Number" (không phải là số). Nó đại diện cho một giá trị không phải là số hợp lệ trong các phép tính số học.
  - Khi một phép tính số học không thể được thực hiện hoặc trả về một kết quả không xác định, kết quả sẽ là NaN.
  -
  ```js
  const result1 = 0 / 0; // Kết quả NaN
  const result2 = Math.sqrt(-1); // Kết quả NaN
  const result3 = parseInt("abc"); // Kết quả NaN
  ```
- var, let, const, hoisting

  - var: function scope, global scope, biến được hoisting
  - let, const: block scope, không được hoisting
  - hoisting:

    - hoisting trong Js có nghĩa là di chuyển các khai báo biến lên đầu phạm vi của chúng, cho phép bạn sử dụng biến trước khi khai báo. Tuy nhiên, chỉ có khai báo được di chuyển lên đầu, không phải gán giá trị.
    - Khi Js thực thi mã, nó trước tiên quét qua các khai báo biến và hàm để tạo ra các biến và hàm trong bộ nhớ, trước khi thực hiện các phần còn lại của mã. Điều này cho phép bạn sử dụng biến trước khi chúng được khai báo trong mã nguồn.
    - 
    ```js
    console.log(a); // Output: ReferenceError: a is not defined
    console.log(b); // Output: undefined
    var b = 20;
    ```

### 2. React

- Tại sao không trực tiếp cập nhật state trong react:
  - Trong React, không thể trực tiếp cập nhật trạng thái (state) mà phải sử dụng useState để quản lý trạng thái của các thành phần. Điều này là do React xây dựng hệ thống giao diện người dùng dựa trên khái niệm "các trạng thái (states) và các thuộc tính (props)".
  - Cách tiếp cận này giúp tạo ra các thành phần có trạng thái (stateful components) trong React. Khi một trạng thái thay đổi, React sẽ tự động tái render các thành phần liên quan và cập nhật giao diện người dùng tương ứng. Điều này giúp duy trì tính nhất quán và hiệu suất trong ứng dụng.
  - Việc sử dụng useState giúp bạn tách rời logic của trạng thái khỏi giao diện và tạo ra một quy trình quản lý trạng thái rõ ràng hơn.
  - Virtual DOM là một khái niệm quan trọng trong React, nó là một bản sao của DOM thực tế được React tạo ra và quản lý. Khi trạng thái trong React thay đổi, React sẽ so sánh và tìm ra sự khác biệt giữa virtual DOM cũ và mới. Dựa trên sự khác biệt này, React sẽ chỉ áp dụng những thay đổi cần thiết lên DOM thực tế, giúp tối ưu hiệu suất và tốc độ của ứng dụng.
  - Khi sử dụng useState, React sẽ theo dõi và quản lý các trạng thái của các thành phần. Khi bạn gọi hàm cập nhật trạng thái, React sẽ tạo ra một bản sao mới của virtual DOM và so sánh với bản sao cũ. Nếu có sự khác biệt, React sẽ cập nhật chỉ những phần cần thiết trên DOM thực tế để phản ánh trạng thái mới.
  - Việc sử dụng virtual DOM giúp tối ưu hiệu suất bởi vì thay vì cập nhật toàn bộ DOM thực tế mỗi khi trạng thái thay đổi, React chỉ cập nhật những phần thay đổi duy nhất. Điều này giúp giảm tải và cải thiện tốc độ render của ứng dụng.
  - Vì vậy, việc sử dụng useState để cập nhật trạng thái trong React liên quan chặt chẽ đến việc sử dụng virtual DOM để tối ưu hiệu suất và tái render chỉ những phần thay đổi cần thiết trên DOM thực tế.

### 3. Rest API