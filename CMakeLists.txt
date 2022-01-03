cmake_minimum_required(VERSION 3.7)

project(msbfs)

include_directories(include)

file(GLOB SOURCES "src/*.cc")

add_executable(MSBFS ${SOURCES})