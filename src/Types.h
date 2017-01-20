//
// Created by kamil on 20.01.17.
//

#ifndef ABSTRACT_PROGRAMMING_TYPES_H
#define ABSTRACT_PROGRAMMING_TYPES_H


struct Type {

};

template<typename T>
struct type_traits {
    static constexpr const char *name = "default";
    static constexpr long size = 0;
};

struct BinaryType : Type {
    long ptr;
};

template<>
struct type_traits<BinaryType> {
    static constexpr const char *name = "binary";
    static constexpr long size = sizeof(long);
};

struct IntegerType : Type {
    long value;
};

template<>
struct type_traits<IntegerType> {
    static constexpr const char *name = "integer";
    static constexpr long size = sizeof(long);
};

struct RealType : Type {
    double value;
};

template<>
struct type_traits<RealType> {
    static constexpr const char *name = "real";
    static constexpr long size = sizeof(double);
};

struct StringType : Type {
    long ptr;
};

template<>
struct type_traits<StringType> {
    static constexpr const char *name = "string";
    static constexpr long size = sizeof(long);
};


#endif //ABSTRACT_PROGRAMMING_TYPES_H
