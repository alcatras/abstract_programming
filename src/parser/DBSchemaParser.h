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
//    static std::string parseDBSchemaToString(DBSchema &schema) {
//        std::stringstream result;
//
//        result << SCHEMANAME << SEPARATOR;
//        result << schema->name << SEPARATOR;
//        result << INDEXPOSITION << SEPARATOR;
//        result << schema.indexPosition << SEPARATOR;
//
//        for (auto table : schema->tables) {
//            result << TABLENAME << SEPARATOR;
//            result << table->name << SEPARATOR;
//            result << INDEXPOSITION << SEPARATOR;
//            result << table->indexPosition << SEPARATOR;
//
//            for (auto attribute : table->attributes) {
//                result << ATTRIBUTENAME << SEPARATOR;
//                result << attribute->name << SEPARATOR;
//                result << ATTRIBUTETYPE << SEPARATOR;
//                result << attribute->type->name() << SEPARATOR;
//            }
//        }
//
//        return result.str();
//    }
//
//    static DBSchema parseStringToDBSchema(std::string schema) {
//        std::vector<std::string> elems;
//        std::stringstream ss;
//        ss.str(schema);
//        std::string item;
//
//        while (std::getline(ss, item, ';')) {
//            elems.push_back(item);
//        }
//
//        long schemaIndexPosition = std::atol(elems[3].c_str());
//
//        DBSchema result(elems[1], schemaIndexPosition);
//
//        long tableIndexPosition;
//
//        int index = 4;
//
//        while (index < elems.size()) {
//
//            tableIndexPosition = std::atol(elems[index + 3].c_str());
//            TableDefinition tableDefinition(elems[index + 1], tableIndexPosition);
//            for (index = index + 4; index < elems.size() && elems[index].compare("TABLENAME") != 0; index += 4) {
//                std::string attributeName = elems[index + 1];
//                std::string attributeTypeString = elems[index + 3];
//                DataType *attributeType;
//                if (attributeTypeString.compare("BinaryDataType") == 0) {
//                    attributeType = new BinaryDataType();
//                } else if (attributeTypeString.compare("IntDataType") == 0) {
//                    attributeType = new IntDataType();
//                } else if (attributeTypeString.compare("RealDataType") == 0) {
//                    attributeType = new RealDataType();
//                } else if (attributeTypeString.compare("StringDataType") == 0) {
//                    attributeType = new StringDataType();
//                }
//                tableDefinition.createTableAttribute(attributeName, attributeType);
//            }
//            result.createTable(&tableDefinition);
//        }
//        return result;
//    }
};

#endif //ABSTRACT_PROGRAMMING_DBSCHEMAPARSER_H
