//
// Created by kamil on 31.01.17.
//

#ifndef ABSTRACT_PROGRAMMING_DATABASECONTEXT_H
#define ABSTRACT_PROGRAMMING_DATABASECONTEXT_H


#include "file/FileHandler.h"
#include "parser/TableHandler.h"

class DatabaseContext {
    FileHandler indexFile;
    FileHandler dataFile;
    TableHandler tableHandler;

public:
    DatabaseContext() : indexFile("index.bin"), dataFile("data.bin"), tableHandler(indexFile) {

    }

    FileHandler &getIndexFile() {
        return indexFile;
    }

    FileHandler &getDataFile() {
        return dataFile;
    }

    TableHandler &getTableHandler() {
        return tableHandler;
    }
};


#endif //ABSTRACT_PROGRAMMING_DATABASECONTEXT_H
