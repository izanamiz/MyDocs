// Create a Promise
// let promise = new Promise((resolve, reject) => {
//   reject("Promise rejected");
// });

// promise
//   .then((res) => {
//     console.log(res);
//   })

//   .catch((err) => {
//     console.log(err);
//   })
//   .finally(() => {
//     console.log("Done!");
//   });

// Promise Chaining
let promise = new Promise((resolve, reject) => {
  resolve();
});

promise
    // .then(() => {
    //   return 1;
    // })
  .then(() => {
    return new Promise((resolve) => {
      setTimeout(()=>{resolve([1,2,3])}, 3000);
    });
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

// Promise.resolve()
// const promise1 = Promise.resolve(123);
// promise1.then((value) => {
//   console.log(value);
// });

// Promise.reject()

// Promise.all()
// const p1 = Promise.resolve(3);
// // const p2 = 1337;
// const p3 = new Promise((resolve, reject) => {
//   setTimeout(() => {
//     resolve("foo");
//   }, 100);
// });
// // p2 = Promise.reject("Error!");
// Promise.all([p1, p2, p3])
//   .then((values) => {
//     console.log(values); // [3, 1337, "foo"]
//   })
//   .catch((err) => {
//     console.log(err);
//   });

// Promise.race()
// const promise1 = new Promise((resolve, reject) => {
//   setTimeout(() => {
//     resolve("one");
//   }, 500);
// });

// const promise2 = new Promise((resolve, reject) => {
//   setTimeout(() => {
//     resolve("two");
//   }, 100);
// });

// Promise.race([promise1, promise2]).then((value) => {
//   console.log(value);
// });

// Async Function
// async function f() {
//     console.log('Async function.');
//     return Promise.resolve(1);
// }

// f().then(function(result) {
//     console.log(result)
// });

// async/await
let promise1 = new Promise((resolve) => {
  setTimeout(() => {
    resolve("Promise resolved");
  }, 3000);
});

let promise2 = new Promise((resolve) => {
  setTimeout(() => {
    resolve("Promise resolved");
  }, 5000);
});
const asyncFunc = async () => {
  let p1 = await new Promise((resolve) => {
    setTimeout(() => {
      resolve("Promise resolved");
    }, 3000);
  });
  let p2 = await new Promise((resolve) => {
    setTimeout(() => {
      resolve("Promise resolved");
    }, 5000);
  });
  // let p1 = await promise1;
  // let p2 = await promise2;
  console.log(p1.concat(p2));
};
asyncFunc();

//Error Handling
// let promise = new Promise((resolve, reject) => {
//   setTimeout(() => {
//     // resolve("Promise resolved");
//     reject("Promise rejected");
//   }, 100);
// });

// async function asyncFunc() {
//   let result = await promise;
//   console.log(result);
// }
// asyncFunc().catch((err) => {
//   console.log(err);
// });
