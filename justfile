default:
  @just --list

build-all:
  @just build-lib
  @just build-cli

build-lib:
  if [ ! -d "libchata/build" ]; then mkdir libchata/build; fi 

  cd libchata/build; cmake .. -DCMAKE_BUILD_TYPE=Debug

  cd libchata/build; cmake --build . -j 4

  cd libchata/build; sudo cmake --install .

build-cli:
  if [ ! -d "chatacli/build" ]; then mkdir chatacli/build; fi 

  cd chatacli/build; cmake .. -DCMAKE_BUILD_TYPE=Debug

  cd chatacli/build; cmake --build .

  cd chatacli/build; sudo cmake --install .

clean-all:
  @just clean-lib
  @just clean-cli

clean-lib:
  if [ -d "libchata/build" ]; then rm -rf libchata/build; fi

clean-cli:
  if [ -d "chatacli/build" ]; then rm -rf chatacli/build; fi