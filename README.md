<h1 align="center">Chata</h1>

<h1 align="center">The <sub><sup>(future)</sup></sub> magic wand 🪄 for signal processing.</h1>

Chata is a programming language that's made just for DSP, or Digital Signal Processing. 

Chata aims to let you do awesome things like music effects and accelerated number crunching by getting rid of all the junk associated with this kind of programming.

# The Problem 😕

**What is DSP anyway?**

Tons of things today use DSP, or Digital Signal Processing, to make them work. 

Take your wireless noise cancelling headphones for example. They're using DSP right now to beam that wireless signal and cancel that noise. My guitar pedal with zillions of different effects uses a special DSP processor to make them all.

However, how do you even get to this point?

**Enter the clown world of DSP programming.**

If you want to process signals straight up, all you need is to write some code in a plain old programming language, and you're done! But what if you want to make it an audio plugin? Now, you're married to some cookie cutter tool that gives you a functional plugin, and hopefully you're done. What if you want to use one of those fancy-schmancy DSP processors? Say hello to special snowflake systems and highway robbery pricing. 

Is there a way out?

**Enter Chata.**

I want to make Chata the most _awesome_ way to do great things with DSP. Imagine a one-two punch of an open road where your mind can run full speed with a language that lets you express your ideas, and a powerful ecosystem to put those ideas to work.

# How It Works :eyes:

**Chata doesn't actually exist yet.**

First, I want to write a standard that's as polished as it can be. Then, once the standard is ready, we can start making it real. 

The reason for doing this is because I think it's sometimes better to know what you want to achieve first and then work towards that _actionable_ goal rather than working towards something and making up the goal along the way. 

Here's some of my goals for Chata:
- a superb standard library with fancy algorithms such as IIR, Hilbert Transform, and more
- an action-oriented syntax with clear verbage
- full math symbol support because DSP is all about math!
- a build system that lets you make different plugins for any valid Chata program
- great support for DSP applications like RF and not just audio
- support for compiling to DSP chip targets

The standard will be in this repository right here on GitHub. :octocat:

We'll figure out what it should look like and see if we can write some example programs that solve common problems. 

**We're all in this journey together!**

<p align="center"><a href="https://discord.gg/J6asnc3pEG"><img src="DiscordBanner.png" height="80px"></a></p>

# Motivation 🎸

I think ba**chata** music, especially the guitar part, is the coolest thing ever. If you don't know what that is, do an internet search for the band featured on my GitHub profile and you'll find out. (Hint: Aventura is the best!)

To make the "classic" ba**chata** guitar sound, you need four audio effects: high-pass EQ, compression, 20ms-delay stereo chorus, and reverb, in that order. Unfortunately, unless you want to lug around a bunch of heavy guitar pedals, a laptop, or a vintage Ibanez PT-4 from the 1990s, a DSP "multi-effects processor" is the only practical option. Also unfortunately, researching how these DSP things work revealed how sorry of a state the professional audio industry is regarding free and open-source software. 

So, why not just make the solution?

# The Competition 🥇

There's already a similar thing called [SOUL](https://github.com/soul-lang/SOUL), or SOUnd Language. SOUL doesn't even come close to Chata:
- SOUL isn't free and open source. The "secret sauce" is still opaque and closed source.
- SOUL is just for audio. Chata, on the other hand, is for all kinds of DSP!
- SOUL has tons of junk boilerplate. I couldn't read the example programs provided there.
- SOUL is selling the implementation, not the end result. This limits SOUL's audience a lot.
- SOUL is abandoned now, because the company behind it went bankrupt, down the drain, more imploded than the gamepad-controlled Titan submarine.

And there's now a followup called [Cmajor](https://github.com/SoundStacks/cmajor)! Cmajor still doesn't even come close to Chata:
- Cmajor STILL isn't free and open source. The tools provided as binaries are still opaque and closed source.
- Cmajor still is focused on audio, while Chata is for all DSP.
- Cmajor looks better regarding boilerplate, but still could do even better.
- Cmajor's readme leaves a lot to be desired because there's almost no information on it.
- Cmajor is STILL owned by some company which could go bust like Apollo 13.

