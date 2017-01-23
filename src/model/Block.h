#ifndef ABSTRACT_PROGRAMMING_BLOCK_H
#define ABSTRACT_PROGRAMMING_BLOCK_H

struct Block {
    int position;
    int length;
    const char* data;

    Block(int position, int length, char* data) {
        this->position = position;
        this->length = length;
        this->data = data;
    }
};

#endif //ABSTRACT_PROGRAMMING_BLOCK_H
