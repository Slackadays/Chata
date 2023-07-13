# Chata

<h1 align="center">The (future) way to smash those signals.</h1>

Chata is a programming language that's made just for DSP, or Digital Signal Processing. 

Chata aims to let you do awesome things like music effects and super fast communication by getting rid of all the junk associated with other kinds of DSP programming.

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

Here's some of my goals for Chata:
- a superb standard library with fancy algorithms such as IIR, Hilbert Transform, and more
- an action-oriented syntax with clear verbage
- full math symbol support because DSP is all about math!
- a build system that lets you make different plugins for any valid Chata program
- great support for DSP applications like RF and not just audio
- support for compiling to DSP chip targets

The standard will be in this repository right here on GitHub.

We'll figure out what it should look like and see if we can write some example programs that solve common problems. We're in this journey together!

# The Competition 🥇

There's already a similar thing called [SOUL](https://github.com/soul-lang/SOUL), or SOUnd Language. SOUL doesn't even come close to Chata:
- SOUL isn't free and open source. The "secret sauce" is still opaque and closed source.
- SOUL is just for audio. Chata, on the other hand, is for all kinds of DSP!
- SOUL has tons of junk boilerplate. I couldn't read the example programs provided there.
- SOUL is selling the implementation, not the end result. This limits SOUL's audience a lot.
- SOUL is abandoned now, because the company behind it went bankrupt, down the drain, more imploded than the Titan submarine.

Other than that, the competition doesn't look good. Therefore, we'll be competing only with ourselves to make the best DSP language out there.

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
  - [ ] basic working interpreter
    - [ ] what language?
    - [ ] at what standard should it be built?
  - [ ] a JIT/faster interpreter
  - [ ] code generator
    - [ ] what languages?
  - [ ] native binary generator
    - [ ] what ISAs?
    - [ ] what platforms?
- [ ] Documentation
  - [x] readme with basic details
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

## Chata Programs

# Examples :hammer:

## Sine Wave

## High Pass Filter

## Low Pass Filter

## Delay

## Reverb
