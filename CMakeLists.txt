cmake_minimum_required(VERSION 3.20)
project(cppdesignpatterns)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

message(STATUS "Where to put all the RUNTIME targets when built => ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

add_executable(visitor Behavioral/Visitor/visitors.cpp)
add_executable(prototype Creational/Prototype/prototype.cpp)
add_executable(factory Creational/Factory/factory.cpp)
add_executable(adapter Structural/Adapter/adapter_via_callbacks.cpp)
add_executable(decorator Structural/Decorator/wrapper.cpp)


