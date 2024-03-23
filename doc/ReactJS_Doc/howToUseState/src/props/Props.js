export const posts = [
  {
    id: 1,
    title: "Vitrtual DOM tree",
    image: "https://images.viblo.asia/aee6d47d-8205-43b0-a80b-1fbdfd1d8efc.png",
    description: "Vitrtual DOM tree",
    data: [{ a: 1 }, { b: 2 }],
  },
];
// export function PostItem({ props, callback }) {
//   return (
//     <div className="post-item">
//       <label htmlFor="email">Email </label>
//       <input id="email"></input>
//       <h2 className="post-title">{props.title}</h2>
//       <img src={props.image} alt={props.title} />
//       <p className="post-desc">{props.description}</p>
//       <ul>
//         {props.data.map((item) => {
//           return <li>{Object.keys(item)} : {Object.values(item)} </li>;
//         })}
//       </ul>
//       <p>{callback()}</p>
//     </div>
//   );
// }
// export function Props() {
//   // console.log(<PostItem title="Test" />);
//   return (
//     <div id="wrapper">
//       {posts.map((item) => {
//         return (
//           <PostItem
//             // key={item.id}
//             props={item}
//             callback={(random) => {
//               return <div>random: {Math.random()}</div>;
//             }}
//           />
//         );
//       })}
//     </div>
//   );
// }

/*---------------------Destructuring--------------------*/
export function PostItem({ title, image, description, callback = () => {} }) {
  callback(Math.random());
  return (
    <div className="post-item">
      <h2 className="post-title">{title}</h2>
      <img src={image} alt={title} />
      <p className="post-desc">{description}</p>
    </div>
  );
}
export function Props() {
  // console.log(<PostItem title="Test" />);
  return (
    <div id="wrapper">
      <PostItem
        // key={1}
        title="Vitrtual DOM tree"
        image="https://images.viblo.asia/aee6d47d-8205-43b0-a80b-1fbdfd1d8efc.png"
        description="Vitrtual DOM tree"
        data={[{ a: 1 }, { b: 2 }]}
        callback={(random) => {
          console.log("random: ", random);
        }}
      />
    </div>
  );
}
