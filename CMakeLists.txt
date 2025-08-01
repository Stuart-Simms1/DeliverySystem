cmake_minimum_required(VERSION 3.10.0)
project(DeliverySystem VERSION 0.1.0 LANGUAGES C CXX)


set(SOURCES include/Node.hpp src/Node.cpp main.cpp)
add_executable(DeliverySystem ${SOURCES})
target_include_directories(DeliverySystem PRIVATE include)

include(CTest)
enable_testing()

