cmake_minimum_required(VERSION 3.16)

project(msbfs)

include_directories(include)

file(GLOB SOURCES "src/*.cc")

add_executable(MSBFS ${SOURCES})

target_compile_features(MSBFS PRIVATE cxx_std_20)