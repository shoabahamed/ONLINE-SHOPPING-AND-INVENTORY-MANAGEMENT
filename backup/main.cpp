#include <iostream>
#include "Customer.h"
//building in using different version may cause problems so if other version of the compiler is used please
//delete the .o files first them compile
using namespace std;

int main()
{
    string customer_name, user_input;
    int balance;
    bool exitFlag = false;

    cout << "Enter your name: ";
    getline(cin, customer_name);
    cout << "Enter the amount of money you have to buy products: ";
    cin>>balance;

    Customer c(customer_name, balance);


    while(!exitFlag){
        cout << endl;
        cout << "*******************************************************************************" << endl
        << "Enter grocery to go to Daily Necessity Section "<< endl
        << "Enter clothes to go to Clothes Section " << endl
        << "Enter tech to go to Technology  Section " << endl
        << "Enter cars to go to Automobile Section " << endl
        << "Enter cart to see shopping cart" << endl
        << "Enter quit to exit our site" << endl
        << "Caution enter small letter only" << endl;
        cout << endl;
        cin.ignore();
        cout << "Where do you want to go: ";
        cin >> user_input;

        if(user_input == "grocery" || user_input == "tech" || user_input == "cars" || user_input == "clothes"){
            c.set_store(user_input);
            c.get_inventory().show_inventory();
            c.buy_item();
        }
        else if(user_input == "cart"){
            cout << c;
        }
        else{
            exitFlag = true;
        }
    }
    return 0;
}
