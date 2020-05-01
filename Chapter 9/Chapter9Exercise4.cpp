/*
Write a program to help a local restaurant automate its breakfast billing system. The program should do the following:

Show the customer the different breakfast items offered by the restaurant.

Allow the customer to select more than one item from the menu.

Calculate and print the bill.

Assume that the restaurant offers the following breakfast items (the price of each item is shown to the right of the item):

Plain Egg 	$1.45
Bacon and Egg 	$2.45
Muffin	$0.99
French Toast	$1.99
Fruit Basket	$2.49
Cereal	$0.69
Coffee	$0.50
Tea	$0.75

Function getData: This function loads the data into the array menuList.

Function showMenu: This function shows the different items offered by the restaurant and tells the user how to select the items.

Function printCheck: This function calculates and prints the check. (Note that the billing amount should include a 5% tax.) A sample output is:

Welcome to Johnny's Restaurant

Bacon and Egg      $2.45

Muffin     $0.99

Coffee     $0.50
Tax    $0.20
Amount Due     $4.14

Format your output with two decimal places. The name of each item in the output must be left justified. You may assume that the user selects only one item of a particular type.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int listSize = 8;
char customerOrder[20];
const double TAX_RATE = 5.00;
int orderCount = 0;

struct menuItemType {
    string menuItem;
    double menuPrice;
};
menuItemType menuList[listSize];

void getData(ifstream& inFile, menuItemType menuList[]);
char showMenu(menuItemType menuList[]);
void printCheck(char customerOrder[], menuItemType menuList[]);

int main()
{
    ifstream inFile("menuItems.txt");

    getData(inFile, menuList);
    showMenu(menuList);
    printCheck(customerOrder, menuList);

}

void getData(ifstream& inFile, menuItemType menulist[]) {
    for (int i = 0; i < listSize; i++) {
        getline(inFile, menuList[i].menuItem, '$');
        inFile >> menuList[i].menuPrice;
    }
    inFile.close();
}
char showMenu(menuItemType menuList[]) {
    int counter = 0;
    cout << "Welcome to Johnny's Restaurant" << endl;
    cout << showpoint << fixed << setprecision(2);
    for (int i = 0; i < listSize; i++) {
        cout << setw(15) << left << menuList[i].menuItem << right << '$' << menuList[i].menuPrice;

    }
    cout << endl;
    cout << "Select a corresponding number between 1-8 for what you would like to order:  ";
    cin >> customerOrder[counter];
    while (customerOrder[counter] != 'N' && customerOrder[counter] != 'n') {
        counter ++;
        cout << "Would you like to order another menu item? Select a number 1-8 to order or 'N' to stop: ";
        cin >> customerOrder[counter];
        orderCount++;
    }
    return customerOrder[19];
}
void printCheck(char customerOrder[], menuItemType menuList[]) {
    double totalBeforeTax = 0.00, totalAfterTax = 0.00, tax;
    cout << "Welcome to Johnny's Restaurant" << endl;
    
    for (int i = 0; i < listSize; i++) {
        if (customerOrder[i] == '1') {
            cout << menuList[0].menuItem << "   $" << menuList[0].menuPrice << endl;
            totalBeforeTax += menuList[0].menuPrice;
        }
        else if (customerOrder[i] == '2') {
            cout << menuList[1].menuItem << "   $" << menuList[1].menuPrice << endl;
            totalBeforeTax += menuList[1].menuPrice;
        }
        else if (customerOrder[i] == '3') {
            cout << menuList[2].menuItem << "   $" << menuList[2].menuPrice << endl;
            totalBeforeTax += menuList[2].menuPrice;
        }
        else if (customerOrder[i] == '4') {
            cout << menuList[3].menuItem << "   $" << menuList[3].menuPrice << endl;
            totalBeforeTax += menuList[3].menuPrice;
        }
        else if (customerOrder[i] == '5') {
            cout << menuList[4].menuItem << "   $" << menuList[4].menuPrice << endl;
            totalBeforeTax += menuList[4].menuPrice;
        }
        else if (customerOrder[i] == '6') {
            cout << menuList[5].menuItem << "   $" << menuList[5].menuPrice << endl;
            totalBeforeTax += menuList[5].menuPrice;
        }
        else if (customerOrder[i] == '7') {
            cout << menuList[6].menuItem << "   $" << menuList[6].menuPrice << endl;
            totalBeforeTax += menuList[6].menuPrice;
        }
        else if (customerOrder[i] == '8') {
            cout << menuList[7].menuItem << "   $" << menuList[7].menuPrice << endl;
            totalBeforeTax += menuList[7].menuPrice;
        }
    }
    
    tax = totalBeforeTax * (TAX_RATE / 100);
    totalAfterTax = totalBeforeTax + tax;
    cout << "Tax    $" << tax << endl;
    cout << "Amount Due     $" << totalAfterTax;
}
