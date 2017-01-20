#ifndef ABSTRACT_PROGRAMMING_INDEXACCESSOR_H
#define ABSTRACT_PROGRAMMING_INDEXACCESSOR_H


#include <fstream>
#include "../file/BinaryFileHandler.h"

class IndexAccessor {
    BinaryFileHandler file_handler;

public:
    IndexAccessor() : file_handler("IndexFile"){}

    std::vector<long> getIndex(long position) {
        BinaryReader reader;
        reader.position = position;
        file_handler.read(reader);

        std::vector<long> result;

        long* pointer = reinterpret_cast<long*>(reader.data.get());
        for (; pointer < pointer + reader.length/chars_in_long; ++pointer){
            result.emplace_back(pointer);
        }

        return result;
    }

    void write(long position, long index){

    }
};


#endif //ABSTRACT_PROGRAMMING_INDEXACCESSOR_H
