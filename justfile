default:
  @just --list

copy:
  python setup-credentials.py
  . ./credentials.sh; \
  rsync -rRv -e ssh ./ $CHATA_CROSS_USERNAME@$CHATA_CROSS_IP:$CHATA_CROSS_PATH --exclude="*/build" --exclude=".git/*" --exclude="*a.out" --exclude="*.png" 

build:
  @just build-lib
  @just build-cli

build-lib:
  if [ ! -d "libchata/build" ]; then mkdir libchata/build; fi 

  if [ ! -d "libchata/build/CMakeFiles" ]; then cd libchata/build; cmake .. -DCMAKE_BUILD_TYPE=Debug; fi

  cd libchata/build; cmake --build . -j 4

  cd libchata/build; sudo cmake --install .

build-cli:
  if [ ! -d "chatacli/build" ]; then mkdir chatacli/build; fi 

  if [ ! -d "chatacli/build/CMakeFiles" ]; then cd chatacli/build; cmake .. -DCMAKE_BUILD_TYPE=Debug; fi

  cd chatacli/build; cmake --build .

  cd chatacli/build; sudo cmake --install .

clean:
  @just clean-lib
  @just clean-cli

clean-lib:
  if [ -d "libchata/build" ]; then rm -rf libchata/build; fi

clean-cli:
  if [ -d "chatacli/build" ]; then rm -rf chatacli/build; fi

format:
  cd libchata/src; find '(' -name '*.cpp' -o -name '*.hpp' ')' -exec clang-format-15 --Werror -i --verbose '{}' +
  cd chatacli/src; find '(' -name '*.cpp' -o -name '*.hpp' ')' -exec clang-format-15 --Werror -i --verbose '{}' +

check-format:
  cd libchata/src; find '(' -name '*.cpp' -o -name '*.hpp' ')' -exec clang-format-15 --Werror -i --verbose --dry-run '{}' +
  cd chatacli/src; find '(' -name '*.cpp' -o -name '*.hpp' ')' -exec clang-format-15 --Werror -i --verbose --dry-run '{}' +
