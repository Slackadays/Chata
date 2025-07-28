cmake_minimum_required(VERSION 3.20)

project(ultrassembler LANGUAGES CXX C VERSION 1)
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

add_library(objultra OBJECT
    src/assembler.cpp
    src/utils.cpp
    src/pseudoinstructions.cpp
    src/registers.cpp
    src/csrs.cpp
    src/instructions.cpp
    src/generated/make_inst_from_pseudoinst.cpp
    src/generated/instruction_search.cpp
    src/generated/register_search.cpp
    src/generated/float_register_search.cpp
    src/generated/vec_register_search.cpp
    src/generated/int_register_search.cpp
    src/generated/csr_search.cpp
)

target_compile_options(objultra PRIVATE -fno-rtti -fno-stack-protector -fomit-frame-pointer)

set_property(TARGET objultra PROPERTY POSITION_INDEPENDENT_CODE ON)

add_library(ultrashared SHARED $<TARGET_OBJECTS:objultra>)
add_library(ultrastatic STATIC $<TARGET_OBJECTS:objultra>)

set_target_properties(ultrastatic PROPERTIES OUTPUT_NAME uas)
set_target_properties(ultrashared PROPERTIES OUTPUT_NAME uas)

add_executable(test_ultrassembler
  src/test.cpp
)

target_link_libraries(test_ultrassembler PRIVATE ultrashared)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  #add_definitions(-DDEBUG -Wall -Wextra -Wpedantic)
  add_definitions(-DDEBUG)
endif()

install(TARGETS ultrashared
    DESTINATION lib
)

install(TARGETS ultrastatic
    DESTINATION lib
)

install(FILES
    src/ultrassembler.hpp
    DESTINATION include
)