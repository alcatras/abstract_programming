#ifndef ABSTRACT_PROGRAMMING_DATAACCESSOR_H
#define ABSTRACT_PROGRAMMING_DATAACCESSOR_H


#include <vector>
#include <string>
#include "../file/BinaryFileHandler.h"
#include "../file/BinaryFileHandler.h"
#include "../model/TableAttribute.h"
#include "../model/Block.h"

class DataAccessor {

    BinaryFileHandler file_handler;

public:
    DataAccessor() : file_handler("DataFile") {}

    void read(std::vector<TableAttribute *> attributes, std::vector<long> index){
        for (auto row = index.begin(); row != index.end(); row++){
            for (auto attribute = attributes.begin(); attribute != attributes.end(); attribute++){

                AbstractReader *reader = &(*(*attribute)->type->getReader());
                file_handler.read(reader, *row);



            }
        }
    }

    void write(Block block) {

        DataWriter writer;
        long position = file_handler.write(writer, block.length, block.data);
    };

};


#endif //ABSTRACT_PROGRAMMING_DATAACCESSOR_H
