#ifndef ABSTRACT_PROGRAMMING_RECORDREADER_H
#define ABSTRACT_PROGRAMMING_RECORDREADER_H


#include <iostream>
#include "AbstractReader.h"

class RecordReader : public AbstractReader {
public:
    char *read(std::istream &istream, long position, long length) override {
//        istream.seekg(0).seekg(position);
        istream.seekg(position);
        char buffer[length];
        istream.read(buffer, length);
        return buffer;
    }

};


#endif //ABSTRACT_PROGRAMMING_RECORDREADER_H
