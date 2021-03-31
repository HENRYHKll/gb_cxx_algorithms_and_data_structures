cmake_minimum_required(VERSION 3.18)

project(lesson7 CXX)

add_executable(lesson7 main.cxx)
target_compile_features(lesson7 PUBLIC cxx_std_17)
include(CTest)
add_test(NAME chec_lesson7
        COMMAND lesson7)
