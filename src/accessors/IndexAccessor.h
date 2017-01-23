#ifndef ABSTRACT_PROGRAMMING_INDEXACCESSOR_H
#define ABSTRACT_PROGRAMMING_INDEXACCESSOR_H

#include <fstream>
#include "../file/BinaryFileHandler.h"
#include "../file/BinaryReader.h"
#include "../Types.h"

class IndexAccessor {
    BinaryFileHandler file_handler;

public:
    IndexAccessor() : file_handler("IndexFile"){}

    std::vector<long> getIndex(long position) {
        std::unique_ptr<AbstractReader> reader = std::unique_ptr(type_traits<BinaryType>::reader_type());
        file_handler.read(reader, position);

        std::vector<long> result;

        long* pointer = (*reader);
        for (; pointer < pointer + reader.get()->getLength() / CHARS_IN_LONG; ++pointer){
            result.emplace_back(pointer);
        }
        return result;
    }

    void write(long position, long index){
        //TODO zrobic
    }
};

#endif //ABSTRACT_PROGRAMMING_INDEXACCESSOR_H
