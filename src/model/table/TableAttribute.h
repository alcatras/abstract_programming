#ifndef ABSTRACT_PROGRAMMING_TABLEATTRIBUTE_H
#define ABSTRACT_PROGRAMMING_TABLEATTRIBUTE_H

#include <string>
#include "../data_type/DataType.h"

struct TableAttribute {
    std::string name;
    DataType* type;

    TableAttribute(std::string name, DataType* type){
        this->name = name;
        this->type = type;
    }
};


#endif //ABSTRACT_PROGRAMMING_TABLEATTRIBUTE_H