There's also something else called [Faust](https://github.com/grame-cncm/faust)! Faust STILL doesn't even come close to Chata:
- Faust puts all of its eggs into functional programming. Chata, on the other hand, is imperative, which is better if that's what you're interested in.
- Faust is "block-diagram oriented." Chata, on the other hand, lacks any concept of block diagrams, which is better if you don't want them.
- Faust is always "fully compiled" with zero interpretation. Chata, on the other hand, is more flexible here because it doesn't specify either.
- Faust relies on bespoke symbol characters like `:`, `,`, `~`, `<:`, and `:>`. With only a couple exceptions, Chata's non-text symbols, on the other hand, are standard mathematical symbols that aren't specific to one language, neither Human nor programming.
- Faust can't combine multiple files into one program, and you have to specify boilerplate metadata within every code file. Chata, C, C++, Rust all have the ability to atomically combine separate files into one, with metadata specified in one place, baked right into the languages themselves. Examples: Rust and Cargo, C/C++ and CMake, and whatever Chata will have.

Something that's common to all of these other options is that there is only one toolchain available for each one. This leads to a monoculture, which means that all projects using it depend on one toolchain to work. Additionally, noncompliant behavior from a single toolchain influences the standard by becoming what projects experience, which isn't good if you're interested in language standardization. Other languages like C, C++, Rust, and Go don't suffer from this. An example is with C++'s "big three" of GCC, Clang, and MSVC. Therefore, it's in our best interest that Chata never becomes a monoculture by making sure multiple toolchains are available.

Other than that, the competition doesn't look good. Therefore, we'll be competing only with ourselves to make the best DSP language out there.

# Contributing :heart:

If you want to help out, feel free to do so! I want Chata to be something that everyone can feel good about because it listens to them.

**`How To Help`** The fastest way to help out is by joining our Discord server above :point_up:. After that, if you see something that you want to change, go fork this repo and make those changes. Then, we'll see if they can be integrated.

# Roadmap 🗺️

- [ ] Chata Language Standard
  - [ ] basic ideas for a general look
    - [ ] what should it look like?
    - [ ] what kinds of looks are feasible?
    - [ ] how nice can it look?
  - [ ] syntax
    - [ ] procedural, functional, imperative?
    - [ ] how should "stuff" work?
  - [ ] names
    - [ ] what kind of capitalization?
    - [ ] what abbreviations should we use?
  - [ ] math symbols
    - [ ] what symbols can we support?
    - [ ] can we seamlessly integrate math symbols into the code?
  - [ ] standard library
    - [ ] what features can we include?
    - [ ] how should we implement the library?
  - [ ] concurrency
    - [ ] how can we determine concurrency support?
  - [ ] platform support
    - [ ] how can we support DSP processors?
    - [ ] what ISAs should we support?
    - [ ] should we use something like LLVM IR?
  - [ ] multi-language support
    - [ ] should we support multiple languages?
- [ ] Official Implementation
  - [x] license
  - [ ] basic working interpreter
    - [ ] what language?
    - [ ] at what standard should it be built?
  - [ ] a JIT/faster interpreter
  - [ ] code generator
    - [ ] what languages?
  - [ ] native binary generator
    - [ ] what ISAs?
    - [ ] what platforms?
- [ ] Alternative Implementation
  - [ ] who will make it?
  - [ ] license
  - [ ] what language?
- [ ] Documentation
  - [x] readme with basic details
  - [ ] Chata logo
  - [ ] sample programs
    - [ ] "hello world" (sine wave)
    - [ ] delay
    - [ ] EQ
    - [ ] reverb
  - [ ] website
  - [ ] online playground
- [ ] Your checkbox here!
  - [ ] Feel free to contribute to this roadmap!

# The Standard 📜

## Definitions

### Chata Programs

A Chata implementation is any software that follows the Chata standard.

