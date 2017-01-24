#ifndef ABSTRACT_PROGRAMMING_ABSTRACTATTRIBUTE_H
#define ABSTRACT_PROGRAMMING_ABSTRACTATTRIBUTE_H


#include <bits/unique_ptr.h>
#include "../file/DataTypeHandler.h"
#include "../file/Handler.h"

class AbstractAttribute {
public:
    virtual std::unique_ptr<DataTypeHandler> getHandler() = 0;
};

template<typename T>
class TableAttribute : public AbstractAttribute {
public:
    std::string name;
};

template<>
class TableAttribute<long> {
    typedef ValueHandler<long> handler_type;
};

template<>
class TableAttribute<double> {
    typedef ValueHandler<double> handler_type;
};

template<>
class TableAttribute<char *> {
    typedef BinaryHandler handler_type;
};

template<>
class TableAttribute<std::string> {
    typedef StringHandler handler_type;
};

#endif //ABSTRACT_PROGRAMMING_ABSTRACTATTRIBUTE_H
