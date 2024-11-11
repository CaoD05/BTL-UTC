#ifndef GOODS_H
#define GOODS_H

#include <iostream>
#include <string>
using namespace std;


class Goods {
    protected:
        string Name;
        int Id;             
        int Stock;
        double CPrice;
        double SPrice;
        static int NextId;  //Khoi tao id cua hang hao sau*?
        //Time 
    public:
        Goods();
        bool operator <(const Goods& x) const ;
        friend ostream& operator <<(ostream& os,const Goods& d);
        friend istream& operator >>(istream& is, Goods& d);
        void addStock(int addstock);
        void setStock(int newstock);
        int getStock() const;
        string getName() const;
        int getId() const;
        void setId(int id);
        static void preventId();
};
#endif // GOODS_H