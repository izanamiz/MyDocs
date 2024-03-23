// function User(firstName, lastName){
//     this.firstName = firstName;
//     this.lastName = lastName;

//     this.getName = function(){
//         return `${this.firstName} ${this.lastName}`;
//     }
// }

// var author = new User('Vanh', 'Tran');
// var user = new User('Giang', 'Nguyen');

// var date = new Date();
// var num = new Number();
// console.log(num.toPrecision());

// console.log(author.getName());
// console.log(user.getName());

// const person1 = {};
// person1['firstname'] = 'Mario';
// person1['lastname'] = 'Rossi';

// console.log(person1.firstname);
// // expected output: "Mario"

// const person2 = {
//   firstname: 'John',
//   lastname: 'Doe'
// };

// console.log(person2['lastname']);
// // expected output: "Doe"
// let object = {}
// object['1'] = 'value'
// console.log(object[1])

// let foo = {unique_prop: 1}, bar = {unique_prop: 2}, object = {};
// object[foo] = 'value'
// console.log(object[bar])

// four variables are created and assigned in a single go,
// separated by commas
// const myObj = {},
//       str = 'myString',
//       rand = Math.random(),
//       anotherObj = {};

// Now, creating additional properties.
// myObj.type              = 'Dot syntax for a key named type';
// myObj['date created']   = 'This key has a space';
// myObj[str]              = 'This key is in variable str';
// myObj[rand]             = 'A random number is the key here';
// myObj[anotherObj]       = 'This key is object anotherObj';
// myObj['']               = 'This key is an empty string';

// console.log(myObj);
// console.log(myObj.myString);

// function Person(name, age, gender) {
//   this.name = name;
//   this.age = age;
//   this.gender = gender;
// }

// const rand = new Person("Rand McKinnon", 33, "M");
// const ken = new Person("Ken Jones", 39, "M");

// function Car(make, model, year, owner) {
//   this.make = make;
//   this.model = model;
//   this.year = year;
//   this.owner = owner;
//   function displayCar() {
//     const result = `A Beautiful ${this.year} ${this.make} ${this.model}`;
//     console.log(result);
//   }
//   this.displayCar = displayCar;
// }

// const car1 = new Car("Eagle", "Talon TSi", 1993, rand);
// const car2 = new Car("Nissan", "300ZX", 1992, ken);
// // console.log(car2.owner.name);
// console.log(typeof car2.owner);
// car1.displayCar();

// const Animal = {
//   type: "Invertebrates", // Default value of properties
//   displayType: function () {
//     // Method which will display type of Animal
//     console.log(this.type);
//   },
// };

// // Create new animal type called animal1
// const animal1 = Object.create(Animal);
// animal1.displayType(); // Output: Invertebrates

// // Create new animal type called fish
// //   const fish = Object.create(Animal);
// fish = Object.create(Animal);
// fish.type = "Fishes";
// fish.displayType(); // Output: Fishes


const arr = ['p', 'r', 'o', 'p', 't', 'I'];
const arr1 = ['We', 'are'];
const arr2 = ['members'];

// array length
console.log(arr.length); // 6

// access
console.log(arr[0]); // p

// add & change
arr[5] = 'i';
arr[6] = 't';
console.log(arr); //'p', 'r', 'o', 'p', 't', 'i', 't'

// remove last ele
arr.pop();
console.log(arr); // ['p', 'r', 'o', 'p', 't', 'i']

// remove first ele
arr.shift();
console.log(arr); // ['r', 'o', 'p', 't', 'i']

// add a new element to the end
arr.push('t');
console.log(arr); // ['r', 'o', 'p', 't', 'i', 't']

// add a new element to the beginning
arr.unshift('p');
console.log(arr); // ['p', 'r', 'o', 'p', 't', 'i', 't']

// join 2 arrays
const tmp = arr1.concat(arr.concat(arr2));
console.log(tmp); //  ['We', 'are', 'p', 'r', 'o', 'p', 't', 'i', 't', 'members']

// Joins all elements of an array into a string.
console.log(arr.join('')); // proptit

// sort the elements alphabetically in strings and in ascending order
console.log(arr.sort());  // ['i', 'o', 'p', 'p', 'r', 't', 't']

// inserts at index 2
arr1.splice(2,0,'a');
console.log(arr1); // ['We', 'are', 'a']
// replaces 1 element at index 2
arr1.splice(2,1,'ProPTIT members');
console.log(arr1); //['We', 'are', 'ProPTIT members']