An action is a collection of symbols defined within the Chata specification and arranged in a valid way, that either the Chata implementation can abstract or that other actions can access.

**`Note`** An action is like a function in regular programming languages, but because functions in Chata have a slightly different way of working, they're called actions instead.

A Chata program is at least one action with name "main."

A Chata program file is a text file that contains only text encoded in UTF-8 format, and that end in a `.chata` extension, and that contains a valid Chata program.

A symbol is the name of an action, function, variable, or other component of a Chata program that the code refers to by a Human-readable string of valid characters.

A statement is a combination of symbols that fits on one line.

A scope is the part of a Chata program in which code within the part can access variables.

A variable is named container of data of a specific type.

A namespace is a way to abstract variables within a single name.

## General Requirements

All symbols must contain only the following classes of text characters:

- any Latin script character
- any of these symbols: _ (underscore), - (dash), + (plus)
- any Greek alphabet letter

Variable names must not be a symbol already used by a Chata implementation.

All statements must end with an ASCII line feed character or an ASCII carriage return character followed by an ASCII line feed character.

**`Note`** This means that either `\n` or `\r\n` can delimit lines.

## Variable Types

There are these variable types in Chata:

### signal

The `signal` type is a floating-point number with range -1.0 to 1.0 and at least 32 bits of precision.

### int

The `int` type is a signed integer with at least 32 bits of precision.

## Number Overflow

If adding a value to a type where the result exceeds the type's maximum capacity in either the positive or negative direction, the type must remain at its previous value.

**`Note`** This means that if you add 1 to an `int` at value 2^31, it will stay at 2^31. This is also called "saturating" a value.

## Actions

All actions start with the keyword `action` followed by the name of the action, followed by an opening curly bracket, Chata code, and closing curly bracket.

**`Example`**
```
action main {
  foobar
}
```

Actions may specify which variables that they can access directly in the format `action action-name, 1st-variable-type 1st-variable-name {code}`. To provide multiple variables, use the format `action action-name, 1st-variable-type 1st-variable-name, 2nd-variable-type 2nd-variable-name {code}`.

**`Example`** An action that accepts a variable called `in1` of type `signal` and another of name `count` of type `int` can look like `action main, signal in1, int count {}`.

## Variable Creation

Variable names must not start with a number.

You can create a variable by declaring it in the format `variable-type variable-name`.

**`Example`** Declare a signal variable of name `foo` with `signal foo`:

```
action main {
  signal foo
}
```

All variables which do not depend on other variables contain the value 0 by default.

To create a variable that matches the value of a different variable, declare it with `variable-type variable-name = target-variable-name`. Chata implementations must only copy the value held by `target-variable-name` into `variable-name`.

## Math Symbol Support

Chata supports all standard math symbols like +, -, *, /, <, >, <= (alias for ≤), => (alias for ≥), != (alias for ≠), =, ||, and ^.

Chata supports mathematical constants like pi (alias for π), e, and i.

Chata supports mathematical functions like sqrt() (alias for √()), sin(), cos(), tan(), sec(), csc(), cot(), sinh(), cosh(), and tanh().

Chata supports standard mathematical syntax such as 5pi (alias for 5π) and 2 + 1.2sin(e)√(5), and (foovariable)sin(1)

Chata supports different mathematical order of operations, but PEMDAS is the default.

All trigonometric functions must use radians for angle units.

**`Note`** This means that you can effortlessly do math on variables as if you were in a math class.

**`Example`**
```
action main, signal in {
  signal foo = 2πin
}
```

## Using Actions

To use an action, use the format `action-name 1st-operand, 2nd-operand, ...`.

**`Example`**
```
action doSomething, signal one, signal two {
  signal three = one + two
}
action main, signal in, signal in2 {
  doSomething in, in2
}
```

## Built-In Actions

Chata provides several built-in actions that all implementations must include.

### set

`set target, value, ...`

Set a variable to one or more values.

**`Example`**
```
int foo
set foo, 100, 69, 420, 42
// result: foo is 42
```

### add

`add target, value, ...`

