#include <iostream>
#include "BigN.h"

BigN::BigN() {}

BigN::BigN(int num) {
    while (num > 0) {
        list.push_front(num % 10);
        num /= 10;
    }
}

void BigN::print() {
    Node* current = list.begin();
    while (current != nullptr) {
        std::cout << current->getData();
        current = current->getNext();
    }
    std::cout << std::endl;
}

BigN BigN::operator*(int n) {
    BigN result;
    int excess = 0;
    Node* a = list.end();
    while (a != nullptr || excess != 0) {
        int sum = excess;
        if (a != nullptr) {
            sum += a->getData() * n;
            a = a->getPrev();
        }
        result.list.push_front(sum % 10);
        excess = sum / 10;
    }
    return result;
}

BigN BigN::operator+(BigN& other) {
    BigN result;
    Node* a = list.end();
    Node* b = other.list.end();
    int excess = 0;

    while (a != nullptr || b != nullptr || excess != 0) {
        int sum = excess;
        if (a != nullptr) {
            sum += a->getData();
            a = a->getPrev();
        }
        if (b != nullptr) {
            sum += b->getData();
            b = b->getPrev();
        }
        result.list.push_front(sum % 10);
        excess = sum / 10;
    }
    return result;
}

BigN BigN::operator*(BigN& other) {
    BigN result;
    int offset = 0;
    Node* a = other.list.end();
    while (a != nullptr) {
        BigN temp = (*this) * a->getData();
        for (int i = 0; i < offset; i++) {
            temp.list.push_back(0);
        }
        result = result + temp;
        offset++;
        a = a->getPrev();
    }
    return result;
}

BigN BigN::operator-(BigN& other) {
    BigN result;
    int borrow = 0;
    Node* a = list.end();
    Node* b = other.list.end();

    while (a != nullptr) {
        int aData = a->getData();
        int bData = (b != nullptr) ? b->getData() : 0;
        if (aData >= bData) {
            result.list.push_front(aData - borrow - bData);
            borrow = 0;
        } else {
            result.list.push_front(aData + 10 - borrow - bData);
            borrow = 1;
        }
        a = a->getPrev();
        if (b != nullptr) b = b->getPrev();
    }
    return result;
}

BigN BigN::Fibonacci(int n) {
    if (n == 0) return BigN(0);
    if (n == 1) return BigN(1);

    BigN a(0);
    BigN b(1);
    for (int i = 2; i <= n; i++) {
        BigN temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

BigN BigN::fraction(int n) {
    BigN result(1);
    for (int i = 2; i <= n; i++) {
        result = result * i;
    }
    return result;
}