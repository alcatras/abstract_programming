#ifndef ABSTRACT_PROGRAMMING_BINARYREADER_H
#define ABSTRACT_PROGRAMMING_BINARYREADER_H

#include <memory>
#include <utility>
#include "AbstractReader.h"
#include "../Consts.h"

using namespace consts;

class BinaryReader : public AbstractReader {
public:
    long ptr_length;
    long position;
    long length;
    char *data;

    BinaryReader(long ptr_length) : ptr_length(ptr_length){};

    void read(std::istream& istream, long ptr_position) override {

        char *ptr = readDirectly(istream, ptr_position, ptr_length);
        position = *ptr;

        istream.seekg(position);
        istream.read(reinterpret_cast<char*>(&length), CHARS_IN_LONG);

        char* buffer = new char[length];
        istream.read(buffer, length);
        data = buffer;
    }

    long getLength() override {
        return length;
    }

};

#endif //ABSTRACT_PROGRAMMING_BINARYREADER_H
