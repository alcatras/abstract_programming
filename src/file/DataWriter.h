#ifndef ABSTRACT_PROGRAMMING_DATAWRITER_H
#define ABSTRACT_PROGRAMMING_DATAWRITER_H


#include <iostream>
#include <vector>
#include "../Consts.h"
using namespace consts;

class DataWriter {

    // zapis do plikow binarnych w zaleznosci od typu

public:
    void write(long position, long length, const char* data, std::ostream& ostream){
        ostream.write(data, length);
    }

    void writeWithLength(long position, long length, const char* data, std::ostream& ostream){
        ostream.write(reinterpret_cast<char*>(&length), chars_in_long).write(data, length);
    }

};

#endif //ABSTRACT_PROGRAMMING_DATAWRITER_H
