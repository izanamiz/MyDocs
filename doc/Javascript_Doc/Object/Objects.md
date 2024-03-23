# **JAVASCRIPT OBJECTS**

> - I. Objects Overview
> - II. Object Properties (`.` & `[]`)
> - III. Methods & `this` keyword
> - IV. Create Objects (literal, instance, constructor, `Object.create()`)
> - V. Prototype
> - VI. Getter & Setter
> - VII. Built-in Objects (array, function, object)

---

## I. Objects Overview (Tổng quát)

### 1. Definition (Định nghĩa)

- Đối tượng JavaScript là một loại dữ liệu non-primitive (không nguyên thủy) cho phép bạn lưu trữ nhiều bộ sưu tập dữ liệu (multiple collections of data)
- > Bạn không cần phải tạo các class để tạo các object.

### 2. Declaration (Khai báo)

- Syntax:

```Javascript
const object_name = {
   key1: value1,
   key2: value2
}
```

- Mỗi thành viên của một đối tượng là một cặp key: value được phân tách bằng dấu `,` và được đặt trong `{}`

- Ví dụ:

```Javascript
// object creation
const person = {
    name: 'John',
    age: 20
};
console.log(typeof person); // object
```

### 3. Nested Objects (Đối tượng lồng nhau)

Một đối tượng cũng có thể chứa một đối tượng khác

```Javascript
// nested object
const student = {
    name: 'John',
    age: 20,
    marks: {
        science: 70,
        math: 75
    }
}

// accessing property of student object
console.log(student.marks); // {science: 70, math: 75}

console.log(typeof student.marks); // object

// accessing property of marks object
console.log(student.marks.science); // 70
```

---

## II. Object Properties

