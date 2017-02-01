#ifndef ABSTRACT_PROGRAMMING_TABLEHANDLER_H
#define ABSTRACT_PROGRAMMING_TABLEHANDLER_H


#include <map>
#include <algorithm>
#include "../command_line/QueryData.h"
#include "../file/FileHandler.h"
#include "../model/TableDefinition.h"

class TableHandler {
    FileHandler *indexFile;
    std::map<std::string, std::unique_ptr<TableDefinition>> tables;

    auto getTypeDefinition(std::string& type, std::string& name){
        std::unique_ptr<AbstractAttribute> ptr;

        if(type.compare("integer") == 0){
            ptr = std::move(std::unique_ptr<AbstractAttribute>(reinterpret_cast<AbstractAttribute*>(new TableAttribute<long>())));
        }
        else if(type.compare("string") == 0){
            ptr = std::move(std::unique_ptr<AbstractAttribute>(reinterpret_cast<AbstractAttribute*>(new TableAttribute<std::string>())));
        }
        else if(type.compare("binary") == 0){
            ptr = std::move(std::unique_ptr<AbstractAttribute>(reinterpret_cast<AbstractAttribute*>(new TableAttribute<char*>())));
        }
        else if(type.compare("real") == 0){
            ptr = std::move(std::unique_ptr<AbstractAttribute>(reinterpret_cast<AbstractAttribute*>(new TableAttribute<double>())));
        } else {
            throw 1;
        }

        ptr->name = name;
        ptr->type_name = type;
        return ptr;
    }


public:
    TableHandler(FileHandler &indexFile) : tables(){
        this->indexFile = &indexFile;
        readTables();
    }

    void readTables() {
        std::fstream stream;
        stream.open("table.txt", std::ios_base::in);
        std::string line;
        while(std::getline(stream, line)) {
            std::istringstream ss(line);
            std::unique_ptr<TableDefinition> table(new TableDefinition());

            ss >> table->name >> table->indexPosition;

            std::cout << "table name: " << table->name << std::endl;
            std::cout << "table position: " << table->indexPosition << std::endl;

            while(!ss.eof()){
                std::string name, type;

                ss >> name;
                ss >> type;


                table->addTableAttribute(std::move(getTypeDefinition(type, name)));
                std::cout << "attribute type: " << type  << " attribute name: " << name << std::endl;
            }
            tables.insert(std::make_pair(table->name, std::move(table)));
        }
        stream.close();
    }

    void createTable(TableNameWithAttributes &table) {
        std::stringstream result;
        std::unique_ptr<DataTypeHandler> handler(new IndexHandler(-1));
        long address = indexFile->write(handler);

        std::cout << "table name: " << table.table_name << std::endl;

        std::unique_ptr<TableDefinition> tabledef(new TableDefinition(table.table_name, address));

        for (auto &attr: table.attributes) {
            tabledef->addTableAttribute(std::move(getTypeDefinition(attr.first, attr.second)));
            std::cout << "attribute type: " << attr.first  << " attribute name: " << attr.second << std::endl;
        }

        tables.insert(std::make_pair(table.table_name, std::move(tabledef)));
        save();
    }

    void save() {
        std::fstream stream;
        stream.open("table.txt", std::ios_base::trunc|std::ios_base::out);
        auto ite = tables.end();
        for(auto it = tables.begin(); it != ite; it++){
            stream << it->second->name;
            stream << " ";
            stream << it->second->indexPosition;
            for (auto&& tableAttribute : it->second->attributes) {
                stream << " ";
                stream << tableAttribute->name << " " << tableAttribute->type_name;
            }
            stream << std::endl;
        }
        stream.close();
    }

    std::unique_ptr<TableDefinition> getTableByName(std::string &table_name){
        return std::move(tables.at(table_name));
    }
};


#endif //ABSTRACT_PROGRAMMING_TABLEHANDLER_H
