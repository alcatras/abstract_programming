#ifndef PROJECT_ABSTRACTREADER_H
#define PROJECT_ABSTRACTREADER_H


#include <istream>

template<typename T = char *>
class AbstractReader {
public:
    virtual T read(std::istream &istream, long position, long length) = 0;
};


#endif //PROJECT_ABSTRACTREADER_H
