cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
set(CMAKE_C_STANDARD 11)
project(dynamicC)

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(TEST_DIR "${PROJECT_SOURCE_DIR}/test")

enable_testing()
find_package(Gtest REQUIRED)

include_directories("${SRC_DIR}")
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCES
  ${SRC_DIR}/array.c
  ${SRC_DIR}/list.c)
set(HEADERS
  ${SRC_DIR}/array.h
  ${SRC_DIR}/math_util.h)
set(TEST_HEADERS
  ${TEST_DIR}/array/array_test.h)

add_executable(run_tests ${TEST_DIR}/test_main.cc ${SOURCES} ${HEADERS}
  ${TEST_HEADERS})
target_link_libraries(run_tests ${GTEST_BOTH_LIBRARIES})
