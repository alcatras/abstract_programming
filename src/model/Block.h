#ifndef ABSTRACT_PROGRAMMING_BLOCK_H
#define ABSTRACT_PROGRAMMING_BLOCK_H

struct Block {
    int length;
    const char* data;

    Block(int length, char* data) {
        this->length = length;
        this->data = data;
    }
};

#endif //ABSTRACT_PROGRAMMING_BLOCK_H
