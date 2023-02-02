cmake_minimum_required(VERSION 3.0.0)
project(asio_study VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(asio_study main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set (Boost_ROOT "C:/Users/zooca/workdir/Boost_v1.64")
set (Boost_LIBRARY_DIR ${Boost_ROOT}/lib)
set (Boost_INCLUDE_DIR ${Boost_ROOT}/include/boost-1_64)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})