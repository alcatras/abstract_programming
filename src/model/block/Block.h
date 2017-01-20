#ifndef ABSTRACT_PROGRAMMING_BLOCK_H
#define ABSTRACT_PROGRAMMING_BLOCK_H


struct Block {
    int position;
    int length;
    void* data;

    Block(int position, int length, void* data) {
        this->position = position;
        this->length = length;
        this->data = data;
    }

    int getPosition() {
        return this->position;
    }

    int getLength() {
        return this->length;
    }

    void* getData() {
        return this->data;
    }
};


#endif //ABSTRACT_PROGRAMMING_BLOCK_H
