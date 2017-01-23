#ifndef ABSTRACT_PROGRAMMING_BINARYFILEHANDLER_H
#define ABSTRACT_PROGRAMMING_BINARYFILEHANDLER_H

#include <fstream>
#include "DataWriter.h"
#include "Allocator.h"
#include "AbstractReader.h"

class BinaryFileHandler {

    //czy tutaj lockery na plikach?

    Allocator allocator;
    std::fstream fstream;

public:
    BinaryFileHandler(std::string file){
//        fstream.open(file, std::ios_base::out);
        fstream.open(file, std::ios_base::binary | std::ios_base::in | std::ios_base::out);
        std::cout << "czy plik '" << file << "' otwarty " << fstream.is_open();
    }

    ~BinaryFileHandler(){
        fstream.close();
    }

    void read(std::unique_ptr<AbstractReader>& reader, long position){
        reader->read(fstream, position);
    }

    long write(DataWriter& writer, long length, const char* data){
        long position = allocator.getPosition(fstream, length);
        writer.write(fstream, position, length, data);
        writer.write(std::cout, position, length, data);
        fstream.flush();
        return position;
    }

};

#endif //ABSTRACT_PROGRAMMING_BINARYFILEHANDLER_H
