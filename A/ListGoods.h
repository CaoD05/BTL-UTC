#ifndef LISTGOODS_H
#define LISTGOODS_H
#include "Goods.cpp"
#include <vector>
#include <algorithm>

class ListGoods {
    private:
        vector<Goods> items;       
    public:
        void Add(const Goods& a);
        void Display() const;
        void SortByStock();
        const Goods* FindMaxStock();
        const Goods* FindMinStock();
        Goods* SearchById(const int id);
        void RemoveById(const int id);
        void Modify();
};
#endif