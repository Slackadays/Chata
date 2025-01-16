# Welcome to `libchata`!

`libchata` is the core library behind Chata. It handles compiling, assembling, and execution of Chata code. The assembler, Chatassembler, can assemble all RISC-V assembly, not just the kind generated from Chata code.

# Welcome to Chatassembler!

Chatassembler is a bloat-free assembler for RISC-V. It's easy to use, embeddable, fully independent, and _over 10x faster_ than GCC's `as`.

Here's more on that. Chatassembler is...

### Complete

Supports all instructions in the RV32I, RV64I, RV32M, RV64M, RV32A, RV64A, RV32F, RV64F, RV32D, RV64D, RV32Q, RV64Q, RV32Zfh, RV64Zfh, Zifencei, Zicsr, Zawrs, Zicond, Zacas, Zcb, Zcmp, Zcd, Zcf, Zcmt, B **(WIP)**, and V **(WIP)** instruction sets, labels, and many directives **(WIP)**.

### Not a binary

Chatassembler ships in the lean and mean `libchata` library and is also available in the `chatacli` tool. Use it anywhere C++23 is supported.

### Zero config

There's only one (1) function with one (1) required parameter. Truly effortless.

### Tested

The Chatassembler testsuite currently has 500+ tests covering all supported instructions and other cases too.

### Fast!

Chatassembler uses a strategy similar to what the fast `mold` linker also uses: more efficient data structures and algorithms. Unlike `mold`, however, Chatassembler doesn't use multithreading, but it doesn't need to. **Coming soon: How is Chatassembler so fast?**

On my desktop with a Zen 3 CPU, Chatassembler is approximately 13x faster than `as` and 9x faster on my RISC-V SBC with a TH1520 SoC, both assembling the `16kinstrs.s` sample file, measured in number of cycles.

## Differences to `as`

Chatassembler is different to `as` in these important ways:

### Machine code

Chatassembler can only generate RISC-V machine code. It can't make ELF or other executable files. 

In other words, Chatassembler replaces what you would otherwise do with `as foo.s && objcopy -O binary a.out`.

### Directive support

Because Chatassembler only generates RISC-V machine code, it ignores directives such as `.align` and `.globl` which only make sense with executable files.

Here's a table of what [directives](https://github.com/riscv-non-isa/riscv-asm-manual/blob/main/src/asm-manual.adoc) Chatassembler supports as of the latest commit:

☑️ = Supported

🪛 = WIP

❌ = Not Supported Yet

💀 = Irrelevant to Chatassembler

| Directive | Status |
|-----------|--------|
| `.align` | 💀 |
| `.attribute` | 💀 |
| `.option rvc/norvc` | 💀 |
| `.option arch` | 🪛 |
| `.option pic/nopic` | 💀 |
| `.option relax/norelax` | 💀 |
| `.option push/pop` | 🪛 |
| `.insn <value>` | ☑️ |
| `.insn <insn_length>, <value>` | ☑️ |
| `.insn <type> <fields>` | 🪛 |
| Relocation functions | ❌ |
| Labels | ☑️ |
| Absolute addressing | ❌ |
| Relative addressing | ❌ |
| GOT-indirect addressing | 💀 |
| Load Immediate | ☑️ |
| Load Upper Immediate’s Immediate | ☑️ |
| Signed Immediates for I- and S-Type Instructions | ☑️ |
| Floating-point literals | ❌* |
| Load Floating-point Immediate | ❌ |
| Load Address | ❌ |
| Load Local Address | ❌ |
| Load Global Address | ❌ |
| Load and Store Global | ❌ |
| Constants | ❌ |
| Far Branches | ❌ |
| Function Calls | ☑️ |
| Floating-point rounding modes | ☑️ |
| Control and Status Registers | ☑️ |
| Standard pseudoinstructions | ☑️ |
| CSR pseudoinstructions | 🪛 |

*Currently available if you use Chata code instead

### License

Chatassembler is available with the MPL 2.0 license. This may or may not be easier to include in your project than the GPL, but this depends on your situation.

## Why Chatassembler?

I wrote Chatassembler because Chata needs to generate RISC-V machine code to execute at runtime, FAST. Until now, the only way to do this was to manually invoke `as` and `objcopy` in a funky and inefficient way. This was because there were no good, independent RISC-V assembler libraries. But now, Chatassembler can do the same thing much faster, much easier, and much prettier.

I was originally going to include Chatassembler as an entirely private part of the `libchata` library that you wouldn't be able to use on its own. However, I realized that with how useful an independent RISC-V assembler might turn out to be, you should be able to use Chatassembler independently of the rest of the Chata project. That's what you're seeing here.

## Quick Start

### Installation

Start by **installing `libchata`** how you would normally with the instructions in the `libchata` section.

Then, **include the C++ header `libchata.hpp`** where you use Chatassembler.

### Usage

The **one function** of Chatassembler is

```cpp
std::span<uint8_t> libchata_assemble(std::string_view code, std::span<RVInstructionSet> supported_sets = {})
```

where `code` is your RISC-V assembly code and `supported_sets` is optionally an array of `RVInstructionSet` enums. It returns an array of bytes of RISC-V machine code. The following is the list of supported instruction sets:

```cpp
enum class RVInstructionSet : uint8_t {
    RV32I,
    RV64I,
    RV32M,
    RV64M,
    RV32A,
    RV64A,
    RV32F,
    RV64F,
    RV32D,
    RV64D,
    RV32Q,
    RV64Q,
    RV32Zfh,
    RV64Zfh,
    Zifencei,
    Zicsr,
    Zawrs,
    Zicond,
    Zacas,
    Zcb,
    Zcmp,
    C,
    Zcd,
    Zcf,
    Zcmt,
    B,
    V
};
```

Include instruction sets if:

- You're assembling code which uses the `bclri` or `rev8` instructions, which are different on 64 bit systems than 32.
- You're assembling code which uses the `.option arch` directive, which requires knowing the target instruction sets.

If you include instruction sets, you must include at least either `RV32I` or `RV64I`.

By default, the `bclri` and `rev8` instructions target a 32 bit system.

### Exceptions

Chatassembler may throw a `ChataError` exception if it encounters incorrect code or has some other error.

To catch these, just add a `try {} catch(...) {}` block like you would with other C++ code.

These errors follow the same format that other parts of `libchata` use.

### Example

```cpp
#include <libchata.hpp>
#include <string_view>
#include <vector>

int main() {
    using enum RVInstructionSet;

    std::vector<RVInstructionSet> my_enums = {RV32I, C};

    std::string_view my_code = "addi a0, a0, 10\n"
    "sub a0, a0, a1\n"
    "ret";

    auto machine_code1 = libchata_assemble(riscv_code);

    auto machine_code2 = libchata_assemble(riscv_code, {RV32I});

    auto machine_code3 = libchata_assemble(riscv_code, my_enums);

    try {
        auto caught_code = libchata_assemble(riscv_code);
    } catch (ChataError& e) {
        // Handle your error!
    }
}
```

This concludes all of the public functionality of Chatassembler.
