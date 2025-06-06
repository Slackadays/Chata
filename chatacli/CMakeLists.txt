cmake_minimum_required(VERSION 3.20)

project(ChataCLI LANGUAGES CXX C VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

execute_process( # save the current branch to GIT_BRANCH
  COMMAND git rev-parse --abbrev-ref HEAD
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_BRANCH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process( # save the current commit hash to GIT_COMMIT_HASH
  COMMAND git log -1 --format=%h
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_COMMIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_definitions(-DGIT_COMMIT_HASH="${GIT_COMMIT_HASH}")
add_definitions(-DGIT_BRANCH="${GIT_BRANCH}")
add_definitions(-DPROJECT_VERSION="${PROJECT_VERSION}")

include(CheckIPOSupported)
check_ipo_supported(RESULT lto_supported)
if(lto_supported AND NOT NO_LTO)
  set_property(TARGET ${this_target} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
  if(CMAKE_COMPILER_IS_GNUCXX)
    list(APPEND CMAKE_CXX_COMPILE_OPTIONS_IPO "-flto=auto") # set the thread amount to what is available on the CPU
  endif()
endif()

include_directories(/usr/local/include)

add_executable(chatacli 
    src/main.cpp
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  #add_definitions(-DDEBUG -Wall -Wextra -Wpedantic)
  add_definitions(-DDEBUG)
endif()

target_link_libraries(chatacli PRIVATE chata)

set_property(
    TARGET chatacli
    APPEND
    PROPERTY INSTALL_RPATH
    "$ORIGIN/../lib"
)

set_property(TARGET chatacli PROPERTY OUTPUT_NAME chata)

install(TARGETS chatacli DESTINATION bin)