#ifndef ABSTRACT_PROGRAMMING_ABSTRACTATTRIBUTE_H
#define ABSTRACT_PROGRAMMING_ABSTRACTATTRIBUTE_H


#include <bits/unique_ptr.h>
#include "../file/DataTypeHandler.h"
#include "../file/Handler.h"

class AbstractAttribute {
public:
    virtual std::unique_ptr<DataTypeHandler> getHandler() = 0;

    std::string name;
    std::string type_name;

    AbstractAttribute() : name(""), type_name("xx") {
    }
};

template<typename T>
class TableAttribute : public AbstractAttribute {

};

template<>
class TableAttribute<long> {
    typedef ValueHandler<long> handler_type;
    std::string name;
    std::string type_name;
};

template<>
class TableAttribute<double> {
    typedef ValueHandler<double> handler_type;
    std::string name;
    std::string type_name;
};

template<>
class TableAttribute<char *> {
    typedef BinaryHandler handler_type;
    std::string name;
    std::string type_name;
};

template<>
class TableAttribute<std::string> {
    typedef StringHandler handler_type;
    std::string name;
    std::string type_name;
};

#endif //ABSTRACT_PROGRAMMING_ABSTRACTATTRIBUTE_H
