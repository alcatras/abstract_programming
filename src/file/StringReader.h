#ifndef ABSTRACT_PROGRAMMING_STRINGREADER_H
#define ABSTRACT_PROGRAMMING_STRINGREADER_H

#include <string>
#include <sstream>

#include "AbstractReader.h"

class StringReader : public AbstractReader<std::string> {
public:
    std::string read(std::istream& istream, long position, long length = 0) override {
        istream.seekg(position);

        std::stringstream buffer;
        char c;
        do {
            istream >> c;
            buffer << c;
        }while (c != '\0');

        std::string s;
        buffer >> s;
        return s;
    }
};

#endif //ABSTRACT_PROGRAMMING_STRINGREADER_H
