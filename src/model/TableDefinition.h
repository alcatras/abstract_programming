#ifndef ABSTRACT_PROGRAMMING_TABLEDEFINITION_H
#define ABSTRACT_PROGRAMMING_TABLEDEFINITION_H

#include <string>
#include <vector>
#include "Attribute.h"

struct TableDefinition {
    std::string name;
    long indexPosition;
    std::vector<std::unique_ptr<AbstractAttribute>> attributes;

    TableDefinition(const std::string &name, long indexPosition)
            : name(name), indexPosition(indexPosition), attributes() {}

    void addTableAttribute(std::unique_ptr<AbstractAttribute> &attribute) {
        attributes.push_back(attribute);
    }
};

#endif //ABSTRACT_PROGRAMMING_TABLEDEFINITION_H
