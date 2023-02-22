cmake_minimum_required(VERSION 3.0.0)
project(asio_study VERSION 0.1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set asio libraries
include(3rdparty.cmake)

add_subdirectory(synchronous_tcp)
add_subdirectory(asynchronous_tcp)
add_subdirectory(chatting_tcp)