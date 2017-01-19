#ifndef ABSTRACT_PROGRAMMING_DBSCHEMAPARSER_H
#define ABSTRACT_PROGRAMMING_DBSCHEMAPARSER_H


#include <sstream>
#include "../model/db_schema/DBSchema.h"

class DBSchemaParser {
private:
    static constexpr const char* SCHEMANAME = "SCHEMANAME";
    static constexpr const char* TABLENAME = "TABLE_NAME";
    static constexpr const char* ATTRIBUTENAME = "ATTRIBUTE_NAME";
    static constexpr const char* ATTRIBUTETYPE = "ATTRIBUTE_TYPE";
    static constexpr const char* INDEXPOSITION = "INDEX_POSITION";
    static constexpr const char* SEPARATOR = ";";

public:
    static std::string parseDBSchemaToString(DBSchema *schema) {
        std::stringstream result;

        result << SCHEMANAME << SEPARATOR;
        result << schema->name << SEPARATOR;
        result << INDEXPOSITION << SEPARATOR;
        result << schema->indexPosition << SEPARATOR;

        for (auto table : schema->tables) {
            result << TABLENAME << SEPARATOR;
            result << table->getName() << SEPARATOR;
            result << INDEXPOSITION << SEPARATOR;
            result << table->getIndexPosition() << SEPARATOR;


            for(auto attribute : table->getAttributes()) {
                result << ATTRIBUTENAME << SEPARATOR;
                result << attribute->getName() << SEPARATOR;
                result << ATTRIBUTETYPE << SEPARATOR;
                result << attribute->getType()->name() << SEPARATOR;
            }
        }

        return result.str();
    }
};


#endif //ABSTRACT_PROGRAMMING_DBSCHEMAPARSER_H
