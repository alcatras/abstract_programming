#ifndef ABSTRACT_PROGRAMMING_TABLEDEFINITION_H
#define ABSTRACT_PROGRAMMING_TABLEDEFINITION_H


#include <string>
#include <vector>
#include "TableAttribute.h"
#include "../data_type/DataType.h"

struct TableDefinition {
    std::string name;
    long indexPosition;
    std::vector<TableAttribute*> attributes;

    TableDefinition(std::string name, long indexPosition) {
        this->name = name;
        this->indexPosition = indexPosition;
    }

    std::string getName() {
        return this->name;
    }

    long getIndexPosition() {
        return this->indexPosition;
    }

    std::vector<TableAttribute*> getAttributes(){
        return this->attributes;
    }

    void createTableAttribute(std::string name, DataType* type) {
        this->attributes.push_back(new TableAttribute(name, type));
    }
};


#endif //ABSTRACT_PROGRAMMING_TABLEDEFINITION_H
