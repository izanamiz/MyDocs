/*------------------DOM---------------*/
{
  // const ulDOM = document.createElement("ul");
  // ulDOM.id = "ul-id";
  // ulDOM.style = "color: red; font-size: 30px";
  // const liDOM1 = document.createElement("li");
  // liDOM1.innerText = "Javascript";
  // liDOM1.id = "li-1";
  // const liDOM2 = document.createElement("li");
  // liDOM2.innerText = "ReactJS";
  // ulDOM.appendChild(liDOM1);
  // ulDOM.appendChild(liDOM2);
  // document.body.appendChild(ulDOM);
}

/*------------------ReactDOM---------------*/
{
  // const ulReact = React.createElement(
  //   "ul",
  //   { id: "ul-id" },
  //   React.createElement("li", { id: "li-1" }, "Javascript"),
  //   React.createElement("li", null, "ReactJS")
  // );
  // const root = document.getElementById("root");
  // ReactDOM.render(ulReact, root);
  // var reactCourse = "React JS";
  // var ulReact =  React.createElement(
  //   "ul",
  //   {
  //     class: "course-list",
  //   },
  //    React.createElement(
  //     "li",
  //     {
  //       style: {
  //         color: "red",
  //       },
  //     },
  //     "Javascript"
  //   ),
  //    React.createElement("li", null, reactCourse)
  // );
  // const root = document.getElementById("root");
  // ReactDOM.render(ulReact, root);
}

/*------------------React@17 vs React@18---------------*/
{
  /* ---------React@17--------- */
  // const postItem = React.createElement(
  //   "div",
  //   { className: "post-item" },
  //   React.createElement("h2", { title: "Học React tại F8" }, "Học ReactJs"),
  //   React.createElement("p", {}, "Học ReactJs từ cơ bản đến nâng cao")
  // );
  // const container = document.getElementById("root");
  // ReactDOM.render(postItem, container);
  /* ---------React@18--------- */
  //  const root = ReactDOM.createRoot(container)
  //  root.render(postItem)
}

/*------------------JSX---------------*/
{
  // const reactCourse = "React JS";
  // const ulReact = (
  //   <ul class="course-list">
  //     <li style={{ color: "red" }}>Javascript</li>
  //     <li>{reactCourse}</li>
  //   </ul>
  // );
  // ReactDOM.render(ulReact, document.getElementById("root"));
  // const jsx = (
    // Error
    // JSX expressions must have one parent element.
    // <h1>Heading 1</h1>
    // <h2>Heading 2</h2>
  //   <React.Fragment>
  //     {" "}
  //     <h1>Heading 1</h1>
  //     <h2>Heading 2</h2>{" "}
  //   </React.Fragment>
  // );
  //   React.createElement(
  //     React.Fragment,
  //     null,
  //     React.createElement("h1", null, "Heading 1"),
  //     React.createElement("h2", null, "Heading 2")
  //   );
  // ReactDOM.render(jsx, document.getElementById("root"));
}

/*------------------JSX Render Arrays---------------*/
{
  // const reactCourse = "React JS";
  // const courses = [
  //   { name: "Html/Css" },
  //   { name: "Responsive Web Design" },
  //   { name: "ReactJS" },
  // ];
  // const jsx = (
  //   <ul class="course-list">
  //     {courses.map((course) => (
  //       <li>{course.name}</li>
  //     ))}
  //     {/* {courses.map((course) => React.createElement("li", null, course.name))} */}
  //   </ul>
  // );
  // ReactDOM.render(jsx, document.getElementById("root"));
}

/*------------------Components, Props---------------*/
{
  /*------------------Components---------------*/
  // function Header() {
  //     return (
  //         <div className="header">Header</div>
  //     )
  // }
  // class Content extends React.Component {
  //     render() {
  //         return (
  //             <div className="content">Content</div>
  //         )
  //     }
  // }
  // const app = (
  //     <div className="wrapper">
  //         <Header></Header>
  //         <Content />
  //         <div className="footer">Footer</div>
  //     </div>
  // )
  // ReactDOM.render(app, document.getElementById('root'));
  
  /*------------------Props---------------*/

  // function PostItem({ title, image, description, callback = () => {} }) {
  //   callback(Math.random());
  //   return (
  //     <div className="post-item">
  //       <h2 className="post-title">{title}</h2>
  //       <img src={image} alt={title} />
  //       <p className="post-desc">{description}</p>
  //     </div>
  //   );
  // }
  // function App() {
  //   return (
  //     <div id="wrapper">
  //       <PostItem
  //         title="Vitrtual DOM tree"
  //         image="https://images.viblo.asia/aee6d47d-8205-43b0-a80b-1fbdfd1d8efc.png"
  //         description="Vitrtual DOM tree"
  //         data={[{ a: 1 }, { b: 2 }]}
  //         callback={(random) => {
  //           console.log("random: ", random);
  //         }}
  //       />
  //       <PostItem />
  //       <PostItem />
  //     </div>
  //   );
  // }
  // ReactDOM.render(<App />, document.getElementById("root"));
}

// console.log("hello");
