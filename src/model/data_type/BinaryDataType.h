#ifndef ABSTRACT_PROGRAMMING_DATATYPEBINARY_H
#define ABSTRACT_PROGRAMMING_DATATYPEBINARY_H


#include "DataType.h"

struct BinaryDataType : public DataType {
    int getLength() {
        return sizeof(long);
    }

    std::string name() const override {
        return "BinaryDataType";
    }
};


#endif //ABSTRACT_PROGRAMMING_DATATYPEBINARY_H
