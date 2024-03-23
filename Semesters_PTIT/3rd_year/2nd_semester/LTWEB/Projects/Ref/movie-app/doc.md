# I. Nodejs

- NodeJS là một nền tảng được xây dựng trên “V8 Javascript engine” được viết bằng c++ và Javascript.

- Node.js ra đời khi các developer đời đầu của JavaScript mở rộng nó từ một thứ bạn chỉ chạy được trên trình duyệt thành một thứ bạn có thể chạy trên máy của mình dưới dạng ứng dụng độc lập.

- Cả trình duyệt JavaScript và Node.js đều chạy trên JavaScript runtime V8 engine. Công cụ này lấy code JavaScript của bạn và convert nó sang mã máy (bytecode) cho việc thực thi nhanh hơn. Mã máy là loại code thấp cấp hơn để máy tính có thể chạy mà không cần biên dịch nó.

## 1. V8

- V8 là một công cụ runtime nguồn mở được viết bằng C++.

- JavaScript -> V8(C++) -> Machine Code

- V8 thực hiện một tệp lệnh gọi là ECMAScript như được chỉ định trong ECMA-262. ECMAScript được tạo ra bởi Ecma International để chuẩn hoá JavaScript.

- Về cơ bản việc này cho phép bạn thêm các tính năng vào JavaScript bằng cách nhúng V8 vào code C++ để code C++ của bạn có thể hiểu hơn những gì ECMAScript chỉ định

## 2. Npm

- NPM viết tắt của từ Node Package Manager là một công cụ tạo và quản lý các thư viện javascript cho Nodejs

- NPM cung cấp 2 chức năng chính bao gồm:

  - Là kho lưu trữ trực tuyến cho các package/module. Chúng ta có thể tìm kiếm các package trên search.nodejs.org.

  - Quản lý các module javascript và phiên bản của chúng trong các dự án của chúng ta đơn giản hơn, dễ dàng hơn, tiết kiệm thời gian hơn.

- File package.json sẽ lưu trữ xem project của chúng ta cần sử dụng những module nào, version của nó là bao nhiêu. Chi tiết của nó sẽ được lưu trữ tại package-lock.json bao gồm phiên bản, nơi lưu trữ, những module cần thiết để chạy module mình cần chạy

## 3. Node Modules

- Module Node là 1 block code có thể tái sử dụng mà sự tồn tại của nó không vô tình ảnh hưởng đến các code khác.

- Bạn có thể tạo module của riêng mình và sử dụng nó với nhiều ứng dụng khác nhau. Node.js có 1 bộ built-in module bạn có thể sử dụng mà không cần cài đặt thêm gì nữa.

# II. react-query

- Đơn giản thì react-query là thư viện để fetching, caching và updating dữ liệu bất đồng bộ của React.

- react-query cung cấp nhiều hooks với API cực kì đơn giản để fetch cũng như update dữ liệu từ server. Hỗ trợ sẵn caching, refetching và nhiều thứ khác.

## 1. useQuery

Để sử dụng hook useQuery, ta phải truyền ít nhất 2 tham số:

- Tham số đầu tiên là queryKey
- Tham số thứ 2 là hàm trả về 1 promise:
  - Resolve data, hoặc
  - Throw error
- Tham số thứ 3 là các options
- queryKey được sử dụng để refetching, caching và chia sẻ dữ liệu giữa các component với nhau.
- Sau đây là ví dụ sử dụng useQuery cơ bản.

```jsx
const { data: commentList } = useQuery({
  queryKey: ["comments"],
  queryFn: async () => {
    const { data } = await httpRequest.get("/review", {
      headers: {
        Authorization: `Bearer ${currentUser.token}`,
      },
    });
    return data;
  },
});
```

> queryFn là một hàm bất đồng bộ, được truyền vào để lấy dữ liệu cho query. Hàm này sẽ được gọi mỗi khi query được gọi, và nó sẽ trả về một promise chứa kết quả query.

## 2. useMutation

- useMutation khác với useQuery, được sử dụng để tạo/thay đổi/xóa dữ liệu ở. (ví dụ như đăng ký, đăng nhập).

- Để sử dụng hook useMutation, ta phải truyền ít nhất 1 tham số:

  - Tham số thứ nhất là hàm trả về 1 promise:
    - Resolve data, hoặc
    - Throw error
  - Tham số thứ 2 là các options

```jsx
const commentUpdateMutation = useMutation({
  mutationFn: async (body) => {
    const { data } = await httpRequest.post(
      `/review/${commentDetail.id}`,
      body,
      {
        headers: {
          Authorization: `Bearer ${currentUser.token}`,
        },
      }
    );
    return data;
  },
});
```

> - mutationFn là một hàm async, nhận đầu vào là body của request. Khi mutationFn được gọi, React Query sẽ tự động thực hiện request và cập nhật kết quả trên UI nếu request thành công. Nếu request thất bại, mutationFn sẽ trả về một lỗi (error) và React Query sẽ quản lý lỗi đó để hiển thị thông báo lỗi tương ứng trên UI.
> - Trong React Query, mutate là một method được cung cấp bởi hook useMutation. Method này được sử dụng để thực thi mutation request (như là một POST, PUT, DELETE request) và cập nhật kết quả trên client-side cache.
>   - mutate có thể nhận đầu vào là data payload hoặc một function, và trả về một promise. Khi promise được resolve, client-side cache sẽ được tự động cập nhật với kết quả mới nhất từ server.
>   - Ngoài ra, mutate cũng hỗ trợ một số options như onSuccess, onError, onSettled để xử lý các trạng thái khác nhau của mutation request.

