cmake_minimum_required(VERSION 3.16)
project(TodoApp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(todo
    src/main.cpp
    src/Task.cpp
    src/TaskManager.cpp
)

target_compile_options(todo PRIVATE -Wall -Wextra -Wpedantic)