#ifndef ABSTRACT_PROGRAMMING_DBSCHEMAPARSER_H
#define ABSTRACT_PROGRAMMING_DBSCHEMAPARSER_H

#include <sstream>
#include "../model/DBSchema.h"

class DBSchemaParser {
private:
    static constexpr const char *SCHEMANAME = "SCHEMANAME";
    static constexpr const char *TABLENAME = "TABLE_NAME";
    static constexpr const char *ATTRIBUTENAME = "ATTRIBUTE_NAME";
    static constexpr const char *ATTRIBUTETYPE = "ATTRIBUTE_TYPE";
    static constexpr const char *INDEXPOSITION = "INDEX_POSITION";
    static constexpr const char *SEPARATOR = ";";
    static constexpr const char *LINESEPARATOR = "\n";

public:
    static std::string parseDBSchemaToString(DBSchema *schema) {
        std::stringstream result;

        result << SCHEMANAME << SEPARATOR;
        result << schema->name << SEPARATOR;
        result << INDEXPOSITION << SEPARATOR;
        result << schema->indexPosition << SEPARATOR;

        for (auto table : schema->tables) {
            result << TABLENAME << SEPARATOR;
            result << table->name << SEPARATOR;
            result << INDEXPOSITION << SEPARATOR;
            result << table->indexPosition << SEPARATOR;

            for (auto attribute : table->attributes) {
                result << ATTRIBUTENAME << SEPARATOR;
                result << attribute->name << SEPARATOR;
                result << ATTRIBUTETYPE << SEPARATOR;
                result << attribute->type->name() << SEPARATOR;
            }
        }

        return result.str();
    }
};

#endif //ABSTRACT_PROGRAMMING_DBSCHEMAPARSER_H
