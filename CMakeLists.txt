cmake_minimum_required(VERSION 3.15)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-std=c++98 -Wall -Werror -O0")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

set(SOURCE_FILES
        DesignByContract.h
        tinystr.h
        tinyxml.h
        TicTacToeUtils.h
        Metro.h
        TicTacToeImporter.h
        MetroExporter.h
        tinystr.cpp
        tinyxml.cpp
        tinyxmlerror.cpp
        tinyxmlparser.cpp
        TicTacToeUtils.cpp
        Metro.cpp
        TicTacToeImporter.cpp
        MetroExporter.cpp)

# Set source files for RELEASE target
set(RELEASE_SOURCE_FILES
        Main.cpp)

add_executable(MetroMain ${SOURCE_FILES} ${RELEASE_SOURCE_FILES})

# Set source files for TEST target
set(TEST_SOURCE_FILES
        TicTacToeTests.cpp)

# Create TEST target
add_executable(MetroTests ${SOURCE_FILES} ${TEST_SOURCE_FILES})


# googletest subproject
add_subdirectory(googletest)
include_directories(googletest/googletest/include)
# Specify that Tests relies on "gtest" Link library
target_link_libraries(MetroTests gtest)
