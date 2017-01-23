#ifndef PROJECT_ABSTRACTREADER_H
#define PROJECT_ABSTRACTREADER_H


#include <istream>
#include <memory>

class AbstractReader {
public:
    virtual void read(std::istream& istream, long position) = 0;

    void readDirectly(std::istream& istream, long position, long length, std::unique_ptr<char> ptr) {
        istream.seekg(position);
        char buffer[length];
        istream.read(buffer, length);
        ptr = std::unique_ptr<char>(buffer);
    }
};


#endif //PROJECT_ABSTRACTREADER_H
