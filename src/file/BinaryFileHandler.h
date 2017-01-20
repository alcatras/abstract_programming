#ifndef ABSTRACT_PROGRAMMING_BINARYFILEHANDLER_H
#define ABSTRACT_PROGRAMMING_BINARYFILEHANDLER_H


#include <fstream>
#include "DataWriter.h"
#include "Allocator.h"
//#include "AbstractReader.h"
#include "SimpleReader.h"
#include "StringReader.h"
#include "BinaryReader.h"

class BinaryFileHandler {

    //czy tutaj lockery na plikach?

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

};


#endif //ABSTRACT_PROGRAMMING_BINARYFILEHANDLER_H
