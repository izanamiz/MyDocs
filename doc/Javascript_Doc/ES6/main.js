/*------------------Destructuring---------------*/
const note = {
    id: 1,
    website: 'anonystick.com',
    date: '17/07/2014',
}
// Destructure properties into variables
const { id, website, date: otherName } = note
// console.log(id)
// console.log(website)
// console.log(otherName)

const date = ['2014', '17', '07']
// Destructure Array values into variables
// const [year, month, day] = date

// console.log(year) 
// console.log(month)
// console.log(day) 


/*------------------Rest parameters---------------*/
const [a, ...rest] = date
// console.log(a)
// console.log(rest)

const { id: ID, ...newObject } = note
// console.log(ID)
// console.log(newObject)

function logger(...params) { // -> rest
    console.log(params)
}
// logger(1, 2, 3, 4, 5, 6, 7)

/*------------------Spread---------------*/
const tools = ['hammer', 'screwdriver']
const otherTools = ['wrench', 'saw']

// Unpack the tools Array into the allTools Array
// const allTools = [...tools, ...otherTools]
// console.log(allTools)

const obj = {
    a: {
        c: 3
    },
    b: 2
}

const obj2 = {
    ...obj,
    a: {
        c: 42
    }
}
// console.log(obj2)

const arr = [1, 2, 3]
function myFunc(a, b, c) {
    console.log(a, b, c)
}
myFunc(...arr) // -> spread

/* rest vs spread
- ... khi dùng với destructuring là toán tử rest
- ... khi định nghĩa params là toán tử rest
- ... khi gọi đến hàm truyền đối số là spread
*/
