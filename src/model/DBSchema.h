#ifndef ABSTRACT_PROGRAMMING_DBSCHEMA_H
#define ABSTRACT_PROGRAMMING_DBSCHEMA_H

#include "TableDefinition.h"

class DBSchema {
public:
    std::vector<std::unique_ptr<TableDefinition>> tables;

    DBSchema() : tables() {}

    void addTable(std::unique_ptr<TableDefinition> &table) {
        tables.push_back(table);
    }

    std::unique_ptr<TableDefinition> getTableByName(std::string &name) {
        for (auto table : tables) {
            if (table->name == name)
                return table;
        }
        throw -1;
    }

};

#endif //ABSTRACT_PROGRAMMING_DBSCHEMA_H
