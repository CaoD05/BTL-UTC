#include <iostream>
using namespace std;
#include "BigN.cpp"

int main() {
    cout << "Nhap so Fibonacci muon tinh: ";
    int n;
    cin >> n;
    BigN a = BigN::Fibonacci(n);
    cout << "Ket Qua: ";
    a.print();
    cout << "Nhap so giai thua muon tinh: ";
    int i;
    cin >> i;
    BigN b = BigN::fraction(i);
    cout << "Ket qua: ";
    b.print();
    return 0;
}