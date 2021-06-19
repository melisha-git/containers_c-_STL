cmake_minimum_required(VERSION 3.19)
project(stl_containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(stl_containers main.cpp vector.class.ipp vector.class.hpp iterators/vector_iterator.hpp iterators/vector_iterator.ipp)