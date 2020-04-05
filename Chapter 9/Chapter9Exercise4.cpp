#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int listSize = 8;
struct menuItemType {
    string menuItem;
    double menuPrice;
};
menuItemType menuList[listSize];

void getData(ifstream& inFile, menuItemType menuList[]);
void showMenu(menuItemType menuList[]);
int main()
{
    ifstream inFile("menuItems.txt");

    getData(inFile, menuList);
    showMenu(menuList);

}

void getData(ifstream& inFile, menuItemType menulist[]) {
    for (int i = 0; i < listSize; i++) {
        getline(inFile, menuList[i].menuItem, '$');
        inFile >> menuList[i].menuPrice;
    }
    inFile.close();
}
void showMenu(menuItemType menuList[]) {
    cout << "Welcome to Johnny's Restaurant" << endl;
    cout << showpoint << fixed << setprecision(2);
    for (int i = 0; i < listSize; i++) {
        cout << setw(20) << left << menuList[i].menuItem << right << '$' << menuList[i].menuPrice;
    }
    
}