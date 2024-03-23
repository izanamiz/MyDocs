import React from "react";

// export default class State extends React.Component {
//     constructor(props) {
//         super(props);
//         this.state = {brand: "Ford",model: "Mustang",};
//       }
//       render() {
//         return (
//           <div>
//             <h1>My {this.state.brand} is a {this.state.model}</h1>
//           </div>
//         );
//       }
// }

export default class State extends React.Component {
  constructor(props) {
    super(props);
    //Chỉ định một state
    this.state = { index: 1 };
  }
  render() {
    return (
      <div>
        <p>Giá trị {this.state.index}</p>
        <button
          onClick={() => {
            this.setState({
              index: this.state.index + 1,
            });
          }}
        >
          Tăng
        </button>
        <button
          onClick={() => {
            this.setState({
              index: this.state.index - 1,
            });
          }}
        >
          Giảm
        </button>
      </div>
    );
  }
}
