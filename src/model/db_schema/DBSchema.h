#ifndef ABSTRACT_PROGRAMMING_DBSCHEMA_H
#define ABSTRACT_PROGRAMMING_DBSCHEMA_H


#include "../table/TableDefinition.h"

class DBSchema {
public:
    std::string name;
    long indexPosition;
    std::vector<TableDefinition *> tables;

    DBSchema(std::string name, long indexPosition) {
        this->name = name;
        this->indexPosition = indexPosition;
    }

    void createTable(TableDefinition *table) {
        tables.push_back(table);
    }

    TableDefinition *getTableByName(std::string name) {
        for (auto table : this->tables) {
            if (table->name == name)
                return table;
        }
        return 0;
    }

};


#endif //ABSTRACT_PROGRAMMING_DBSCHEMA_H
