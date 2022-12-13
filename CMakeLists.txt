cmake_minimum_required(VERSION 3.20)
project(cppdesignpatterns)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

message(STATUS "Where to put all the RUNTIME targets when built => ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

add_executable(visitor Behavioral/Visitor/visitors.cpp)
add_executable(templatemethod Behavioral/TemplateMethod/socket.cpp)
add_executable(prototype Creational/Prototype/prototype.cpp)
add_executable(factory Creational/Factory/factory.cpp)
add_executable(virtualctor Creational/Factory/virtual_constructor.cpp)
add_executable(dynamictyperegistry Creational/Factory/dynamic_type_registry.cpp)
add_executable(adapter Structural/Adapter/adapter_via_callbacks.cpp)
add_executable(queueadapter Structural/Adapter/queue.cpp)
add_executable(decorator Structural/Decorator/wrapper.cpp)
add_executable(observer Behavioral/Observer/observer.cpp)

