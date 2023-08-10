cmake_minimum_required(VERSION 3.27.1)
project(zstring)              

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${PROJECT_NAME} main.c)

# defines targets and sources
add_subdirectory(src)
