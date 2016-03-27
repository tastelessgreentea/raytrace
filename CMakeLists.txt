cmake_minimum_required(VERSION 2.6)

set(project_name raytrace)

project(${project_name})

include_directories(${CMAKE_SOURCE_DIR}/src/)
link_directories(${CMAKE_SOURCE_DIR}/src/)

add_subdirectory(src)
