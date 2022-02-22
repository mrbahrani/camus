cmake_minimum_required(VERSION 3.21)
project(camus)

set(CMAKE_CXX_STANDARD 20)
include_directories(googletest/googletest/include)
add_subdirectory(googletest)
add_executable(camusTests tests/testMain.cpp)
add_executable(camus main.cpp lexical_analyzer/Token.cpp lexical_analyzer/Token.h lexical_analyzer/LexicalAnalyzer.cpp lexical_analyzer/LexicalAnalyzer.h)

target_link_directories(camusTests PUBLIC googletest)
target_link_libraries(camusTests gtest)