cmake_minimum_required(VERSION 3.30)
project(lab15v2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab15v2 main.cpp
        stack.cpp
        stack.h
        node.h
        queue.cpp
        queue.h
        linked_list.cpp
        linked_list.h)
