cmake_minimum_required(VERSION 3.10)
project(OS-LAB C)

# Set C standard and flags
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# Option to enable Valgrind memory testing
option(ENABLE_VALGRIND "Enable memory leak tests" ON)

# List of files to exclude from Valgrind tests
set(SKIP_VALGRIND exp4 exp6 exp7 exp10)

# Enable testing if Valgrind is ON
if (ENABLE_VALGRIND)
  enable_testing()
endif()

# Collect all .c files from src/
file(GLOB SOURCES "src/*.c")

# Create one executable per source file
foreach(source_file ${SOURCES})
  get_filename_component(exec_name ${source_file} NAME_WE)
  add_executable(${exec_name} ${source_file})

  # If Valgrind is enabled, and file is not skipped, create a test
  if (ENABLE_VALGRIND)
    list(FIND SKIP_VALGRIND ${exec_name} index)
    if (${index} EQUAL -1)
      add_test(NAME valgrind_${exec_name}
               COMMAND valgrind --leak-check=full --error-exitcode=1 $<TARGET_FILE:${exec_name}>)
    else()
      message(STATUS "Skipping Valgrind test for ${exec_name}")
    endif()
  endif()
endforeach()

