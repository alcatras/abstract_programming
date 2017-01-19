#ifndef ABSTRACT_PROGRAMMING_DATATYPE_H
#define ABSTRACT_PROGRAMMING_DATATYPE_H

#include <string>

struct DataType {
    virtual std::string name() const = 0;
    virtual int getLength() = 0;
};


#endif //ABSTRACT_PROGRAMMING_DATATYPE_H