### 3. useQueryClient

- useQueryClient là một hook được cung cấp bởi thư viện React Query, nó được sử dụng để lấy truy vấn query client để truy cập và thao tác với bộ nhớ cache của các truy vấn đã được lưu trong đó.

- Khi sử dụng useQueryClient, bạn có thể gửi các yêu cầu truy vấn mới và cập nhật bộ nhớ cache cho các yêu cầu truy vấn hiện có. Nó cũng cung cấp các phương thức để làm mới hoặc xóa các truy vấn khỏi bộ nhớ cache.

- `queryClient.invalidateQueries` được sử dụng để thông báo cho React Query rằng danh sách comment đã thay đổi và cần được tải lại. invalidateQueries nhận đối số là một đối tượng mô tả key của query cần được tải lại.

# III. react hook

## 1. Hooks

- Hooks là các hàm mà cho phép bạn “hook into (móc vào)” trạng thái của React và các tính năng vòng đời từ các hàm components. Hooks không hoạt động bên trong classes — chúng cho phép bạn sử dụng React không cần classes.

## 2. useRef

- useRef giữ giá trị của biến này qua các lần render của component.

- Khi sử dụng useRef, ta có thể thay đổi giá trị của biến đối tượng tham chiếu mà không gây ra việc re-render component.

- useRef trả về một đối tượng reference, và ta có thể truy cập vào giá trị hiện tại của biến tham chiếu thông qua thuộc tính `current` của đối tượng reference đó.

> - Đối tượng reference là một đối tượng trong JavaScript được sử dụng để tham chiếu đến một vùng nhớ khác trong bộ nhớ của máy tính.
> - Đối tượng reference cho phép ta truy cập và thao tác với giá trị được lưu trữ trong vùng nhớ này thông qua việc truy cập vào đối tượng reference đó.

- `fowardRef`:

  - forwardRef là một hàm trong React được sử dụng để chuyển tiếp (forward) một ref từ một component cha xuống cho một component con, mà không làm mất tính năng ref của component con đó.

  - Khi sử dụng forwardRef, ta có thể truyền ref vào một component con bên trong component cha, giúp cho ta có thể truy cập và thao tác trực tiếp với các phần tử DOM hoặc các thành phần khác trong component con đó, mà không cần thông qua component cha.

  - Ví dụ, ta có thể sử dụng forwardRef để chuyển tiếp ref vào một component con là input để truy cập và thay đổi giá trị của input đó:

  ```jsx
  import React, { forwardRef } from "react";

  const Input = forwardRef((props, ref) => {
    return <input type="text" ref={ref} {...props} />;
  });

  function App() {
    const inputRef = useRef(null);

    function handleClick() {
      inputRef.current.value = "Hello World";
    }

    return (
      <div>
        <Input ref={inputRef} />
        <button onClick={handleClick}>Set Value</button>
      </div>
    );
  }
  ```

  - Trong ví dụ này, ta sử dụng forwardRef để chuyển tiếp ref từ component cha App xuống cho component con Input. Khi người dùng click vào nút "Set Value", giá trị của input được truyền vào thông qua ref sẽ được thay đổi thành "Hello World".

## 3. useImperativeHandle

- useImperativeHandle là một Hook của React cho phép bạn tùy chỉnh phần tử hiển thị bên ngoài của một component khi được truy cập thông qua ref.

- Trong React, khi ta tạo một ref cho một component con, ta có thể truy cập tất cả các phần tử DOM của component con đó. Tuy nhiên, trong một số trường hợp, ta muốn chỉ truy cập một số phần tử DOM hoặc các hàm của component con, mà không cần phải truy cập tất cả các phần tử DOM của nó. Đó chính là khi ta sử dụng useImperativeHandle.

- useImperativeHandle cho phép bạn chỉ định các phương thức hoặc thuộc tính được truy cập thông qua ref. Bằng cách này, ta có thể tùy chỉnh cách các phương thức và thuộc tính của component được truy cập thông qua ref.

- Ví dụ, ta có thể sử dụng useImperativeHandle để tạo một hàm focus cho một component Input, giúp ta có thể truy cập trực tiếp vào phần tử DOM của Input khi nó được focus:

```jsx
import React, { useRef, useImperativeHandle } from "react";

const Input = React.forwardRef((props, ref) => {
  const inputRef = useRef(null);

  useImperativeHandle(ref, () => ({
    focus: () => {
      inputRef.current.focus();
    },
  }));

  return <input type="text" ref={inputRef} {...props} />;
});

function App() {
  const inputRef = useRef(null);

  function handleClick() {
    inputRef.current.focus();
  }

  return (
    <div>
      <Input ref={inputRef} />
      <button onClick={handleClick}>Focus</button>
    </div>
  );
}
```

- Trong ví dụ này, ta sử dụng useImperativeHandle để tạo ra một hàm focus cho component Input. Khi người dùng click vào nút "Focus", hàm focus này sẽ được gọi và đưa con trỏ chuột tới input của Input.
