<<<<<<< HEAD
cmake_minimum_required(VERSION 3.10)

project(Vector)

add_executable(Vector main.cpp)

#target_include_directories(Vector PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
=======
# CMakeLists.txt

cmake_minimum_required(VERSION 3.0)

project(Forward_List)

# Include directories
include_directories(headers)

# Globbing the source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

>>>>>>> 5576926 (This is my Forward List 1)
