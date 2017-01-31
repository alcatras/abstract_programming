//
// Created by kamil on 24.01.17.
//

#ifndef ABSTRACT_PROGRAMMING_FILEHANDLER_H
#define ABSTRACT_PROGRAMMING_FILEHANDLER_H


#include <fstream>
#include <memory>
#include "Allocator.h"
#include "DataTypeHandler.h"

class FileHandler {

    Allocator allocator;
    std::fstream fstream;
public:

    FileHandler(std::string file) : fstream(file, std::ios_base::binary | std::ios_base::in | std::ios_base::out) {

    }

    virtual ~FileHandler() {
        fstream.close();
    }

    void read(std::unique_ptr<DataTypeHandler> &reader) {
        reader->read(fstream);
    }

    long write(std::unique_ptr<DataTypeHandler> &writer) {
        writer->write(fstream, allocator);
    }
};


#endif //ABSTRACT_PROGRAMMING_FILEHANDLER_H
