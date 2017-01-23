#ifndef ABSTRACT_PROGRAMMING_TABLEATTRIBUTE_H
#define ABSTRACT_PROGRAMMING_TABLEATTRIBUTE_H

#include <string>
#include "../Types.h"
#include "AbstractAttribute.h"

template<typename T>
class TableAttribute : public AbstractAttribute {
public:
    std::string name;

    TableAttribute(std::string name) {
        this->name = name;
    }

    std::unique_ptr<AbstractReader> getReader() override {
        return T::reader_type();
    }

    std::string getName() override {
        return name;
    }
};

#endif //ABSTRACT_PROGRAMMING_TABLEATTRIBUTE_H
