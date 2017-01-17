#ifndef PROJECT_ABSTRACTREADER_H
#define PROJECT_ABSTRACTREADER_H


#include <istream>

class AbstractReader {
public:
    virtual char * read(int position, int length, std::istream istream, std::ostream ostream) = 0;
};


#endif //PROJECT_ABSTRACTREADER_H
