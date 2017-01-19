#ifndef ABSTRACT_PROGRAMMING_BINARYREADER_H
#define ABSTRACT_PROGRAMMING_BINARYREADER_H

#include "AbstractReader.h"
#include "../Consts.h"
using namespace consts;

class BinaryReader : public AbstractReader{
    std::string read(std::istream& istream, long position, long length = 0) override {
        istream.seekg(position);
        long binary_length;
        istream.read(static_cast<char*>(&binary_length), chars_in_long);

        char buffer[binary_length];
        istream.read(buffer, binary_length);
        return buffer;
    }
};


#endif //ABSTRACT_PROGRAMMING_BINARYREADER_H
