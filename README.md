<h1 align="center">xva</h1>

<div align="center">
  <i>ˈk(w)iːvə, QUEE-va, like the Irish name Caoimhe</i>
</div>
<br/>
<div align="center">
    <img src="https://img.shields.io/github/workflow/status/xva-lang/xva/Build" alt="Build status"/>
    <img src="https://img.shields.io/github/checks-status/xva-lang/xva/main" alt="Checks status"/>
    <img src="https://img.shields.io/badge/stability-experiemental-orange" alt="Stability"/>
</div>
<div align="center">
  <h2>The Xva programming language</h2>
</div>




Xva is an interpreted, statically typed programming language, designed to be small, fast, and allow for rapid prototyping. Its syntax is beginner friendly, but also exposes many common and powerful features found in other languages.

Xva started out with me wanting a "playground" to research all sorts of interesting bits and bobs in the world of programming. I thought that reading about programming constructs wasn't enough, I wanted to **do** something with it. As such, Xva borrows lots of things from a variety of languages, both those that I use in a professional context as well as those I am interested in for my own benefit.

Xva is still extremely experimental. I am always open to new ideas and contributions and I am by no means an expert programmer, so if you feel like adding something, please go right ahead and make a fork!

## What can Xva do?

See for yourself! Here's an example Xva program, demonstrating a few bits and pieces.

`main.xva`

```xva
// Xva is statically typed - all variables must have a type, and variables cannot change their types.
let number: int = 1;

// Xva automatically makes variables immutable, so you can't re-assign another value to them.
// If you do want to re-assign something to a variable, you have to declare it as mutable:
let changeableNumber: mutable float = 1.24
changeableNumber = 2.48

// You can also let Xva "figure out" the type of a variable, based on its initial assignment.
let stringVariable = "Xva can do implicit typing!"

// Xva allows you to declare functions in multiple ways.
// You can declare a "traditional" function, with a start and end
def sayHello(): void
    print("Hello, Xva!)
end

// Or, you could be a little fancier and bind an anonymous function to a name:
let sayHelloThreeTimes = def (): void
    print("Hello, world!)
    print("Hello, world!)
    print("Hello, world!)
end

// You can get even fancier with a lambda expression:
let oneLiner = def () => print("Hello, world!")

// And just in case you thought you couldn't get any fancier, functions in Xva are
// first-class - you can lob them around any way you like!
functionThatCallsAFunction(def () => print("I should get called!"))


let xvaIsSuperCool = true
// (Xva knows that it's super cool - it doesn't need a variable for that 😉)

if xvaIsSuperCool
    print("You're right! Xva IS super cool!")
else
    print("This is impossible! Xva is super cool!")
end

```
