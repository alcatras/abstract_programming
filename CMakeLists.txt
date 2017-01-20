cmake_minimum_required(VERSION 3.3)
project(abstract_programming)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES src/main.cpp src/file/AbstractReader.h src/file/RecordReader.h src/command_line/EvaluationTree.h src/command_line/EvaluationNodeFactory.h src/command_line/evaluation.h src/command_line/QueryData.h src/command_line/CommandLineInterface.h)

add_executable(abstract_programming ${SOURCE_FILES})