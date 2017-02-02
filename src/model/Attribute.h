#ifndef ABSTRACT_PROGRAMMING_ABSTRACTATTRIBUTE_H
#define ABSTRACT_PROGRAMMING_ABSTRACTATTRIBUTE_H


#include <string>
#include <bits/unique_ptr.h>
#include <sstream>
#include "../file/Handler.h"

template<typename T>
std::string stringFromValue(T value) {
    std::stringstream ss;
    ss << value;
    std::string s;
    ss >> s;
    return s;
}

class AbstractAttribute {
public:
    virtual DataTypeHandler* getHandler() = 0;

    std::string name;
    std::string type_name;

    AbstractAttribute() : name(""), type_name("") {
    }
};

template<typename T>
class TableAttribute : public AbstractAttribute {
};

template<>
struct TableAttribute<long> {
    typedef ValueHandler<long> handler_type;
    std::string name;
    std::string type_name;

    virtual DataTypeHandler* getHandler() {
        return new ValueHandler<long>(-1, -1);
    }

    static long fromString(std::string &string) {
        return atol(string.c_str());
    }

    static std::string toString(long value) {
        return stringFromValue(value);
    }
};

template<>
struct TableAttribute<double> {
    typedef ValueHandler<double> handler_type;
    std::string name;
    std::string type_name;

    virtual DataTypeHandler* getHandler() {
        return new ValueHandler<double>(-1, -1);
    }

    static double fromString(std::string &string) {
        return atof(string.c_str());
    }

    static std::string toString(double value) {
        return stringFromValue(value);
    }
};

template<>
struct TableAttribute<char *> {
    typedef BinaryHandler handler_type;
    std::string name;
    std::string type_name;

    virtual DataTypeHandler* getHandler() {
        return new BinaryHandler(-1, -1);
    }
};

template<>
struct TableAttribute<std::string> {
    typedef StringHandler handler_type;
    std::string name;
    std::string type_name;

    virtual DataTypeHandler* getHandler() {
        return new StringHandler(-1);
    }

    static std::string fromString(std::string &string) {
        return string;
    }

    static std::string toString(std::string value) {
        return value;
    }
};

#endif //ABSTRACT_PROGRAMMING_ABSTRACTATTRIBUTE_H
