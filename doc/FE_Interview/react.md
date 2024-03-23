# 1. Create React App

- Create React App is a comfortable environment for learning React, and is the best way to `start building a new single-page application in React`.
- It sets up your development environment so that you can use the latest JavaScript features, provides a nice developer experience, and optimizes your app for production. You’ll need to have Node >= 14.0.0 and npm >= 5.6 on your machine. To create a project, run:
  > npx create-react-app my-app
  > cd my-app
  > npm start
- Create React App doesn’t handle backend logic or databases; `it just creates a frontend build pipeline`, so you can use it with any backend you want. Under the hood, it uses Babel and webpack, but you don’t need to know anything about them.

# 2. JSX

- JSX is a syntax extension to JavaScript.
- JSX produces React “elements”.
- You can put any valid JavaScript expression inside the curly braces in JSX.
- JSX is an Expression too. This means that you can use JSX inside of if statements and for loops, assign it to variables, accept it as arguments, and return it from functions:

```jsx
function getGreeting(user) {
  if (user) {
    return <h1>Hello, {formatName(user)}!</h1>;
  }
  return <h1>Hello, Stranger.</h1>;
}
```

- JSX Prevents Injection Attacks. By default, React DOM escapes any values embedded in JSX before rendering them. Thus it ensures that you can never inject anything that’s not explicitly written in your application. Everything is converted to a string before being rendered. This helps prevent XSS (cross-site-scripting) attacks.

# 3. Components

- Components let you split the UI into independent, reusable pieces, and think about each piece in isolation.
- Conceptually, `components are like JavaScript functions`. They accept arbitrary inputs (called “props”) and return React elements describing what should appear on the screen.

## 3.1. Function Components

## 3.2. Class Components

## 3.3. Converting a Function to a Class

```jsx
function Clock(props) {
  return (
    <div>
      <h1>Hello, world!</h1>
      <h2>It is {props.date.toLocaleTimeString()}.</h2>
    </div>
  );
}
```

1. Create an ES6 class, with the same name, that extends `React.Component`.
2. Add a single empty method to it called `render()`.
3. Move the body of the function into the `render()` method.
4. Replace `props` with `this.props` in the `render()` body.
5. Delete the remaining empty function declaration.

```jsx
class Clock extends React.Component {
  render() {
    return (
      <div>
        <h1>Hello, world!</h1>
        <h2>It is {this.props.date.toLocaleTimeString()}.</h2>
      </div>
    );
  }
}
```

# 4. Props vs State

## 4.1. Props

- `Props are read only`
- Whether you declare a component as a function or a class, it must never modify its own props. Such functions are called “pure” because they do not attempt to change their inputs, and always return the same result for the same inputs.
- `All React components must act like pure functions` with respect to their props.

## 4.2. State

- State is similar to props, but it is private and fully controlled by the component.
- Using State Correctly
    - Do Not Modify State Directly
    - State Updates May Be Asynchronous
    - State Updates are Merged

## 4.3. Comparision
- props are passed into the component
- props can come from the parent, or can be set by the component itself.
- props should not change: During a component’s life cycle props should not change (consider them immutable).

# 5. Component LifeCycle

- In applications with many components, it’s very important to free up resources taken by the components when they are destroyed.
- We want to set up a timer whenever the Clock is rendered to the DOM for the first time. This is called `“mounting”` in React. 
    - The `componentDidMount()` `method runs after the component output has been rendered to the DOM`. This is a good place to set up a timer:

```jsx
  componentDidMount() {
    this.timerID = setInterval(
      () => this.tick(),
      1000
    );
  }
```

- We also want to clear that timer whenever the DOM produced by the Clock is removed. This is called `“unmounting”` in React.
  - We will tear down the timer in the `componentWillUnmount()` lifecycle method:

```jsx
 componentWillUnmount() {
    clearInterval(this.timerID);
  }
```

- These methods are called “lifecycle methods”.