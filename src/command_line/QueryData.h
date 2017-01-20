//
// Created by kamil on 20.01.17.
//

#ifndef ABSTRACT_PROGRAMMING_QUERYDATA_H
#define ABSTRACT_PROGRAMMING_QUERYDATA_H

#include <string>
#include <vector>

namespace et {
    class QueryData {
    };

    struct TableQueryData : QueryData {
        std::string table_name;
    };

    struct CreateTableQueryData : TableQueryData {
        typedef std::pair<std::string, std::string> attribute_type;
        std::vector<attribute_type> attributes;
    };

    struct predicate {
        std::string lhs;
        std::string rhs;
        std::string op;
    };

    struct WhereData {
        std::vector<predicate> predicates;
    };

    struct DeleteRecordsQueryData : TableQueryData, WhereData {
    };
}

using namespace et;

#endif //ABSTRACT_PROGRAMMING_QUERYDATA_H
