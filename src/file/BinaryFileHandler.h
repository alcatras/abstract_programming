#ifndef ABSTRACT_PROGRAMMING_BINARYFILEHANDLER_H
#define ABSTRACT_PROGRAMMING_BINARYFILEHANDLER_H

#include <fstream>
#include <ntsecapi.h>
#include "DataWriter.h"
#include "DataReader.h"
#include "Allocator.h"
#include "../model/block/Block.h"
#include "../model/data_type/DataType.h"
#include "../model/data_type/IntDataType.h"
#include "../model/data_type/RealDataType.h"
#include "../model/data_type/StringDataType.h"
#include "../model/data_type/BinaryDataType.h"
#include "SimpleReader.h"
#include "StringReader.h"
#include "BinaryReader.h"

class BinaryFileHandler {

    //czy tutaj lockery na plikach?

    DataWriter data_writer;
    DataReader data_reader;
    SimpleReader simple_reader;
    StringReader string_reader;
    BinaryReader binary_reader;
    Allocator allocator;
    std::fstream fstream;

public:
    BinaryFileHandler(std::string file){
        fstream.open(file);
    }

    void write(DataWriter& writer, long length, char* data){
        writer.write(fstream, allocator.getPosition(length), length, data);
    }

    void read(AbstractReader& reader){
        reader.read(fstream);
    }




    // to nizej trzeba przeniesc

    void write(DataType type, Block block){
//        std::fstream fstream("DataFile");

        // TODO zmień :D
        if (type.name() == "BinaryDataType"){
            data_writer.writeWithLength(fstream, allocator.getPosition(block.length), block.length, block.data);
        } else {
            data_writer.write(fstream, allocator.getPosition(block.length), block.length, block.data);
        }
    }

    std::pair<long, std::unique_ptr<char>> read(long position, DataType type){
        char value[type.getLength()];
        value = simple_reader.read(fstream, position, type.getLength());
        char* data;
        if (type.name() == "IntDataType" || type.name() == "RealDataType"){
            return std::pair<long, std::unique_ptr<char>>(type.getLength(), std::unique_ptr<char>(value));
        }
        if (type.name() == "StringDataType"){
            return string_reader.read(fstream, position);
        }
        if (type.name() == "BinaryDataType"){
            return binary_reader.read(fstream, position);
        }
    }


};


#endif //ABSTRACT_PROGRAMMING_BINARYFILEHANDLER_H
