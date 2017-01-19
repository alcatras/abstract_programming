cmake_minimum_required(VERSION 3.3)
project(abstract_programming)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/main.cpp
        src/command_line/CommandLine.h
        src/command_line/Query.h
        src/file/AbstractReader.h
        src/file/RecordReader.h
        src/file/BinaryFileHandler.h
        src/file/DataWriter.h
        src/file/StringReader.h
        src/file/BinaryReader.h
        src/model/data_type/DataType.h
        src/model/data_type/IntDataType.h
        src/model/data_type/StringDataType.h
        src/model/data_type/RealDataType.h
        src/model/data_type/BinaryDataType.h
        src/model/block/Block.h
        src/model/table/TableAttribute.h
        src/model/table/TableDefinition.h
        src/model/db_schema/DBSchema.h
        src/parser/DBSchemaParser.h
        src/Consts.h
)
set()

add_executable(abstract_programming ${SOURCE_FILES})