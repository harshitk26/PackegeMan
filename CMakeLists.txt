cmake_minimum_required(VERSION 3.2)
project(DEP C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


set(LIBINTERFACE_VERSION 1 CACHE INTEGER "Version of libInterface")
set(TEST_JSON_FILE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/test/json")

add_definitions( -DVERSION_LIBINTERFACE=${LIBINTERFACE_VERSION} )
add_definitions( -DTEST_JSON_FILE_PATH="${TEST_JSON_FILE_PATH}")


configure_file( config.h.in ${CMAKE_BINARY_DIR}/generated/config.h )
include_directories( ${CMAKE_BINARY_DIR}/generated/ ) # Make sure it can be included...

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(third_party/nlohmann_json)
add_subdirectory(third_party/googletest)


add_subdirectory(src)

# allow to report to a cdash dashboard
include(CTest)
# enable testing
enable_testing()
# define tests
add_subdirectory(test)
