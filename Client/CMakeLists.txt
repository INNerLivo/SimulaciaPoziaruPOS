cmake_minimum_required(VERSION 3.18)
project(Client)

set(CMAKE_CXX_STANDARD 17)

add_executable(Client main.cpp
                my_socket.cpp my_socket.h)