- Trong JavaScript, các cặp "Key: value" được gọi là thuộc tính.
  ![Properties](https://cdn.programiz.com/sites/tutorial2program/files/javascript-object-properties.png)

### 1. Accessing Object Properties (Truy cập thuộc tính của đối tượng)

#### 1.1. Using dot Notation (Sử dụng `.`)

- Syntax:

```
objectName.key
```

#### 1.2. Using Bracket Notation (Sử dụng `[]`)

_a. Syntax_

- Syntax:

```
objectName["propertyName"]
```

- Ví dụ:

```Javascript
// accessing property
console.log(person['name']); // John
```

- Các đối tượng đôi khi được gọi là mảng liên kết, vì mỗi thuộc tính được liên kết với giá trị chuỗi có thể được sử dụng để truy cập nó

- Thuộc tính không được chỉ định của một đối tượng là `undefined` (và không phải `null`)

_b. `[]` vs `.`_

- Tên thuộc tính đối tượng có thể là bất kỳ chuỗi JavaScript hợp lệ nào hoặc bất cứ thứ gì có thể được chuyển đổi thành một chuỗi, bao gồm một chuỗi trống. Tuy nhiên, bất kỳ tên thuộc tính nào không phải là định danh JavaScript hợp lệ đều không thể sử dụng ký hiệu DOT`.` Ví dụ: tên thuộc tính có dấu cách hoặc dấu gạch nối, bắt đầu bằng một số hoặc được giữ bên trong một biến chỉ có thể được truy cập bằng ký hiệu khung vuông`[]`.

- Ví dụ:

```Javascript
const myObj = {},
      str = 'myString',
      rand = Math.random(),
      anotherObj = {};

// Now, creating additional properties.
myObj.type              = 'Dot syntax for a key named type';
myObj['date created']   = 'This key has a space';
myObj[str]              = 'This key is in variable str';
myObj[rand]             = 'A random number is the key here';
myObj[anotherObj]       = 'This key is object anotherObj';
myObj['']               = 'This key is an empty string';

console.log(myObj);
console.log(myObj.myString);
```

- Tên thuộc tính đối tượng JavaScript (keys) chỉ có thể là các string hoặc Symbol - tất cả các keys trong `[]` được chuyển đổi thành string trừ khi chúng là Symbol. Ví dụ: trong code trên, khi key `anotherObj` được thêm vào `myObj`, JavaScript sẽ gọi phương thức `toString()` của `anotherObj` và sử dụng chuỗi kết quả làm key mới.

- Bạn cũng có thể truy cập các thuộc tính với giá trị chuỗi được lưu trữ trong một biến. Biến phải được truyền trong ký hiệu `[]`. Trong ví dụ trên, biến `str` đã giữ `"myString"` và `"myString"` là tên thuộc tính. Do đó, `myobj.str` sẽ trở lại là `undefined`

```
console.log(myObj.str); //[Log] undefined
```

---

## III. Methods & `this` keyword

### 1. Methods

- Trong JavaScript, các đối tượng cũng có thể chứa các function.
- Phương thức JavaScript là một thuộc tính chứa khai báo function. Ví dụ:

```Javascript
// accessing method and property
const person = {
    name: 'John',
    greet: function() {
        console.log('hello');
    }
};

// accessing property
person.name; // John

// accessing method
person.greet(); // hello
```

- Trong ví dụ trên, một đối tượng `Person` có hai key (`name` và `greet`), có value `string` và value `function` tương ứng.
  > Do đó, về cơ bản, phương thức JavaScript là một thuộc tính đối tượng có giá trị function.

#### 1.1. Accessing Object Methods

- Syntax

```
objectName.methodKey()
```

#### 1.2. Adding a Method to a JavaScript Object

```Javascript
// creating an object
let student = { };

// adding a property
student.name = 'John';

// adding a method
student.greet = function() {
    console.log('hello');
}

// accessing a method
student.greet(); // hello
```

### 2. `this` keyword

- Để truy cập một thuộc tính của một đối tượng từ trong một phương thức của cùng một đối tượng, bạn cần sử dụng từ khóa `this`. Ví dụ:

```Javascript
const person = {
    name: 'John',
    age: 30,

    // accessing name property by using this.name
    greet: function() {
        console.log('The name is' + ' ' + this.name);
    }
};

person.greet(); // The name is John
```

> Trong JavaScript, từ khóa `this` khi được sử dụng với phương thức của đối tượng đề cập đến đối tượng. `this` bị ràng buộc với một đối tượng.

---

## IV. Create Objects (Tạo các đối tượng)

### 1. Using object literal

- Một object literal sử dụng `{}` để tạo trực tiếp một đối tượng.
- Một đối tượng được tạo bằng một cặp khóa: giá trị.
- Bạn cũng có thể xác định các function, array và thậm chí các object bên trong một đối tượng.

```Javascript
// program to create JavaScript object using object literal
const person = {
    name: 'John',
    age: 20,
    hobbies: ['reading', 'games', 'coding'],
    greet: function() {
        console.log('Hello everyone.');
    },
    score: {
        maths: 90,
        science: 80
    }
};

console.log(typeof person); // object

// accessing the object value
console.log(person.name);
console.log(person.hobbies[0]);
person.greet();
console.log(person.score.maths);
```

### 2. By creating instance of Object directly (Bằng cách tạo trực tiếp instance của đối tượng)

- Syntax

```Javascript
const objectName = new Object();
```

- Ví dụ

```Javascript
// program to create JavaScript object using instance of an object
const person = new Object ( {
    name: 'John',
    age: 20,
    hobbies: ['reading', 'games', 'coding'],
    greet: function() {
        console.log('Hello everyone.');
    },
    score: {
        maths: 90,
        science: 80
    }
});

console.log(typeof person); // object

// accessing the object value
console.log(person.name);
console.log(person.hobbies[0]);
person.greet();
console.log(person.score.maths);
```

### 3. By using constructor function (Bằng cách sử dụng hàm tạo)

- Bạn có thể tạo một đối tượng với hai bước sau
  - 1. Xác định loại đối tượng bằng cách viết hàm tạo.
    - Để xác định loại đối tượng, hãy tạo một hàm cho loại đối tượng chỉ định tên, thuộc tính và phương thức của nó. Ví dụ:
    ```Javascript
    function Car(make, model, year) {
        this.make = make;
        this.model = model;
        this.year = year;
    }
    ```
  - 2. Tạo một instance của đối tượng với từ khoá `new`.
  ```Javascript
  const myCar = new Car('Eagle', 'Talon TSi', 1993);
  ```
- Một đối tượng có thể có một thuộc tính mà thuộc tính đó là một đối tượng khác. Ví dụ:

```Javascript
function Person(name, age, gender) {
  this.name = name;
  this.age = age;
  this.gender = gender;
}

const rand = new Person("Rand McKinnon", 33, "M");
const ken = new Person("Ken Jones", 39, "M");

function Car(make, model, year, owner) {
  this.make = make;
  this.model = model;
  this.year = year;
  this.owner = owner;

  function displayCar() {
    const result = `A Beautiful ${this.year} ${this.make} ${this.model}`;
    console.log(result);
  }
  this.displayCar = displayCar;
}

const car1 = new Car("Eagle", "Talon TSi", 1993, rand);
const car2 = new Car("Nissan", "300ZX", 1992, ken);
// console.log(car2.owner.name);
console.log(typeof car2.owner); // object
car1.displayCar(); // A Beautiful 1993 Eagle Talon TSi
```

- `this` keyword
  Trong JavaScript, khi từ `this` được sử dụng trong hàm constructor, `this` đề cập đến đối tượng khi đối tượng được tạo.

### 4. Using the `Object.create()` method

Phương thức này có thể rất hữu ích, bởi vì nó cho phép bạn chọn đối tượng prototype cho đối tượng bạn muốn tạo, mà không phải xác định hàm tạo hàm. Ví dụ:

```Javascript
// Animal properties and method encapsulation
const Animal = {
  type: 'Invertebrates', // Default value of properties
  displayType: function() {
    console.log(this.type);
  }
};

const animal1 = Object.create(Animal);
animal1.displayType(); // Invertebrates

const fish = Object.create(Animal);
fish.type = 'Fishes';
fish.displayType(); // Fishes
```

### 5. Constructor Function Vs Object Literal

- Objet Literal thường được sử dụng để tạo một đối tượng. Constructor Fuction rất hữu ích nếu bạn muốn tạo nhiều đối tượng.
- Mỗi đối tượng được tạo từ Constructor Function là duy nhất. Bạn có thể có các thuộc tính giống như hàm tạo hoặc thêm một thuộc tính mới vào một đối tượng cụ thể.
- Tuy nhiên, nếu một đối tượng được tạo bằng một object literal và nếu một biến được xác định với giá trị đối tượng đó, bất kỳ thay đổi nào trong giá trị biến sẽ thay đổi đối tượng gốc. Ví dụ:

```Javascript
// using object lateral
let person = {
    name: 'Sam'
}

console.log(person.name); // Sam

let student = person;

// changes the property of an object
student.name = 'John';

// changes the origins object property
console.log(person.name); // John
console.log(student.name); // John
```

---

## V. Prototype

- Prototype được sử dụng để cung cấp thuộc tính bổ sung cho tất cả các đối tượng được tạo từ hàm khởi tạo.
- Syntax:

```
objectConstructorName.prototype.key = 'value';
```

### 1. Prototype Inheritance

- Trong JavaScript, một prototype có thể được sử dụng để thêm các thuộc tính và phương thức vào hàm constructor. Các đối tượng kế thừa các thuộc tính và phương pháp từ một prototype. Ví dụ:

```Javascript
// constructor function
function Person () {
    this.name = 'John',
    this.age = 23
}

// creating objects
const person1 = new Person();
const person2 = new Person();

// adding property to constructor function
Person.prototype.gender = 'male';

// prototype value of Person
console.log(Person.prototype); // Person { gender: 'male' }

// inheriting the property from prototype
console.log(person1.gender); // male
console.log(person2.gender); // male
```

### 2. Changing Prototype

Nếu một giá trị prototype được thay đổi, thì tất cả các đối tượng mới sẽ có giá trị thuộc tính đã thay đổi. Tất cả các đối tượng được tạo trước đó sẽ có giá trị trước đó. Ví dụ:

```Javascript
// constructor function
function Person() {
    this.name = 'John'
}

// add a property
Person.prototype.age = 20;

// creating an object
const person1 = new Person();

// changing the property value of prototype
Person.prototype = { age: 50 }

// creating new object
const person3 = new Person();

console.log(person3.age); // 50
console.log(person1.age); // 20
```

### 3. Prototype Chaining (Chuỗi Prototype)

Nếu một đối tượng cố gắng truy cập cùng một thuộc tính có trong hàm constructor và đối tượng prototype, đối tượng sẽ lấy thuộc tính từ hàm constructor. Ví dụ:

```Javascript
function Person() {
    this.name = 'John'
}

// adding property
Person.prototype.name = 'Peter';
Person.prototype.age = 23

const person1 = new Person();

console.log(person1.name); // John
console.log(person1.age); // 23
```

---

## VI. Getter and Setter

Trong JavaScript, có hai loại thuộc tính đối tượng:

- Data properties (Thuộc tính dữ liệu). Ví dụ:

```Javascript
const student = {

    // data property
    firstName: 'Monica';
};
```

- Accessor properties (Thuộc tính của người truy cập): là các phương thức nhận hoặc đặt giá trị của một đối tượng
  - `get` keyword: Để xác định phương thức getter để lấy giá trị thuộc tính
  - `set` keyword: Để xác định phương thức setter để đặt giá trị thuộc tính

### 1. Getter

Các phương thức getter được sử dụng để truy cập các thuộc tính của object.

```Javascript
const student = {

    // data property
    firstName: 'Monica',

    // accessor property(getter)
    get getName() {
        return this.firstName;
    }
};

// accessing data property
console.log(student.firstName); // Monica

// accessing getter methods
console.log(student.getName); // Monica

// trying to access as a method
console.log(student.getName()); // error
```

### 2. Setter

Các phương thức setter được sử dụng để thay đổi các giá trị của một đối tượng.

```javascript
const student = {
  firstName: "Monica",

  //accessor property(setter)
  set changeName(newName) {
    this.firstName = newName;
  },
};

console.log(student.firstName); // Monica

// change(set) object property using a setter
student.changeName = "Sarah";

console.log(student.firstName); // Sarah
```

3. `Object.defineProperty()`
   Bạn cũng có thể sử dụng phương thức `object.defineProperty()` để thêm getters và setters.

- Syntax:

```
Object.defineProperty(objectionName, propertyName, descriptor)
```

- Ví dụ:

```javascript
const student = {
  firstName: "Monica",
};

// getting property
Object.defineProperty(student, "getName", {
  get: function () {
    return this.firstName;
  },
});

// setting property
Object.defineProperty(student, "changeName", {
  set: function (value) {
    this.firstName = value;
  },
});

console.log(student.firstName); // Monica

// changing the property value
student.changeName = "Sarah";

console.log(student.firstName); // Sarah
```

---

## VII. Built-in Objects (Đối tượng tích hợp)

### 1. Array
Một Array là một đối tượng có thể lưu trữ nhiều giá trị cùng một lúc. Ví dụ:
```javascript
const words = ['hello', 'world', 'welcome'];
```
#### 1.1. Create an Array (Tạo mảng)
- Using an array literal
- Using the new keyword (Sử dụng từ khóa `new`). Ví dụ:
```javascript
const array2 = new Array("eat", "sleep");
```
- Ví dụ khác về array:
```javascript
// array with mixed data types
const newData = ['work', 'exercise', 1, true];
```
- Bạn cũng có thể lưu trữ các mảng, function và các đối tượng khác bên trong một mảng. Ví dụ:
```javascript
const newData = [
    {'task1': 'exercise'},
    [1, 2 ,3],
    function hello() { console.log('hello')}
];
```
#### 1.2. Array Properties & Methods
```javascript
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
```
#### 1.3. Working of JavaScript Arrays 
Vì mảng là đối tượng, các phần tử mảng được lưu trữ bởi tham chiếu. Do đó, khi một giá trị mảng được sao chép, bất kỳ thay đổi nào trong mảng được sao chép cũng sẽ phản ánh trong mảng gốc. Ví dụ:
```javascript
let arr = ['h', 'e'];
let arr1 = arr;
arr1.push('l');

console.log(arr); // ["h", "e", "l"]
console.log(arr1); // ["h", "e", "l"]
```

### 2. Function
Mỗi JavaScript function thực sự là một Function object. Điều này có thể được nhìn thấy với mã (function (){}).constructor === Function, trả về true.
#### 2.1. Constructor
#### 2.2. Instance properties
#### 2.3. Instance methods


### 
