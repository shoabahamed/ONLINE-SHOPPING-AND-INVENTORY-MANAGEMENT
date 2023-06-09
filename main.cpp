#include <iostream>
#include "Customer.h"
#include <functional>
#include <algorithm>
using namespace std;

void display();

int main()
{
    string customer_name;
    int balance, user_input;
    bool exitFlag = false;

    display();
    cout << "Enter your name: ";
    getline(cin, customer_name);
    cout << "Enter the amount of money you have to buy products: ";
    cin>>balance;

    Customer c(customer_name, balance);


    while(!exitFlag){
        cout << endl;
        cout << "*******************************************************************************" << endl
        << "Enter 1 to go to Daily Necessity Section "<< endl
        << "Enter 2 to go to Clothes Section " << endl
        << "Enter 3 to go to Technology  Section " << endl
        << "Enter 4 to go to Automobile Section " << endl
        << "Enter 5 to see shopping cart" << endl
        << "Enter 0 to exit our site" << endl;
        cout << endl;
        cin.ignore();
        cout << "Where do you want to go: ";
        cin >> user_input;

        if(user_input == 1 || user_input == 2 || user_input == 3 || user_input == 4){
            c.set_store(user_input);
            c.get_inventory().show_inventory();
            c.buy_item();
        }
        else if(user_input == 5){
            cout << c;
        }
        else{
            exitFlag = true;
        }
    }
    return 0;
}

void display(){
    cout << "##############################  WELCOME TO ABCD SUPER STORE  #####################" << endl;
}

