cmake_minimum_required(VERSION 3.10)
project(OS-LAB)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

file(GLOB SOURCES "src/*.c")

foreach(source_file ${SOURCES})
  get_filename_component(exec_name ${source_file} NAME_WE)
  add_executable(${exec_name} ${source_file})
endforeach()
