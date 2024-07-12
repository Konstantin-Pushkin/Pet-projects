cmake_minimum_required(VERSION 3.8)

project(Algorithms)

set(CMAKE_CXX_STANDARD 23)

add_executable(TodoList Task.hpp Task.cpp TodoList.hpp TodoList.cpp main.cpp)