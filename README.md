<h1>Welcome to the Chata programming language</h1>

Chata is an idea for a programming language that's just for DSP, or Digital Signal Processing.

There's no junk or cruft with Chata, so it lets you do great things easier than ever!

# October 2024: Important Update

It's been months since I last touched this project because I wasn't feeling good vibes from it.

Consider this: A language that's like RISC-V assembly (the way Old Chata worked) is reinventing the wheel. I'm placing a bet that in the long term (say, 30 years), everything will become RISC-V, making a language similar to it that can run on other platforms redundant.

Therefore, why not just base Chata off of assembly directly? We can borrow a subset of RISC-V simply, expand it with convenient building blocks, and provide a runtime emulatable on other platforms too. That's the new idea going forward.

> [!NOTE]
> <a href="readme/README-old.md">Click here for Old Chata's README.</a>

# 😕 The problem (and the solution)

### What is DSP anyway?

Tons of things today use DSP, or Digital Signal Processing, to make them work. 

Take your wireless noise cancelling headphones for example. They're using DSP right now to beam that wireless signal and cancel that noise. 

But how do you even get to this point?

### 🤡 Enter the clown world of DSP programming.

Current DSP processors often require bespoke tools to work with them. For example, take [SigmaStudio](https://www.analog.com/en/design-center/evaluation-hardware-and-software/software/ss_sigst_02.html), a proprietary thing for everything to do with AD's DSPs.

If you just want to simply type code instead like you really want to do, then you're dealing with more bespoke SDKs, APIs, and other (not so) fun things.

Is there a way out?

### Enter Chata.

The goal of Chata is to be the best way to do great things with DSP. 

In marketing speak, imagine a one-two punch of an open road where your mind can run full speed with a language that lets you express your ideas, and a powerful ecosystem to put those ideas to work.

**Sound interesting? Read on.**

# :screwdriver: How it works

Chata builds off of a subset of RISC-V assembly. In case you don't know, RISC-V is a new kind of computer "instruction set architecture" (ISA) that defines the raw code that your computer runs. We'll use this low-level language because DSP mainly performs low-level operations on raw data, and this saves us a lot of time and effort.

But if you're scared of the idea of writing assembly, fear not. Chata will include a vast standard library with all the classic DSP goodies like filters, transforms, and the like. Plus, since we can take creative license, Chata will have a lot of helpers that make it feel more like other programming languages you might be used to already.

Finally, we put all this together with a complete toolchain so you can put DSP to use.

<details><summary><b>Ok, but why use assembly for a new programming language?</b></summary>

Consider this: I'm making a few assumptions with the Chata project. They are:

- that everything will eventually become RISC-V
- that in the meantime, emulation is fast enough for most purposes
- that high-level language features will not be needed
- that we need low-level control over data transformation
- that we can't waste any time or effort
- that all parts will be free and open-source
- that natively usable hardware exists
- that Chata programs will be completely portable between platforms

With those assumptions, a customized RISC-V assembly is a clear choice. Alternatives such as assembly for other platforms won't cut it as they are either all proprietary (x86, ARM, MIPS, and others fail the freedom constraint) or are unavailable in practical hardware (OpenRISC). Higher level languages where Chata is merely a DSP library won't cut it either, but for a couple reasons that aren't obvious. Also consider this:

- C, C++, and other compiled languages work on "all" platforms. However, subtle differences exist, such as `char` in C sometimes being signed and other times unsigned. Do you know what it is on your system? Either way, fixing this would require adding type definitions, which perhaps makes this a minor annoyance.
- Here's a potential scenario. Imagine you're writing a program and you want to optimize it to use vectors. Unfortunately, since you're not using assembly, you need to use "vector intrinsics" for your platform and your platform only. Now assume you include these. Now your optimization is valid only for your platform out of many others. On one hand, this same problem exists in assembly too. On the other hand, vector intrinsics are different for all platforms, so if your code had instead targeted RISC-V only, it would work on all platforms in the long run and still be emulatable in the meantime.
- Building off of a higher-level language entails a certain amount of backwards compatibility. However, these languages often have breaking changes. Chata aims to remain backward-compatible in the long term, say 30 years. This means the underlying language would need to retain backwards compatibility for 30 years. While examples of this exist like ANSI C, we can't guarantee it. On the other hand, one of RISC-V's goals is retain this backwards compatibility for as long as possible. 

</details>

# ⚖️ Chata compared

<details><summary>Click here to see a comparison between this and a bunch of other DSP languages.</summary>

There's already a similar thing called [SOUL](https://github.com/soul-lang/SOUL), or SOUnd Language.
- SOUL isn't free and open source. The "secret sauce" is still opaque and closed source.
- SOUL is just for audio. Chata, on the other hand, is for all kinds of DSP!
- SOUL has tons of junk boilerplate. I couldn't read the example programs provided there.
- SOUL is abandoned now, because the company behind it went bankrupt, down the drain, more imploded than the gamepad-controlled Titan submarine.

And there's now a followup called [Cmajor](https://github.com/SoundStacks/cmajor)!
- Cmajor STILL isn't free and open source. The tools provided as binaries are still opaque and closed source.
- Cmajor still is focused on audio, while Chata is for all DSP.
- Cmajor looks better regarding boilerplate, but still could do even better.
- Cmajor is STILL owned by some company which could implode like the Titan submarine.

There's also something else called [Faust](https://github.com/grame-cncm/faust).
- Faust puts all of its eggs into functional programming. Chata, on the other hand, works like most regular languages.
- Faust is "block-diagram oriented." Chata, on the other hand, lacks any concept of block diagrams, which is better if you don't want them.
- Faust is always "fully compiled" with zero interpretation. With Chata, you could do either.
- Faust relies on bespoke symbol characters like `:`, `,`, `~`, `<:`, and `:>`, which is hard to learn.
- Faust can't combine multiple files into one program, and you have to specify boilerplate metadata within every code file. Chata, C, C++, Rust all have the ability to atomically combine separate files into one, with metadata specified in one place, baked right into the languages themselves. Examples: Rust and Cargo, C/C++ and CMake, and whatever Chata will have.

How about something called [Glicol](https://github.com/chaosprint/glicol)?
- Glicol claims to be a "graph-oriented live coding language". However, Chata does not contain any graphs at all in the language.
- Glicol also seems to be oriented around audio synthesis. However, Chata is for generic DSP, where audio generation is a mere bonus.
- Glicol is also functional which Chata is not.

Introducing yet another competitor: [Extempore](https://github.com/digego/extempore)!
- Extempore looks like one of those functional lisps. However, Chata is neither of those.
- Extempore is yet another DSP language oriented toward music. However, again, Chata is for generic DSP with music as an application of that.
- Extempore does not use a certified FOSS license. However, Chata uses the high-quality Mozilla Public License.

Let's finish this comparison off with [Mimium](https://github.com/mimium-org/mimium):
- Mimium claims that it's "for sound and music". Chata, yet again, is just generic DSP, with sound and music mere bonuses.
- Mimium code actually looks similar to Chata code. However, it lacks some features such as more advanced math due to being only for sound and music.

</details>

# :heart: Contribute

Like with my other projects, I'm accepting any contributions you might want to make!

# 🗺️ Roadmap

<details><summary>Click here to see the roadmap</summary>

- [ ] Chata Language Standard
  - [ ] basic ideas for a general look
    - [ ] what should it look like?
    - [ ] what kinds of looks are feasible?
    - [ ] how nice can it look?
  - [ ] types
    - [ ] int types
    - [ ] float types
    - [ ] buffer (array) types
    - [ ] other types?
  - [ ] versioning
  - [ ] syntax
    - [x] procedural, functional, imperative?
    - [ ] how should "stuff" work?
    - [ ] generics/templates
  - [ ] IO
    - [x] ~~in != out IO~~
  - [ ] names
    - [x] what kind of capitalization? **Follow RISC-V**
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
  - [x] license **MPL 2.0**
  - [ ] basic working interpreter
    - [ ] what language?
    - [ ] at what standard should it be built?
  - [x] ~~a JIT/faster interpreter~~ 
  - [x] ~~code generator~~
    - [x] what languages? **RISC-V**
  - [ ] native binary generator
    - [ ] what ISAs?
    - [ ] what platforms?
- [ ] Alternative Implementation
  - [ ] who will make it?
  - [ ] license
  - [ ] what language?
- [ ] Documentation
  - [x] readme with basic details **Right here**
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

</details>

# 🖥️ Chata language standard

## Definitions

"RISC-V assembly" is the Unprivileged ISA standard defined by https://github.com/riscv/riscv-isa-manual/releases/tag/20240411.

An alias is a way to represent RISC-V assembly code with a different syntax.

## Program structure

All Chata programs' code must be in files ending with the `.chata` file extension.

Chata programs must not include Privileged assembly instructions or these Unprivileged ones:

- `scall`
- `ecall`

## Input/Output

### Channel mapping

One common application of DSP is in audio. However, not all DSP applications are audio. To ensure Chata works with both audio and non-audio applications, we need to define a channel mapping to convert discrete audio channels and generic inputs to the program's arguments.

| Generic inputs | Audio format | Program arguments (audio channel: register)|
|----------------|--------------|--------------------------------------------|
| 1              | mono (1.0)   | fa0                                        |
| 2              | stereo (2.0) | left: fa0, right: fa1                      |
| 3              | stereo (2.1) | left: fa0, right: fa1, sub: fa2            |
| 3              |surround (3.0)| left: fa0, right: fa1, center/back: fa2    |
| 4              |surround (3.1)| left: fa0, right: fa1, center/back: fa2, sub: fa3|
| 4              | quad (4.0)   | left: fa0, right: fa1, back left: fa2, back right: fa3|
| more to come   |              |                                            |

### Program entry

A register used for input will contain the value of the input signal, not the address of the value in memory.

### Program exit

A Chata program may use the `ret` keyword at the uppermost level to stop execution early.

## Superpseudo Instructions

This is where Chata sets itself apart from RISC-V assembly. RISC-V assembly has "pseudo instructions" that are simply aliases for a different instruction. For example, "bnez rs1, offset" directly translates to "bne rs1, zero, offset," and "zero" is in fact an alias itself for the register "x0."

Chata, of course, supports all these pseudo instructions. What it includes in addition is "superpseudo instructions" that provide more logic and a larger selection than RISC-V's own pseudo instructions.

### `if` 

The code

```
if register condition register:
  code
```

is equivalent to

```
if_jump:
  code

beq|bne|blt|bge register, register, if_jump
```

where `condition` can be `=`, `!=`, `<`,  `>`, `<=`, or `>=`.

For example,

```
if fa1 = zero:
  foobar
```

is the same as

```
if_jump:
  foobar

beq fa1, x0, if_jump
```

which looks a lot nicer!

### `=`, `*=`, `+=`, `-=`, and `/=`

The code 

```
a0 = 69

fa0 = 69
```

is the same as

```
addi a0, zero, 69

addi t0, zero, 69
fcvt.s.w fa0, t0
```

The same idea is true for `*=`, `+=`, `-=`, and `/=`.

The code

```
a0 *= 2

a0 *= 3

a0 += 5

a0 -= 7

a0 /= 20

if a0 == 20:
  a0 += a1

# Floating point

fa0 *= 2

fa0 += 5

fa0 -= 7

fa0 /= 20
```

is the same as

```
slli a0, a0, 2 # Automatically apply this easy optimization!

addi t0, zero, 3
mul a0, a0, t0

addi a0, a0, 5

addi t0, zero, 7
sub a0, a0, t0

addi t0, zero, 20
div a0, a0, t0

if_jump:
  add a0, a0, a1
  ret # AKA jalr x0, x1, 0

addi t0, zero, 20
beq a0, t0, if_jump

# Floating point

addi t0, zero, 2
fcvt.s.w ft0, t0
fmul.s fa0, fa0, ft0

addi t0, zero, 5
fcvt.s.w ft0, t0
fadd.s fa0, fa0, ft0

addi t0, zero, 7
fcvt.s.w ft0, t0
fsub.s fa0, fa0, ft0

addi t0, zero, 20
fcvt.s.w ft0, t0
fdiv.s fa0, fa0, ft0
```

Be honest: which one would you rather read?