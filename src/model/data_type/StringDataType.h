#ifndef ABSTRACT_PROGRAMMING_DATATYPESTRING_H
#define ABSTRACT_PROGRAMMING_DATATYPESTRING_H

#include <string>
#include "DataType.h"

struct StringDataType: public DataType{
    int getLength() override {
        return sizeof(long);
    }

    std::string name() const override {
        return "StringDataType";
    }
};


#endif //ABSTRACT_PROGRAMMING_DATATYPESTRING_H
