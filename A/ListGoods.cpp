#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

#include "ListGoods.h"


void ListGoods::Add(const Goods& a){
    //Check xem co ton tai item day trong danh sach k* neu co thi add stock
    for(auto &item : items){
        if(item.getName() == a.getName()){
            item.addStock(a.getStock());
            cout <<"Updated Stock for "<< item.getName() <<endl;
            Goods::preventId();
            return;
        }
    }
    items.push_back(a);
    cout <<"Added new item"<< endl;

}

void ListGoods::Display() const {
	if(items.empty()){
		cout<<"Items empty!"<<endl;
	} else {
	    for(auto item : items){
	        cout << item <<endl;
	    }
	}
}

void ListGoods::SortByStock(){
    sort(items.begin(), items.end());
}

const Goods* ListGoods::FindMaxStock(){
	if(items.empty()){
		return nullptr;
	} else {
		return &(*max_element(items.begin(), items.end()));        //con tro de tra thang vao items max 
	}
}

const Goods* ListGoods::FindMinStock(){
	if(items.empty()){
		return nullptr;
    } else return &(*min_element(items.begin(), items.end()));        //con tro de tra thang vao items min
}

Goods* ListGoods::SearchById(const int id) {
    for(auto& item : items){
        if(item.getId() == id){
            return &item;
        }
    }
    return nullptr;
}

void ListGoods::RemoveById(const int id){
    items.erase(remove_if(items.begin(), items.end(), [id](Goods& item) { return item.getId() == id; }), items.end());
}

void ListGoods::Modify(){
    int id;
    int choice;
    int stock;
	if(items.empty()){
		cout<<"Items empty!"<<endl;
		return;
	} else {
	    for(const auto& item : items){
	        cout << item <<endl;
	    }
	    cout << endl << "Enter ID to modify: ";
	    cin >> id;
	    for(auto& a : items){
	    	if(a.getId() == id){
	    		cout << "Item selected" << endl;
    			cout << "Choose an option:\n";
    			cout << "1. Add stock to existing stock." << endl;
    			cout << "2. Change current Stock." << endl;
    			cout << "0. Exit" << endl;
    			cout << "Enter your choice: ";
    			cin >> choice;
    			cin.ignore();
    			switch (choice) {
    				case 1: {
    					cout << "Input how much stock you want to add: ";
    					cin >> stock;
    					a.addStock(stock);
    					cout << "Success!\n";
						break;
					}
					case 2: {
						cout << "Input new stock: ";
						cin >> stock;
						a.setStock(stock);
						cout << "Success!\n";
						break;
					}
					case 0: {
						cout << "Exiting...\n";
						break;
					}
					default:
		                cout << "Invalid choice. Try again.\n";
		                break;
				}
			return;
			}
		}
		cout << "No items found!\n";
	}
}
