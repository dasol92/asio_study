cmake_minimum_required(VERSION 3.0.0)
project(asio_study VERSION 0.1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set asio libraries
include(3rdparty.cmake)

add_executable(sync_tcp_server synchronous_tcp/sync_server.cpp)
add_executable(sync_tcp_client synchronous_tcp/sync_client.cpp)

add_executable(async_tcp_server asynchronous_tcp/async_server.cpp)
add_executable(async_tcp_client asynchronous_tcp/async_client.cpp)

add_subdirectory(chatting_tcp)