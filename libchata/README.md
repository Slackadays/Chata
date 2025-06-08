# Welcome to `libchata`!

`libchata` is the core library behind Chata. It handles compiling, assembling, and execution of Chata code. The assembler, Ultrassembler, can assemble most RISC-V assembly, not just the kind generated from Chata code, so you can use `libchata` just for that if you wish!

## Quick Start

> [!WARNING]
> Most of libchata is currently WORK IN PROGRESS. Anything could change right now. However, Ultrassembler is ready for real world usage!

### Prerequisites

You'll need a compiler that supports C++20, or GCC 11 and up, CMake, and Just.

### Download

Start by cloning this repo from GitHub:

```sh
git clone https://github.com/Slackadays/Chata
```

### Build

Then use `just` to build:

```sh
just build # This builds and installs everything
just build-lib # This builds and installs just libchata
just build-cli # This builds and installs just chatacli
```

### Other Actions

There are a lot of other things you can do here:

```sh
jackson@pop-desktop:~/Chata$ just
Available recipes:
    build type='Release'     # build everything
    build-cli type='Release' # build just chatacli
    build-lib type='Release' # build just libchata
    check-format             # check if all code is formatted
    clean                    # clear all CMake files for everything
    clean-cli                # clear all CMake files for just chatacli
    clean-lib                # clear all CMake files for just libchata
    copy                     # copy all files to a remote system
    default                  # show this list
    format                   # format all code
    generate                 # run codegen scripts
    test                     # run testsuites for everything
    test-lib                 # run testsuite for just libchata
```

Use `copy` if you want to edit the Chata project's code but build it remotely. This runs a script to copy everything to a remote system over SSH.

Use `generate` if you've modified data that the `.py` codegen scripts use to generate code, or if you've modified the scripts themselves.

### Integrating `libchata` into your project

Start by downloading and building `libchata`. Then, add `#include <libchata.hpp>` wherever you use its functions or objects.

If you're not using C++, bindings for other languages are planned!


