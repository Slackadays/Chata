# show this list
default:
  @just --list

# copy all files to a remote system
copy:
  python misc/setup-credentials.py
  . ./credentials.sh; \
  rsync -rRv -e ssh ./ $CHATA_CROSS_USERNAME@$CHATA_CROSS_IP:$CHATA_CROSS_PATH --exclude="*/build" --exclude=".git/*" --exclude="*a.out" --exclude="*.png" 

set positional-arguments

# build everything
build type='Release':
  @just build-lib {{type}}
  @just build-cli {{type}}

# build just libchata
build-lib type='Release':
  if [ ! -d "libchata/build" ]; then mkdir libchata/build; fi 

  if [ ! -d "libchata/build/CMakeFiles" ]; then cd libchata/build; cmake .. -DCMAKE_BUILD_TYPE="{{type}}"; fi

  cd libchata/build; cmake --build . -j 12

  cd libchata/build; sudo cmake --install .

# build just chatacli
build-cli type='Release':
  if [ ! -d "chatacli/build" ]; then mkdir chatacli/build; fi 

  if [ ! -d "chatacli/build/CMakeFiles" ]; then cd chatacli/build; cmake .. -DCMAKE_BUILD_TYPE="{{type}}"; fi

  cd chatacli/build; cmake --build .

  cd chatacli/build; sudo cmake --install .

# clear all CMake files for everything
clean:
  @just clean-lib
  @just clean-cli

# clear all CMake files for just libchata
clean-lib:
  if [ -d "libchata/build" ]; then rm -rf libchata/build; fi

# clear all CMake files for just chatacli
clean-cli:
  if [ -d "chatacli/build" ]; then rm -rf chatacli/build; fi

# format all code
format:
  cd libchata/src; find '(' -name '*.cpp' -o -name '*.hpp' ')' -exec clang-format --Werror -i --verbose '{}' +
  cd chatacli/src; find '(' -name '*.cpp' -o -name '*.hpp' ')' -exec clang-format --Werror -i --verbose '{}' +

# check if all code is formatted
check-format:
  cd libchata/src; find '(' -name '*.cpp' -o -name '*.hpp' ')' -exec clang-format --Werror -i --verbose --dry-run '{}' +
  cd chatacli/src; find '(' -name '*.cpp' -o -name '*.hpp' ')' -exec clang-format --Werror -i --verbose --dry-run '{}' +

# run codegen scripts
generate:
  cd libchata/src; python3 scripts/generate_instruction_search.py
  cd libchata/src; python3 scripts/generate_register_search.py
  cd libchata/src; python3 scripts/generate_csr_search.py
  cd libchata/src; python3 scripts/generate_pseudoinstruction_converter.py
  @just format

# run testsuites for everything
test:
  @just test-lib

# run testsuite for just libchata
test-lib:
  cd libchata/build; ./test_libchata
  
