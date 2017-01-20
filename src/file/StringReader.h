#ifndef ABSTRACT_PROGRAMMING_STRINGREADER_H
#define ABSTRACT_PROGRAMMING_STRINGREADER_H


#include <string>
#include <sstream>
#include <memory>
#include "AbstractReader.h"

class StringReader : public AbstractReader<std::pair<long, std::unique_ptr<char>>> {
public:
    long position;
    std::string data;

    void read(std::istream& istream) override {
        istream.seekg(position);

        std::stringstream buffer;
        char c;
        do {
            istream >> c;
            buffer << c;
        } while (c != '\0');

        buffer >> data;
    }
};

#endif //ABSTRACT_PROGRAMMING_STRINGREADER_H
