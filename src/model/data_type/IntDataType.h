#ifndef ABSTRACT_PROGRAMMING_DATATYPEINT_H
#define ABSTRACT_PROGRAMMING_DATATYPEINT_H


#include "DataType.h"

struct IntDataType : public DataType{
    int getLength() override {
        return sizeof(long);
    }

    std::string name() const override {
        return "IntDataType";
    }
};


#endif //ABSTRACT_PROGRAMMING_DATATYPEINT_H
