cmake_minimum_required(VERSION 3.26)
project(FEM_Code)

set(CMAKE_CXX_STANDARD 23)

add_executable(FEM_code main.cpp
        Node/Node.hpp
        Node/Node.cpp
        Initialize/Initialize.hpp
        Initialize/Initialize.cpp
        Element/Element.cpp
        Element/Element.h
        eigen-3.4.0/Eigen/Dense
        eigen-3.4.0/Eigen
        Problem/problem.cpp
        Problem/problem.hpp
)
