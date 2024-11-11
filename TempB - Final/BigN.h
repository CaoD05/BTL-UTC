#ifndef BIGN_H
#define BIGN_H

#include "DoubleLinkedList.cpp"

class BigN {
    DoubleLinkedList list;

public:
    BigN();
    BigN(int num);
    void print();
    BigN operator*(int n);
    BigN operator+(BigN& other);
    BigN operator*(BigN& other);
    BigN operator-(BigN& other);
    static BigN Fibonacci(int n);
    static BigN fraction(int n);
};

#endif // BIGN_H