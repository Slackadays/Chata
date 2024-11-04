cmake_minimum_required(VERSION 3.20)

project(ChataCLI LANGUAGES CXX C VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include("../boilerplate.cmake")

include_directories(/usr/local/include)

add_executable(chatacli 
    src/main.cpp
)

target_link_libraries(chatacli PRIVATE chata)

set_property(TARGET chatacli PROPERTY OUTPUT_NAME chata)

install(TARGETS chatacli DESTINATION bin)