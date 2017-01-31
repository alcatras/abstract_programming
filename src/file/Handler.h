//
// Created by kamil on 24.01.17.
//

#ifndef ABSTRACT_PROGRAMMING_READER_H
#define ABSTRACT_PROGRAMMING_READER_H


#include <vector>
#include <fstream>
#include <sstream>
#include "DataTypeHandler.h"
#include "../Consts.h"

using namespace consts;

typedef std::vector<long> index_type;


template<typename T>
class Handler : public DataTypeHandler {
protected:
    long address;
    long size;
    T data;

public:
    Handler(long address, long size) : address(address), size(size), data() {}

    T getData() const {
        return data;
    }
};

class IndexHandler : public Handler<index_type> {
    long capacity;
public:
    IndexHandler(long address) : Handler(address, 0) {}

    void read(std::fstream &istream) override {
        long *idx_size = reinterpret_cast<long *>(readNBytes(istream, address, CHARS_IN_LONG));
        long *idx_capacity = reinterpret_cast<long *>(readNBytes(istream, CHARS_IN_LONG));

        capacity = *idx_capacity;

        data.resize((unsigned long) *idx_size);
        size = *idx_size;

        for (long i = 0; i < *idx_size; ++i) {
            long *element = reinterpret_cast<long *>(readNBytes(istream, CHARS_IN_LONG));
            data.push_back(*element);
            delete element;
        }

        delete idx_capacity;
        delete idx_size;
    }

    long write(std::fstream &ostream, Allocator &allocator) override {
        if (capacity <= data.size()) {

            long initSize = (data.size() + 2) * sizeof(long);

            for (int i = 1 << sizeof(long) * 8 - 1;; i >>= 1) {
                if (initSize & i) {
                    i <<= 1;
                    allocator.free(address, size);
                    address = allocator.allocate(ostream, i);
                    capacity = i;
                    break;
                }
            }
        }

        writeNBytes(ostream, address, reinterpret_cast<char *>(&size), sizeof(long));
        writeNBytes(ostream, reinterpret_cast<char *>(&capacity), sizeof(long));

        for (auto it: data) {
            writeNBytes(ostream, reinterpret_cast<char *>(&it), sizeof(long));
        }

        return address;
    }

    void addIndex(long address) {
        data.push_back(address);
    }
};

template<typename Z>
class ValueHandler : public Handler<Z> {
public:
    ValueHandler(long address, long size) : Handler<Z>(address, size) {}

    void read(std::fstream &istream) override {
        Z *d = reinterpret_cast<Z *>(readNBytes(istream, this->address, sizeof(Z) / sizeof(char)));

        this->data = *d;
    }

    long write(std::fstream &ostream, Allocator &allocator) override {
        writeNBytes(ostream, this->address, reinterpret_cast<char *>(&this->data), sizeof(Z));
        return this->address;
    }

    void setData(Z data) {
        data = data;
    }
};

class BinaryHandler : public Handler<char *> {
public:
    BinaryHandler(long address, long size) : Handler(address, size) {}

    void read(std::fstream &istream) override {
        long *bin_size = reinterpret_cast<long *>(readNBytes(istream, address, CHARS_IN_LONG));

        data = readNBytes(istream, *bin_size);
        delete bin_size;
    }

    long write(std::fstream &ostream, Allocator &allocator) override {
        long *bin_size = reinterpret_cast<long *>(readNBytes(ostream, address, CHARS_IN_LONG));

        if (size > *bin_size) {
            allocator.free(address, *bin_size);
            address = allocator.allocate(ostream, size);
        }

        writeNBytes(ostream, address, reinterpret_cast<char *>(size), sizeof(long));
        writeNBytes(ostream, data, size);
        return address;
    }

    void setData(char *ptr, long size) {
        if (data == nullptr)
            delete[] data;

        this->data = ptr;
        this->size = size;
    }
};

class StringHandler : public Handler<std::string> {
public:
    StringHandler(long address) : Handler(address, 0) {}

    void read(std::fstream &istream) override {
        istream.seekg(address);
        std::getline(istream, data, '\0');
        size = data.size();
    }

    long write(std::fstream &ostream, Allocator &allocator) override {
        if (data.size() > size) {
            allocator.free(address, size);
            address = allocator.allocate(ostream, data.size());
        }

        writeNBytes(ostream, address, (char *) data.c_str(), data.size() * sizeof(char));
        return address;
    }

    void setData(std::string &str) {
        this->data = str;
    }
};

#endif //ABSTRACT_PROGRAMMING_READER_H
