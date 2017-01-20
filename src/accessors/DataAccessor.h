#ifndef ABSTRACT_PROGRAMMING_DATAACCESSOR_H
#define ABSTRACT_PROGRAMMING_DATAACCESSOR_H


#include <vector>
#include "../file/BinaryFileHandler.h"
#include "../model/TableAttribute.h"

class DataAccessor {

    BinaryFileHandler file_handler;

public:
    DataAccessor() : file_handler("DataFile") {}

    void read(std::vector<TableAttribute *> attributes, std::vector<long> index){
        for (auto record = index.begin(); record < index.end(); record++){
            for (auto attribute = attributes.begin(); attribute < attributes.end(); attribute++){
                SimpleReader reader;
                file_handler.read(reader);
                //TODO

            }
        }
    }

    void write() {
    };

};


#endif //ABSTRACT_PROGRAMMING_DATAACCESSOR_H
