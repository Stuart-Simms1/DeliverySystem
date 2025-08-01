cmake_minimum_required(VERSION 3.10.0)
project(DeliverySystem VERSION 0.1.0 LANGUAGES C CXX)


set(SOURCES include/Node.hpp include/Edge.hpp include/Basket.hpp include/Customer.hpp include/Robot.hpp include/World.hpp
            src/Node.cpp src/Edge.cpp src/Basket.cpp src/Customer.cpp src/Robot.cpp src/World.cpp
            main.cpp)
add_executable(DeliverySystem ${SOURCES})
target_include_directories(DeliverySystem PRIVATE include)

include(CTest)
enable_testing()

