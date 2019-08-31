cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(
    unit_tests
    entity_test.cpp
    )

target_include_directories(
    unit_tests
    PRIVATE
        ${PROJECT_BINARY_DIR}
     )

target_link_libraries(
    unit_tests
    gtest_main
    clone_entity
    )


add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
