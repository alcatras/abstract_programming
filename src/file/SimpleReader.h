#ifndef ABSTRACT_PROGRAMMING_RECORDREADER_H
#define ABSTRACT_PROGRAMMING_RECORDREADER_H

#include <iostream>
#include <memory>
#include "AbstractReader.h"

class SimpleReader : public AbstractReader {

public:
    long length;
    char *data;

    SimpleReader(long length) : length(length){};

    void read(std::istream& istream, long position) override {
        data = readDirectly(istream, position, length);
//        std::cout << "test\n"; //TODO usunac
//        for (char *i = data; i<data+8; ++i){
//            std::cout << *i << "\n"; //TODO usunac
//        }
    }

    long getLength() override {
        return length;
    }

};

#endif //ABSTRACT_PROGRAMMING_RECORDREADER_H
