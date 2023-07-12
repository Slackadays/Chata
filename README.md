# Chata

<h1 align="center">The (future) best way to smash those signals.</h1>

Chata is a programming language that's made just for DSP, or Digital Signal Processing. 

Chata aims to let you do _awesome_ things by getting rid of all the junk associated with other kinds of DSP programming.

# The Problem 😕

Tons of awesome things today use Digital Signal Processing to make them work. 

Take your wireless noise cancelling headphones for example. They're using DSP right now to beam that wireless signal and cancel that noise. My guitar pedal with zillions of different effects hinges on a special DSP processor to make them all.

However, how do you even do this in the first place? 

**Enter the clown world of DSP programming.**

If you want to process signals straight up, all you need is to write some code in a plain old programming language, and you're done! But what if you want to make it an audio plugin? Now, you're married to some cookie cutter tool that gives you a functional plugin, and hopefully you're done. What if you want to use one of those fancy-schmancy DSP processors? Say hello to special snowflake systems and highway robbery pricing. 

Is there a way out?

**Enter Chata.**

I want to make Chata the most _fun_ and _awesome_ way to do DSP. Imagine a one-two punch of _fun_ by letting your mind go wild with a language that lets you express your ideas, and _awesome_ by having a powerful ecosystem to put those ideas to work.

# How It Works :eyes:

Chata doesn't actually exist yet. 

Instead, I want to make a language specification that's as polished as it can be. Once the specification is ready, then we can start making it real. 

Here's some of my goals for Chata:
- a superb standard library with fancy algorithms such as IIR, Hilbert Transform, and more
- an imperative syntax with clear actions
- full math symbol support because DSP is all about math!
- a build system that lets you make different plugins for any valid program
- great support for DSP applications like RF and not just audio
- support for compiling to DSP processor targets

The specification will be in this repository on GitHub with some example programs to see if it works out or not. We're in this journey together!

# The Competition 🥇

There's already a similar thing called [SOUL](https://github.com/soul-lang/SOUL), or SOUnd Language. However, SOUL doesn't even come close to Chata for these reasons:
- SOUL isn't free and open source. The "secret sauce" is still opaque and closed source.
- SOUL is just for audio. Chata, on the other hand, is for all kinds of DSP!
- SOUL has tons of boilerplate. I couldn't read the example programs provided there.
- SOUL is basically abandoned now, because the company behind it went bankrupt, down the drain, more imploded than the Titan submarine.

Other than that, the competition doesn't look good. Therefore, we'll be competing only with ourselves to make the best DSP language out there.

# For Nerds Only 🤓

Right now, Chata is mostly an imperative language with functional aspects. Its syntax looks mildly similar to
