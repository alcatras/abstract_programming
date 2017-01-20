#ifndef ABSTRACT_PROGRAMMING_BINARYREADER_H
#define ABSTRACT_PROGRAMMING_BINARYREADER_H

#include <bits/unique_ptr.h>
#include "AbstractReader.h"
#include "../Consts.h"
using namespace consts;

class BinaryReader : public AbstractReader<std::unique_ptr<char>> {
public:
    std::unique_ptr<char> read(std::istream& istream, long position, long length = 0) override {
        istream.seekg(position);
        long binary_length;
        istream.read(reinterpret_cast<char*>(&binary_length), chars_in_long);

        char* buffer = new char[binary_length];
        istream.read(buffer, binary_length);
        std::unique_ptr<char> ptr(buffer);

        return ptr;
    }
};


#endif //ABSTRACT_PROGRAMMING_BINARYREADER_H
