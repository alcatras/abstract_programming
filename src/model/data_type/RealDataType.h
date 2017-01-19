#ifndef ABSTRACT_PROGRAMMING_DATATYPEREAL_H
#define ABSTRACT_PROGRAMMING_DATATYPEREAL_H


#include "DataType.h"

struct RealDataType : public DataType{
    int getLength() override {
        return sizeof(double);
    }

    std::string name() const override;
};

std::string RealDataType::name() const {
    return "RealDataType";
}


#endif //ABSTRACT_PROGRAMMING_DATATYPEREAL_H
