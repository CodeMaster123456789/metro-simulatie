cmake_minimum_required(VERSION 3.15)
project(Metro_simulatie)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-std=c++98 -Wall -Werror -O0")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

include_directories(gtest/include)
link_directories(gtest/lib)
set(SOURCE_FILES
        lib/DesignByContract.h
        lib/tinystr.h
        lib/tinyxml.h
        src/MetroUtils.h
        src/Metro.h
        src/MetroImporter.h
        src/MetroExporter.h
        lib/tinystr.cpp
        lib/tinyxml.cpp
        lib/tinyxmlerror.cpp
        lib/tinyxmlparser.cpp
        src/MetroUtils.cpp
        src/Metro.cpp
        src/MetroImporter.cpp
        src/MetroExporter.cpp src/Station.cpp src/Station.h src/Tram.cpp src/Tram.h)

# Set source files for RELEASE target
set(RELEASE_SOURCE_FILES
        Main.cpp)

add_executable(MetroMain ${SOURCE_FILES} ${RELEASE_SOURCE_FILES})

# Set source files for TEST target
set(TEST_SOURCE_FILES
        MetroTests.cpp
        test/TramTest.cpp
        test/MetroDomainTests.cpp
        test/MetroInputTests.cpp
        test/MetroOutputTests.cpp)

# Create TEST target
add_executable(MetroTests ${SOURCE_FILES} ${TEST_SOURCE_FILES})


# googletest subproject

# Specify that Tests relies on "gtest" Link library
target_link_libraries(MetroTests gtest)
