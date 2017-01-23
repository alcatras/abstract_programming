#ifndef ABSTRACT_PROGRAMMING_ABSTRACTATTRIBUTE_H
#define ABSTRACT_PROGRAMMING_ABSTRACTATTRIBUTE_H


#include <bits/unique_ptr.h>
#include "../file/AbstractReader.h"

class AbstractAttribute {
public:
    virtual std::unique_ptr<AbstractReader> getReader() = 0;
    virtual std::string getName() = 0;
};


#endif //ABSTRACT_PROGRAMMING_ABSTRACTATTRIBUTE_H
