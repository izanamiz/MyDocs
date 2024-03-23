import React from "react";
export const handleClick = (event, mess) => {
  console.log(event.target);
  console.log(mess);
  console.log(Math.random());
};

const handleClick2 = (event) => {
  // user
  handleClick(event, "abc");
  // handleClick(event);
};

const handleClickAgain = (name) => {
  console.log("hello " + name);
};

export function Events() {
  // return <button onClick={handleClick}>Click me!</button>;
  // return <button onClick={() => handleClick()}>Click me!</button>;
  // return <button onClick={handleClick2}>Click me!</button>;

  return (
    <button
      onClick={() => {
        handleClickAgain("mario");
      }}
    >
      Click me Again
    </button>
  );
}

// Javascript Engine: handleClick(event)

export class Bind extends React.Component {
  // constructor(props) {
  //   super(props);
  //   this.handleClick = this.handleClick.bind(this, "Ahihi");
  // }
  handleClick(mess) {
    console.log("this is:" + mess);
  }

  render() {
    // Cú pháp này đảm bảo `this` được ràng buộc trong handleClick
    return (
      <button onClick={this.handleClick().bind(this, "ahihi")}>Click me</button>
    );
  }
}
