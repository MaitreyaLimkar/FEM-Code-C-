cmake_minimum_required(VERSION 3.26)
project(FEM_Code)

set(CMAKE_CXX_STANDARD 17)

add_executable(FEM_code main.cpp
        Node/Node.hpp
        Node/Node.cpp
        Initialize/Initialize.hpp
        Initialize/Initialize.cpp
        Element/Element.cpp
        Element/Element.h
        Preprocess/Mesh_1D.hpp
        Preprocess/Mesh_1D.cpp
        eigen-3.4.0/Eigen/Dense
        eigen-3.4.0/Eigen
        Problem/problem.cpp
        Problem/problem.hpp
)

include_directories(${CMAKE_SOURCE_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)
