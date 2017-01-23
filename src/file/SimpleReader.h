#ifndef ABSTRACT_PROGRAMMING_RECORDREADER_H
#define ABSTRACT_PROGRAMMING_RECORDREADER_H

#include <iostream>
#include <memory>
#include "AbstractReader.h"

class SimpleReader : public AbstractReader {

public:
    long length;
    std::unique_ptr<char> data;

    SimpleReader(long length) : length(length){};

    void read(std::istream& istream, long position) override {
//        readDirectly(istream, position, length, data);
////         istream.seekg(0).seekg(position);
//        istream.seekg(position);
//        char buffer[length];
//        istream.read(buffer, length);
//        data = std::unique_ptr<char>(buffer);
//        std::cout << "test\n"; //TODO usunac
    }

};

#endif //ABSTRACT_PROGRAMMING_RECORDREADER_H
