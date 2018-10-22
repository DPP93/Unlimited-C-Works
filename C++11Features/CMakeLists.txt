cmake_minimum_required(VERSION 3.5)
project(C__11Features)

set(CMAKE_CXX_STANDARD 11)

add_executable(C__11Features main.cpp Lambdas.cpp Lambdas.h FunctionalTypes.cpp FunctionalTypes.h DelegateConstructor.cpp DelegateConstructor.h Constructors.cpp Constructors.h References.cpp References.h)