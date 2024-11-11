#include <iostream>
#include <limits>
#include "Goods.h"
using namespace std;

Goods::Goods() {
    Id = NextId++;      //Tu dong khoi gan id cua item nhap sau day*
};

bool Goods::operator <(const Goods& x) const {             //Toan tu so sang so luong
    return this->Stock < x.Stock;
};

void Goods::addStock(int addstock){ Stock += addstock; };

void Goods::setStock(int newstock){ Stock = newstock; };

int Goods::getStock() const { return Stock; };

string Goods::getName() const { return Name; };

int Goods::getId() const { return Id; };

void Goods::setId(int id) { Id = id; };

void Goods::preventId() { NextId--; };	//Dung de ngan viec tao id moi khi update stock;

//Auto Assign Id to new item (new to old) * 10001 --- NextId++ (cong sau)
int Goods::NextId = 10001; // Starting ID

ostream& operator <<(ostream& os, const Goods& d){
    os << "Name: " << d.Name << endl;
    os << "Id: " << d.Id << endl;
    os << "Stock: " << d.Stock << endl;
    os << "Cost Price: " << d.CPrice << endl;
    os << "Sell Price: " << d.SPrice << endl;
    return os;
}

string deleteSpace(const string& input) {
    size_t end = input.size();
    
    while (end > 0 && input[end - 1] == ' ') {
        --end;
    }
    
    return input.substr(0, end);
}

istream& operator>>(istream& is, Goods& d) {
    cout << "Name?: ";
    getline(is, d.Name);
    d.Name = deleteSpace(d.Name);		//Remove any Space left in the back :v
    // Validate Stock input
    cout << "Number of Stocks?: ";
    is >> d.Stock;
    while (is.fail()) {
        cout << "Invalid input for Stock! Please enter a valid integer: ";
        is.clear(); // Clear the error state
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        is >> d.Stock;
    }
    cout << "Cost Price?: ";
    is >> d.CPrice;
    while (is.fail()) {
        cout << "Invalid input for Cost Price! Please enter a valid number: ";
        is.clear(); 
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        is >> d.CPrice;
    }
    cout << "Sell Price?: ";
    is >> d.SPrice;
    while (is.fail()) {
        cout << "Invalid input for Sell Price! Please enter a valid number: ";
        is.clear(); 
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        is >> d.SPrice;
    }
    is.ignore(); // Clear the newline character left in the input buffer
    return is;
}