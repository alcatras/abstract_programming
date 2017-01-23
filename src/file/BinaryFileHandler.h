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
        fstream.open(file);
        std::cout << "czy plik '" << file << "' otwarty " << fstream.is_open();
        std::fstream test("DataFile");
        std::cout << "czy plik '" << "test" << "' otwarty " << fstream.is_open();
    }

    //destruktor => fstream.close(file);

    void read(AbstractReader* reader, long position){
        reader->read(fstream, position);
    }

    long write(DataWriter& writer, long length, const char* data){
        long position = allocator.getPosition(length);
        writer.write(fstream, position, length, data);
        return position;
    }

};

#endif //ABSTRACT_PROGRAMMING_BINARYFILEHANDLER_H
