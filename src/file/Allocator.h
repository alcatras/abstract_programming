#ifndef ABSTRACT_PROGRAMMING_ALOCATOR_H
#define ABSTRACT_PROGRAMMING_ALOCATOR_H

class Allocator {
public:
    long getPosition(std::fstream &fstream, long length){
        fstream.seekg(0, fstream.end);
        long x = fstream.tellg();
        return x;
//        return 0; //TODO zrobic :D
    };
};

#endif //ABSTRACT_PROGRAMMING_ALOCATOR_H
