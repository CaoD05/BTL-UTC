#include <iostream>
#include "ListGoods.cpp"
using namespace std;

class App {
private:
    ListGoods listGoods;
public:
    void Menu();
};

void App::Menu() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Goods\n";
        cout << "2. Display All Goods\n";
        cout << "3. Sort Goods by Stock\n";
        cout << "4. Find Goods with Max Stock\n";
        cout << "5. Find Goods with Min Stock\n";
        cout << "6. Remove Goods by ID\n";
        cout << "7. Search Goods by ID\n";
        cout << "8. Modify Stock of existing Goods\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                Goods g;
                cin >> g;
                listGoods.Add(g);
                int c;
                do {
	                cout << "Do you want to continue?\n";
	                cout << "1. Yes" << endl << "2. No\n";
	                cin >> c;
	                cin.ignore();
                	switch (c) {
                	case 1: {
                		Goods e;
                		cin >> e;
                		listGoods.Add(e);
						break;
					}
					case 2: {
						cout << "Exiting...\n";
						break;
					}
					default:
						cout << "Invalid choice. Try again.\n";
		                system("pause");
		              	system("cls");
		                break;
					}
            	} while (c!=2);
				system("pause");
              	system("cls");
                break;
            }
            case 2: {
                listGoods.Display();
                system("pause");
              	system("cls");
                break;
            }
            case 3: {
                listGoods.SortByStock();
                cout << "Goods sorted by stock.\n";
                system("pause");
              	system("cls");
                break;
            }
            case 4: {
                const Goods* maxStock = listGoods.FindMaxStock();
                if(maxStock == nullptr){
                	cout << "There are no item!\n";
				} else {
					cout << "Goods with max stock:\n" << *maxStock << endl;
				}
                system("pause");
              	system("cls");
                break;
            }
            case 5: {
                const Goods* minStock = listGoods.FindMinStock();
                if(minStock == nullptr){
                	cout << "There are no item!\n";
				} else {
                	cout << "Goods with min stock:\n" << *minStock << endl;
                }
                system("pause");
              	system("cls");
                break;
            }
            case 6: {
                int id;
                cout << "Enter ID to remove: ";
                cin >> id;
                listGoods.RemoveById(id);
                cout << "Goods removed.\n";
                system("pause");
              	system("cls");
                break;
            }
            case 7: {
                int id;
                cout << "Enter ID to search: ";
                cin >> id;
                Goods* found = listGoods.SearchById(id);
                if (found) {
                    cout << "Goods found:\n" << *found<< endl;
                } else {
                    cout << "Goods not found.\n" << endl;
                }
                system("pause");
              	system("cls");
                break;
            }
            case 8: {
                listGoods.Modify();
                system("pause");
              	system("cls");
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                system("pause");
              	system("cls");
                break;
        }
    } while (choice != 0);
}