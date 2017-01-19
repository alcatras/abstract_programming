#ifndef ABSTRACT_PROGRAMMING_DATAWRITER_H
#define ABSTRACT_PROGRAMMING_DATAWRITER_H


#include <iostream>
#include <vector>
#include "../Consts.h"
using namespace consts;

class DataWriter {

    // zapis do plikow binarnych w zaleznosci od typu

public:
    void write(int position, long length, const char* data, std::ostream& ostream){
        ostream.write(data, length);
    }

    void writeWithLength(int position, long length, const char* data, std::ostream& ostream){
        ostream.write(static_cast<char*>(&length), chars_in_long).write(data, length);
    }

};

#endif //ABSTRACT_PROGRAMMING_DATAWRITER_H
