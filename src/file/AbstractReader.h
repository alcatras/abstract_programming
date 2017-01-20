#ifndef PROJECT_ABSTRACTREADER_H
#define PROJECT_ABSTRACTREADER_H


#include <istream>

template<typename T = char *>
class AbstractReader {
public:
    virtual void read(std::istream& istream) = 0;
//    virtual T getData() = 0;
    };


#endif //PROJECT_ABSTRACTREADER_H
