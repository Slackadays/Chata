cmake_minimum_required(VERSION 3.20)

project(libchata LANGUAGES CXX C VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include("../boilerplate.cmake")

add_library(chata MODULE
    src/libchata.cpp
)

add_compile_options(chata PRIVATE -fno-exceptions -fno-unwind-tables -fno-rtti)

install(TARGETS chata
    DESTINATION lib
)

install(FILES
    src/libchata.hpp
    DESTINATION include
)