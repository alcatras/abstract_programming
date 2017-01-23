#ifndef ABSTRACT_PROGRAMMING_TABLEATTRIBUTE_H
#define ABSTRACT_PROGRAMMING_TABLEATTRIBUTE_H

#include <string>
#include "../Types.h"

struct TableAttribute {
    std::string name;
    type_traits<IntegerType> *type;

    TableAttribute(std::string name, type_traits<IntegerType> *type) {
        this->name = name;
        this->type = type;
    }
};

#endif //ABSTRACT_PROGRAMMING_TABLEATTRIBUTE_H
