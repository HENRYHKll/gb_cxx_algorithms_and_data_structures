cmake_minimum_required(VERSION 3.18)

project(lesson9 CXX)

add_executable(lesson9 main.cxx)
target_compile_features(lesson9 PUBLIC cxx_std_17)
include(CTest)
add_test(NAME chec_lesson9
        COMMAND lesson9)
