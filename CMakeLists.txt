cmake_minimum_required(VERSION 3.10)
project(CBigNum)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Add cbignum library
add_library(cbignum STATIC src/cbignum.cpp)
target_include_directories(cbignum PUBLIC include)

# Add cbigmath library
add_library(cbigmath STATIC src/cbigmath.cpp)
target_include_directories(cbigmath PUBLIC include)

# Installation rules
install(TARGETS cbignum cbigmath 
        ARCHIVE DESTINATION lib)
install(DIRECTORY include/ 
        DESTINATION include 
        FILES_MATCHING PATTERN "*.h")
