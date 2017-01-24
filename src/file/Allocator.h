//
// Created by kamil on 24.01.17.
//

#ifndef ABSTRACT_PROGRAMMING_ALLOCATOR_H
#define ABSTRACT_PROGRAMMING_ALLOCATOR_H


#include <fstream>

class Allocator {
public:
    void free(long address, long size) {

    }

    long allocate(std::fstream &fstream, long size) {
        fstream.seekg(0, fstream.end);
        return fstream.tellg();
    }
};


#endif //ABSTRACT_PROGRAMMING_ALLOCATOR_H