Add one or more values to a variable.

**`Example`**
```
int foo
add foo, 1
// result: foo is 1
add foo, 100, 50
// result: foo is 151
```

### mul

`mul target, value, ...`

Multiply one or more values with a variable.

**`Example`**
```
int foo
mul foo, 10000000
// result: foo is 0
add foo, 5
mul foo, 100, 1, 5
// result: foo is 2500
```

### sub

`sub target, value, ...`

Subtract one or more values from a variable.

**`Example`**
```
int foo = 100
sub foo, 10
// result: foo is 90
sub foo, foo - 50, 1
// result: foo is 49
```

### setif

Set a variable to one or more values if a condition is true.

`setif condition, target, value, ...`

**`Example`**
```
int foo = 100
sub foo, 50
setif foo = 50, foo, 10
// result: foo is 10
```

**`Note`** `setif` exists to provide an easy way to do predicated actions on variables as is commonly done in DSPs.

### addif 

Add one or more values to a variable if a condition is true.

`addif condition, target, value, ...`

**`Example`**
```
int foo = 100
sub foo, 50
addif foo = 50, foo, 10
// result: foo is 60
```

### subif 

Subtract one or more values from a variable if a condition is true.

`subif condition, target, value, ...`

**`Example`**
```
int foo = 100
sub foo, 50
subif foo = 50, foo, 10
// result: foo is 40
```

### mulif

Multiply one or more values with a variable if a condition is true.

`mulif condition, target, value, ...`

**`Example`**
```
int foo = 100
sub foo, 50
mulif foo = 50, foo, 10
// result: foo is 500
```

## Scopes

All Chata programs have a global scope where all actions within the program can access any variables declared in it.

Within an action, only code within the action and other actions created within it can access variables created in that action.

Only code following the creation of a variable may access that variable.

## Comments

Chata implementations must not interpret code comments as code.

Code comments can start anywhere.

Code comments which span a single line start with the characters `//`.

Code comments which can span multiple lines start with the character `#` and end with the character `#`.

**`Note`** The reason for using `#` for multi-line comments was so that you don't have to type more characters compared to a single-line comment.

## Namespaces

A namespace may contain one or more variables and/or namespaces under a single name. For example, the `foo` namespace may contain the variables `bar` and `baz`. 

You can access variables or namespaces within a namespace in Chata in the format `namespace:content`. For example, to access the `bar` variable within `foo`, use `foo:bar`.

To create a namespace, use the format `namespace namespace-name {content}`. `content` is lines of variable or namespace declarations.

**`Example`**
```
signal someGlobalVar
namespace foo {
  signal bar
  int baz
}
#namespace junk {
  blah var
}#
action main, signal in {
  // make a copy of foo:bar
  signal bat = foo:bar
  set foo:baz, someGlobalVar
}
```

**`Note`** Here's the equivalent code but in C++:
```cpp
float someGlobalVar;
namespace foo {
  float bar;
  int baz;
}
/*namespace junk {
  blah var
}*/
int main(float& in) { //note that you can't actually do this in C++!
  // make a copy of foo:bar
  float bat = foo::bar;
  foo::baz = someGlobalVar + bat
}
```

## Special Global Variables

Chata provides several global variables that are always present in all Chata programs.

### Sample Rate

This variable of type `int` represents the current sample rate of the Chata implementation in Hertz. If the Chata implementation does not have a set sample rate, the value is 0.

Access the sample rate with `std:SampleRate`.

**`Example`**
```
action main {
  int foo = std:SampleRate
}

```

# Examples :hammer:

## Sine Wave

```
action main, signal in1 {
  int hertz = 440
  int samplesPerCycle = std:SampleRate / hertz
  int cycles
  set in1, sin(2πcycles/samplesPerCycle)
  add cycles, 1
}
```

issues:
- won't exactly be 440 hertz because there is not enough precision when dividing ints
- `cycles` will eventually saturate which leads to no more signals getting made

## High Pass Filter

## Low Pass Filter

## Delay

## Reverb
