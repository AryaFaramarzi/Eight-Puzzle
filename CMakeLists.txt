cmake_minimum_required(VERSION 3.13.4)

project(Eight_Puzzle)

set (EIGHT_PUZZLE_SOURCES
        src/main.cpp 
        src/Node.cpp 
        src/Search.cpp
)

include_directories(header)

add_executable(${PROJECT_NAME} ${EIGHT_PUZZLE_SOURCES})