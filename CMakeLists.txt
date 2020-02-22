cmake_minimum_required(VERSION 3.15)
project(cryptopp_example)

set(CMAKE_CXX_STANDARD 14)

find_package(cryptopp CONFIG REQUIRED)

add_executable(cryptopp_example main.cpp StringEncryption.cpp StringEncryption.h)

target_link_libraries(cryptopp_example PRIVATE cryptopp-static)