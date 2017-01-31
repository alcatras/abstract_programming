//
// Created by kamil on 31.01.17.
//

#ifndef ABSTRACT_PROGRAMMING_DATABASECONTEXT_H
#define ABSTRACT_PROGRAMMING_DATABASECONTEXT_H


#include "file/FileHandler.h"

class DatabaseContext {
    FileHandler indexFile;
    FileHandler dataFile;

public:
    DatabaseContext() : indexFile("index.bin"), dataFile("data.bin") {

    }

    const FileHandler &getIndexFile() const {
        return indexFile;
    }

    const FileHandler &getDataFile() const {
        return dataFile;
    }
};


#endif //ABSTRACT_PROGRAMMING_DATABASECONTEXT_H
