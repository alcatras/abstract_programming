#ifndef ABSTRACT_PROGRAMMING_BINARYREADER_H
#define ABSTRACT_PROGRAMMING_BINARYREADER_H


#include <memory>
#include <utility>
#include "AbstractReader.h"
#include "../Consts.h"

using namespace consts;

class BinaryReader : public AbstractReader { //<std::pair<long, std::unique_ptr<char>>> {
public:
    long position;
    long length;
    std::unique_ptr<char> data;

    void read(std::istream& istream) override {
        istream.seekg(position);
        istream.read(reinterpret_cast<char*>(&length), CHARS_IN_LONG);

        char* buffer = new char[length];
        istream.read(buffer, length);
        data = std::unique_ptr<char>(buffer);
    }
};


#endif //ABSTRACT_PROGRAMMING_BINARYREADER_H
