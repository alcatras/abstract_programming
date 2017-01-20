#ifndef ABSTRACT_PROGRAMMING_DATAACCESSOR_H
#define ABSTRACT_PROGRAMMING_DATAACCESSOR_H


#include "../file/BinaryFileHandler.h"

class DataAccessor {

    BinaryFileHandler file_handler;

public:
    DataAccessor() : file_handler("DataFile") {}



    void write() {
    };

};


#endif //ABSTRACT_PROGRAMMING_DATAACCESSOR_H
