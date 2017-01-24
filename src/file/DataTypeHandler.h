//
// Created by kamil on 24.01.17.
//

#ifndef ABSTRACT_PROGRAMMING_ABSTRACTREADER_H
#define ABSTRACT_PROGRAMMING_ABSTRACTREADER_H


#include <fstream>
#include "Allocator.h"

class DataTypeHandler {
public:
    virtual void read(std::fstream &istream) = 0;

    virtual long write(std::fstream &ostream, Allocator &allocator) = 0;

protected:
    char *readNBytes(std::fstream &stream, long address, long count) {
        stream.seekg(address);
        return readNBytes(stream, count);
    }

    char *readNBytes(std::fstream &stream, long count) {
        char *buffer = new char[count];
        stream.read(buffer, count);
        return buffer;
    }

    void writeNBytes(std::fstream &stream, long address, char *data, long size) {
        stream.seekg(address);
        writeNBytes(stream, data, size);
    }

    void writeNBytes(std::fstream &stream, char *data, long size) {
        stream.write(data, size).flush();
    }
};


#endif //ABSTRACT_PROGRAMMING_ABSTRACTREADER_H
