import React, { useState } from "react";
// export class Example extends React.Component {
//   constructor(props) {
//     super(props);
//     this.state = {
//       count: 0,
//     };
//   }

//   render() {
//     return (
//       <div>
//         <p>You clicked {this.state.count} times</p>
//         <button onClick={() => this.setState({ count: this.state.count + 1 })}>
//           Click me
//         </button>
//       </div>
//     );
//   }
// }
export function Example() {
  const [count, setCount] = useState(0);

  return (
    <div>
      <button
        onClick={() => {
          // console.log("value before: ", count); //0
          // setCount(count + 1);
          // console.log("value after: ", count); //0

          console.log("value before: ", count); //0
          // setCount((pre) => {
          //   return pre + 1;
          // });
          // setCount((pre) => {
          //   return pre + 1;
          // });
          // Output: 2
          setCount(count + 1);
          setCount(count + 1);
          // Output: 1
        }}
      >
        Click me! {count}
      </button>
    </div>
  );
}

export function NumberComponent() {
  const [count, setCount] = useState(0);
  return (
    <div>
      <p>Giá trị {count}</p>
      <button
        onClick={() => {
          setCount(count + 1);
        }}
      >
        Tăng
      </button>
      <button
        onClick={() => {
          setCount(count - 1);
        }}
      >
        Giảm
      </button>
    </div>
  );
}
