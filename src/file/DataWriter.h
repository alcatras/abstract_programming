#ifndef ABSTRACT_PROGRAMMING_DATAWRITER_H
#define ABSTRACT_PROGRAMMING_DATAWRITER_H

#include <iostream>
#include <vector>
#include "../Consts.h"

using namespace consts;

class DataWriter {

    // TODO jedna metoda?

public:
    void write(std::ostream& ostream, long position, long length, const char* data){
        ostream.write(data, length).flush();
    }

    void writeWithLength(std::ostream& ostream, long position, long length, const char* data){
        ostream.write(reinterpret_cast<char*>(&length), CHARS_IN_LONG).write(data, length).flush();
    }

};

#endif //ABSTRACT_PROGRAMMING_DATAWRITER_H
