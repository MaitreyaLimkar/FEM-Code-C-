cmake_minimum_required(VERSION 3.26)
project(FEM_Code)
#include(FetchContent)
#include(eigen-3.4.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(FEM_code main.cpp
        Node/Node.hpp
        Node/Node.cpp
        Preprocess/Mesh_1D.hpp
        Preprocess/Mesh_1D.cpp)


#add_executable(eigen_run main.cpp)
include_directories(${CMAKE_SOURCE_DIR})
#target_link_libraries(eigen_run PRIVATE eigen)
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)