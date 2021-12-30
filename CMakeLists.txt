cmake_minimum_required(VERSION 3.7)

project(msbfs)

include_directories(include)

# set(SOURCES src/run.cc src/test_class.cc)
file(GLOB SOURCES "src/*.cc")

add_executable(runMSBFS ${SOURCES})