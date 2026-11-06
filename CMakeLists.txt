cmake_minimum_required(VERSION 3.16)
project(shunting_yard_calculator LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
include_directories(include)

add_executable(calculator src/main.cpp src/shunting_yard.cpp src/calculator.cpp)

enable_testing()
add_executable(unit_tests tests/test.cpp src/shunting_yard.cpp src/calculator.cpp)
add_test(NAME AllTests COMMAND unit_tests)