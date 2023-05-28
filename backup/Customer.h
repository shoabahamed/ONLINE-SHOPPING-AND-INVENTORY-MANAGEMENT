#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Store.h"


class Customer : public Store
{
    public:
        Customer();
        Customer(string, int);
        ~Customer();

        //virtual inherited functions
        void show_customer_info();
        void buy_item();
        void update_inventory(string, int);
        void show_inventory();

        //operator overloading method
        friend ostream& operator<<(ostream &out, Customer &c);

    protected:
        string name;
        int balance;
        vector<string> items_bought;
        vector<float> items_cost;
        float total_cost = 0;

};

#endif // CUSTOMER_H
