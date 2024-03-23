import logo from "./logo.svg";
import "./App.css";
import Compo from "./components/Compo.js";
import { Props } from "./props/Props.js";
import { Events, Form, Bind } from "./events/Events.js";
import State from "./state/State.js";
import { Example, NumberComponent } from "./useState/useState.js";
function App() {
  // const listItem = [
  //   {
  //     name: "John",
  //     age: 34,
  //     id: 1,
  //   },
  //   { name: "Mary", age: 35, id: 2 },
  //   { name: "Peter", age: 36, id: 3 },
  // ];
  // return (
  //   <>
  //     {" "}
  //     <div className="App">
  //       {listItem.map((item, index) => {
  //         return (
  //           <h1 key={item.id} className={item.id === 1 ? "active" : "disabled"}>
  //             {item.name}---{item.age}
  //           </h1>
  //         );
  //       })}
  //     </div>
  //     <Compo />
  //   </>
  // );
  return (
    <>
      {""}
      <div className="App">
        <Example />
      </div>
      {""}
    </>
  );
}

export default App;
