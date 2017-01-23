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
    std::unique_ptr<char> data;

    BinaryReader(long ptr_length) : ptr_length(ptr_length){};

    void read(std::istream& istream, long ptr_position) override {

        std::unique_ptr<char> ptr;
//        readDirectly(istream, ptr_position, ptr_length, ptr);
        position = *ptr;

        istream.seekg(position);
        istream.read(reinterpret_cast<char*>(&length), CHARS_IN_LONG);

        char* buffer = new char[length];
        istream.read(buffer, length);
        data = std::unique_ptr<char>(buffer);
    }
};


#endif //ABSTRACT_PROGRAMMING_BINARYREADER_H
