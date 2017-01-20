#ifndef ABSTRACT_PROGRAMMING_RECORDREADER_H
#define ABSTRACT_PROGRAMMING_RECORDREADER_H


#include <iostream>
#include <memory>
#include "AbstractReader.h"

class SimpleReader : public AbstractReader{

public:
    long position;
    long length;
    std::unique_ptr<char> data;

    void read(std::istream& istream) override {
//        istream.seekg(0).seekg(position);
        istream.seekg(position);
        char buffer[length];
        istream.read(buffer, length);
        data = std::unique_ptr<char>(buffer);
    }

};


#endif //ABSTRACT_PROGRAMMING_RECORDREADER_H
