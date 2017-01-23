//#ifndef ABSTRACT_PROGRAMMING_DATAREADER_H
//#define ABSTRACT_PROGRAMMING_DATAREADER_H
//
//
//#include <iostream>
//#include <memory>
//#include "../Consts.h"
//
//using namespace consts;
//
//class DataReader {
//public:
//    std::unique_ptr<char> read(std::istream& istream, long position, long length) {
////        istream.seekg(0).seekg(position);
//        istream.seekg(position);
//        long binary_length;
//        istream.read(reinterpret_cast<char*>(&binary_length), CHARS_IN_LONG);
//
//        char* buffer = new char[binary_length];
//        istream.read(buffer, binary_length);
//        std::unique_ptr<char> ptr(buffer);
//
//        return ptr;
//    }
//
//};
//
//
//#endif //ABSTRACT_PROGRAMMING_DATAREADER_H
//TODO usunac
