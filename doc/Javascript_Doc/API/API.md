# **JAVASCRIPT - API**

## I. Promise

### 1. Promise là gì?

- JavaScript là một ngôn ngữ lập trình đồng bộ (đơn luồng), có nghĩa là chỉ một điều gì đó có thể xảy ra tại một thời điểm, JavaScript engine chỉ có thể xử lý một câu lệnh tại một thời điểm trong một luồng.

- Promise được sinh ra như một đối tượng đặc biệt dùng cho các xử lý bất đồng bộ. Nó đại diện cho một xử lý bất đồng bộ và promise sẽ trả về giá trị khi thành công (resolve) hoặc thất bại (reject).

- Mục đích của Promise là cơ chế của nó giúp bạn thực hiện các tác vụ bất đồng bộ mà không rơi vào tình trạng callback hell hay pyramid of doom, là tình trạng dùng các callback lồng nhau quá nhiều
  ![callHell](https://images.viblo.asia/e660d989-6410-4ee3-ae94-86de14f463d4.png)

### 2. Cách tạo một Promise?

- Promise nhận vào một hàm callback gồm 2 tham số:

  - `resolve`: một function sẽ được gọi nếu đoạn code bất đồng bộ trong Promise chạy thành công.
  - `reject`: một function sẽ được gọi nếu đoạn code bất đồng bộ trong Promise có lỗi xảy ra.

- Promise cũng cung cấp cho chúng ta các phương thức để xử lý sau khi được thực hiện:
  - `then()`: Dùng để xử lý sau khi Promise được thực hiện thành công (khi resolve được gọi).
  - `catch()`: Dùng để xử lý sau khi Promise có bất kỳ lỗi nào đó (khi reject được gọi).
  - `finally()`: Dùng để xử lý sau khi Promise được thực hiện thành công hoặc thất bại (resolve hoặc reject được gọi)
- Cấu trúc:

```Javascript
const promise = new Promise((resolve, reject) => {
        // Logic
        // Nếu thành công: resolve()
        // Nếu thất bại: reject()
)

promise
    .then((res) => {
        // nếu resolve => callback trong then được gọi
    })
    .catch((err) => {
        // nếu reject => callback trong catch được gọi
    })
    .finally(() => {
        // nếu resolve hoặc reject => callback trong finally được gọi
    });
```

- Ví dụ:

```Javascript
let promise = new Promise((resolve, reject) => {
  reject("Promise rejected");
});

promise
  .then((res) => {
    console.log(res);
  })

  .catch((err) => {
    console.log(err);
  })
  .finally(() => {
    console.log("Done!");
  });
```

### 3. Cách sử dụng Promise?

- Tại mỗi thời điểm, Promise sẽ có những trại thái khác nhau, bắt đầu với `pending` hay `unsetted`. Trạng thái này chính là trạng thái ban đầu của Promise khi được khởi tạo và đang chờ kết quả trả về. Khi quá trình xử lý thực hiện xong xuôi, promise sẽ chuyển sang trạng thái `setted`, khi kết quả được trả về, sẽ có hai khả năng có thể xảy ra:
  _ `fulfilled`: trạng thái xử lý thành công.
  _ `rejected`: trạng thái xử lý thất bại.
  ![howPromiseWorks](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/promises.png)

### 4. Promise Chaining

- Promise còn hỗ trợ cho chúng ta một kỹ thuật khá hay giúp ta kết nối các promise liên tiếp lại với nhau. Vì phương thức then (ở trường hợp promise thành công) khi return giá trị thì nó sẽ tạo một promise khác bọc lại giá trị đó, ta có thể tạo nên phương thức then phía sau để kết nối tiếp.
  ![promiseChaining](https://f.howkteam.vn/Upload/cke/images/2_IMAGE%20TUTORIAL/7_JavaScript/1_So%20tay%20JS/B05/8_B%C3%A0i%205_Promise%20l%C3%A0%20g%C3%AC.png)
- Ví dụ:

```Javascript
let promise = new Promise((resolve, reject) => {
  resolve();
});

promise
  .then(() => {
    return 1;
  })
  .then((res) => {
    console.log(res);
    return 2;
  })
  .then((res) => {
    console.log(res);
    return 3;
  })
  .then((res) => {
    console.log(res);
  })

  .catch((err) => {
    console.log(err);
  })
  .finally(() => {
    console.log("Done!");
  });

```

### 5. Promise methods

#### 5.1. Promise.resolve()

- `Promise.resolve(value)`: Trả về một promise resolved (hoàn thành) với một giá trị cụ thể.
- Ví dụ:

#### 5.2. Promise.reject()

- `Promise.reject(value)`: Trả về một promise rejected (lỗi) với một lỗi cụ thể.
- Ví dụ:

#### 5.3. Promise.all(iterable of multiple promises)

- `Promise.all(value)`:
  - Nhận vào một mảng các promise hoặc cũng có thể là non-promise (number, boolean, .etc).
  - Trả về một promise mới.
  - Chờ tất cả các promise trong mảng resolved, kết quả của promise mới này là một mảng chứa kết quả của các promise theo đúng thứ tự.
  - 1 promise bất kì rejected, kết quả của promise mới này được trả về ngay lập tức lỗi của promise rejected đó, các promise khác vẫn tiếp tục thực thi nhưng kết quả bị bỏ qua.
  - Thực thi promise dạng parallel.
- Ví dụ:

### 5.4. Promise.race(iterable)

- Khác với `Promise.all( )`, `Promise.race()` sẽ xử lý promise đầu tiên có kết quả trả về không quan tâm kết quả trả về có lỗi hay không.
- Ví dụ:

## II. Async, Await

### 1. Async, Await là gì?

- Async/await là cơ chế giúp bạn thực thi các thao tác bất đồng bộ một cách tuần tự hơn , giúp đoạn code nhìn qua tưởng như đồng bộ nhưng thực ra lại là chạy bất đồng bộ, giúp chúng ta dễ hình dung hơn.
- Async await, về bản chất nó được xây dựng dựa trên Promise, và tương thích với tất cả các Promise dựa trên API.

#### 1.1. Async

- Để định nghĩa một hàm bất đồng bộ với async, ta cần khai báo từ khóa `async` ngay trước từ khóa định nghĩa hàm.
- Giá trị trả về của AsyncFunction sẽ luôn là một Promise mặc cho bạn có gọi await hay không, nếu trong code không trả về Promise nào thì sẽ có một promise mới được resolve với giá trị lúc đầu (nếu không có giá trị nào trong return kết quả trả về sẽ là undefine)
- Ví dụ:

```javascript
async function f() {
  console.log("Async function.");
  return Promise.resolve(1);
}

f().then(function (result) {
  console.log(result);
});
```

#### 1.2. Await

- Từ khóa `await`: Được sử dụng bên trong hàm async để chờ hoạt động bất đồng bộ.

  - Khi được đặt trước một Promise, nó sẽ đợi cho đến khi Promise kết thúc và trả về kết quả.
  - Await chỉ làm việc với Promises, nó không hoạt động với callbacks.
  - Await chỉ có thể được sử dụng bên trong các function async.

### 2. Cách dùng

#### 2.1. Cách thức hoạt động

- Ví dụ:

```javascript
let promise1 = new Promise((resolve) => {
  setTimeout(() => {
    resolve("Promise resolved");
  }, 400);
});

const asyncFunc = async () => {
  let result = await promise1;
  console.log(result);
  console.log("hello");
};
asyncFunc();
```

![Working of async/await function](https://cdn.programiz.com/sites/tutorial2program/files/async-await-function.png)

#### 2.2. Error handling

- Dùng catch()

```javascript
let promise = new Promise((resolve, reject) => {
  setTimeout(() => {
    // resolve("Promise resolved");
    reject("Promise rejected");
  }, 100);
});

async function asyncFunc() {
  let result = await promise;
  console.log(result);
}
asyncFunc().catch((err) => {
  console.log(err);
});
```

- Dùng try...catch

```javascript
let promise = new Promise((resolve, reject) => {
  setTimeout(() => {
    // resolve("Promise resolved");
    reject("Promise rejected");
  }, 100);
});

async function asyncFunc() {
  try {
    let result = await promise;
    console.log(result);
  } catch (error) {
    console.log(error);
  }
}
asyncFunc();
```

#### 2.3. So sánh Async/Await với Promise

    - Code dễ đọc hơn là sử dụng một callback hoặc một promise.
    - Xử lý lỗi đơn giản hơn.
    - Gỡ lỗi dễ dàng hơn.

## III. Fetch API, REST API

### 1. Fetch API là gì?

- Fetch API là một API đơn giản cho việc gửi và nhận requesst bằng js.
- Phương thức fetch () nhận đầu vào là url để truy vấn rồi trả về response của request đó.
- Cấu trúc cơ bản của Fetch API như thế này:

```javascript
fetch(url)
  .then(function () {
    // handle the response
  })
  .catch(function () {
    // handle the error
  });
```

- Phương thức fetch() sẽ trả về một Promise, nếu trạng thái của Promise là resolve, đoạn code bên trong phương thức then() sẽ được thực thi, bên trong function này chúng ta thường thực thi các đoạn code để xử lý dữ liệu trả về.
- Khi việc gọi API bằng phương thức fetch() gặp lỗi, lúc này Promise trả về trạng thái là reject, lúc này phương thức catch() sẽ được gọi tới để xử lý các ngoại lệ.
- Mặc định phương thức fetch() sử dụng GET method, nếu muốn sử dụng các method khác như POST chúng ta cần truyền thêm một tham số thứ hai là một object, bên trong object này chứa các định nghĩa cho một request được viết dưới dạng key: value, key ở đây có thể là method, body, headers, cache...

### 2. REST API
#### 2.1. REST API là gì?
- RESTful API là một tiêu chuẩn dùng trong việc thiết kế API cho các ứng dụng web (thiết kế Web services) để tiện cho việc quản lý các resource. Nó chú trọng vào tài nguyên hệ thống (tệp văn bản, ảnh, âm thanh, video, hoặc dữ liệu động…), bao gồm các trạng thái tài nguyên được định dạng và được truyền tải qua HTTP.
  ![restAPI](https://cloudgeeks.net/wp-content/uploads/2020/10/image-12.png)

- 2 thành phần của Rest API:

  - API (Application Programming Interface) là một tập các quy tắc và cơ chế mà theo đó, một ứng dụng hay một thành phần sẽ tương tác với một ứng dụng hay thành phần khác. API có thể trả về dữ liệu mà bạn cần cho ứng dụng của mình ở những kiểu dữ liệu phổ biến như JSON hay XML.

  - REST (REpresentational State Transfer) là một dạng chuyển đổi cấu trúc dữ liệu, một kiểu kiến trúc để viết API. Nó sử dụng phương thức HTTP đơn giản để tạo cho giao tiếp giữa các máy. Vì vậy, thay vì sử dụng một URL cho việc xử lý một số thông tin người dùng, REST gửi một yêu cầu HTTP như GET, POST, DELETE, vv đến một URL để xử lý dữ liệu.

- REST hoạt động chủ yếu dựa vào giao thức HTTP. Các hoạt động cơ bản nêu trên sẽ sử dụng những phương thức HTTP riêng.
  - GET (SELECT): Trả về một Resource hoặc một danh sách Resource.
  - POST (CREATE): Tạo mới một Resource.
  - PUT (UPDATE): Cập nhật thông tin cho Resource.
  - DELETE (DELETE): Xoá một Resource.
> Những phương thức hay hoạt động này thường được gọi là CRUD tương ứng với Create, Read, Update, Delete – Tạo, Đọc, Sửa, Xóa.
#### 2.2 Status Code
Khi chúng ta request một API nào đó thường thì sẽ có vài status code để nhận biết sau:

- 200 OK – Trả về thành công cho những phương thức GET, PUT, PATCH hoặc DELETE.
- 201 Created – Trả về khi một Resouce vừa được tạo thành công.
- 204 No Content – Trả về khi Resource xoá thành công.
- 304 Not Modified – Client có thể sử dụng dữ liệu cache.
- 400 Bad Request – Request không hợp lệ
- 401 Unauthorized – Request cần có auth.
- 403 Forbidden – bị từ chối không cho phép.
- 404 Not Found – Không tìm thấy resource từ URI
- 405 Method Not Allowed – Phương thức không cho phép với user hiện tại.
- 410 Gone – Resource không còn tồn tại, Version cũ đã không còn hỗ trợ.
- 415 Unsupported Media Type – Không hỗ trợ kiểu Resource này.
- 422 Unprocessable Entity – Dữ liệu không được xác thực
- 429 Too Many Requests – Request bị từ chối do bị giới hạn