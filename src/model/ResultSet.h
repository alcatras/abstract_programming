#ifndef ABSTRACT_PROGRAMMING_RESULTSET_H
#define ABSTRACT_PROGRAMMING_RESULTSET_H

#include <vector>
#include "../Types.h"

struct ResultSet {
    std::vector<Type*> set;

    ResultSet(std::vector<Type*> set) : set(set) {};
};

#endif //ABSTRACT_PROGRAMMING_RESULTSET_H
