#ifndef PROJECT_ABSTRACTREADER_H
#define PROJECT_ABSTRACTREADER_H

#include <istream>
#include <memory>

class AbstractReader {
public:
    virtual void read(std::istream& istream, long position) = 0;
    virtual long getLength() = 0;

    char* readDirectly(std::istream& istream, long position, long length) {
        istream.seekg(position);
        char *buffer = new char[length];
        istream.read(buffer, length);
        return buffer;
    };
};

#endif //PROJECT_ABSTRACTREADER_H
