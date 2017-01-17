#ifndef ABSTRACT_PROGRAMMING_RECORDREADER_H
#define ABSTRACT_PROGRAMMING_RECORDREADER_H


#include <iostream>
#include "AbstractReader.h"

class RecordReader : public AbstractReader{
    char * read(int position, int length, std::istream istream, std::ostream ostream) override {
        istream.seekg(0).seekg(position);
        char buffer[length];
        istream.read(buffer, length);
        return buffer;
    }

};


#endif //ABSTRACT_PROGRAMMING_RECORDREADER_H
