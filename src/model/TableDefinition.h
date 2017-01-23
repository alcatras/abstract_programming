#ifndef ABSTRACT_PROGRAMMING_TABLEDEFINITION_H
#define ABSTRACT_PROGRAMMING_TABLEDEFINITION_H

#include <string>
#include <vector>
#include "TableAttribute.h"
#include "../Types.h"

struct TableDefinition {
    std::string name;
    long indexPosition;
    std::vector<AbstractAttribute*> attributes;

    TableDefinition(std::string name, long indexPosition) {
        this->name = name;
        this->indexPosition = indexPosition;
    }

    void createTableAttribute(std::string name, Type *type) {
        this->attributes.push_back(new TableAttribute(name));
    }
};

#endif //ABSTRACT_PROGRAMMING_TABLEDEFINITION_H
