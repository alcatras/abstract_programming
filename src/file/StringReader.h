#ifndef ABSTRACT_PROGRAMMING_STRINGREADER_H
#define ABSTRACT_PROGRAMMING_STRINGREADER_H

#include <string>
#include <sstream>
#include <memory>
#include "AbstractReader.h"

class StringReader : public AbstractReader {
public:
    long ptr_length;
    std::string data;

    StringReader(long ptr_length) : ptr_length(ptr_length){};

    void read(std::istream& istream, long ptr_position) override {
        char *ptr = readDirectly(istream, ptr_position, ptr_length);

        long string_position = *ptr;
        istream.seekg(string_position);

        std::stringstream buffer;
        char c;
        do {
            istream >> c;
            buffer << c;
        } while (c != '\0');

        buffer >> data;
    }

    long getLength() override {
        return 0;
    }
};

#endif //ABSTRACT_PROGRAMMING_STRINGREADER_H
