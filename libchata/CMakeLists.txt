cmake_minimum_required(VERSION 3.20)

project(libchata LANGUAGES CXX C VERSION 1)
set(CMAKE_CXX_STANDARD 20)
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

add_library(objchata OBJECT
    src/libchata.cpp
    src/assembler/assembler.cpp
    src/compile.cpp
    src/utils.cpp
    src/if.cpp
    src/change.cpp
    src/assembler/instructions.cpp
    src/assembler/pseudoinstructions.cpp
    src/assembler/make_inst_from_pseudoinst.cpp
    src/registers.cpp
    src/assembler/csrs.cpp
    src/assembler/instruction_search.cpp
    src/register_search.cpp
    src/assembler/csr_search.cpp
)

target_compile_options(objchata PRIVATE -fno-rtti -fno-stack-protector -fomit-frame-pointer)

set_property(TARGET objchata PROPERTY POSITION_INDEPENDENT_CODE ON)

add_library(chatashared SHARED $<TARGET_OBJECTS:objchata>)
add_library(chatastatic STATIC $<TARGET_OBJECTS:objchata>)

set_target_properties(chatastatic PROPERTIES OUTPUT_NAME chata)
set_target_properties(chatashared PROPERTIES OUTPUT_NAME chata)

add_executable(test_libchata
  src/test.cpp
)

target_link_libraries(test_libchata PRIVATE chatashared)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  #add_definitions(-DDEBUG -Wall -Wextra -Wpedantic)
  add_definitions(-DDEBUG)
endif()

install(TARGETS chatashared
    DESTINATION lib
)

install(TARGETS chatastatic
    DESTINATION lib
)

install(FILES
    src/libchata.hpp
    DESTINATION include
)