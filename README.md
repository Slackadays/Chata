<h1>Welcome to the Chata programming language</h1>

Chata is an idea for a programming language that's just for DSP, or Digital Signal Processing. 

Chata gets rid of all the junk and cruft associated with DSP, letting you do great things easier than ever.

# Important Update!

It's been months since I last touched Chata. Since then, I've been wondering if it is even a good idea in the first place. 

Consider this: A language that's like RISC-V assembly is reinventing the wheel. I'm placing a bet that in the long term (say, 30 years), everything will become RISC-V, making a language similar to it that can run on other platforms redundant.

Therefore, why not just base Chata off of assembly directly? We can borrow a subset of RISC-V simply, expand it with constructions for convenience, and provide a runtime that you can emulate on other platforms. That's the new idea going forward.

> [!NOTE]
> <a href="README-old.md">Click here for the README for Old Chata.</a>

# The Problem 😕

### What is DSP anyway?

Tons of things today use DSP, or Digital Signal Processing, to make them work. 

Take your wireless noise cancelling headphones for example. They're using DSP right now to beam that wireless signal and cancel that noise. 

My guitar pedal with zillions of effects uses a special DSP processor to create them all.

But how do you even get to this point?

 ### Enter the clown world of DSP programming.

Current DSP processors often require bespoke tools to work with them. For example, take [SigmaStudio](https://www.analog.com/en/design-center/evaluation-hardware-and-software/software/ss_sigst_02.html).

If you just want to type code instead, then you're dealing with more bespoke SDKs, APIs, and other fun things.

What about running DSP on a regular computer instead? At least you don't have to deal with closed-source, visual tools, but now you've got even more bespoke libraries to deal with.

Is there a way out?

### Enter Chata.

The goal of Chata is to be the _dedicated_ way to do great things with DSP. To get really creative, imagine a one-two punch of an open road where your mind can run full speed with a language that lets you express your ideas, and a powerful ecosystem to put those ideas to work.

**Sound interesting? Read on.**

# How It Works :eyes:

Chata builds off of a subset of RISC-V assembly. In case you don't know, RISC-V is a new kind of computer _instruction set architecture_ that defines the raw instructions that you computer runs. We use this low-level language because DSP mainly performs low-level operations on raw data, and this saves us a lot of time and effort.

But if you're cringing at the thought of writing assembly, fear not. Chata will include a vast standard library with all the classic DSP goodies like filters, transforms, and the like. Plus, since we can take creative license, Chata will have a lot of helpers that make it feel more like other programming languages you might be used to already.

Finally, we put all this together with...