#ifndef INVENTORY_H
#define INVENTORY_H
#include "SuperStore.h"



class Inventory:public SuperStore
{
    public:
        Inventory();

        //virtual inherited functions
        void show_customer_info();
        void buy_item();
        void update_inventory(string, int);
        void show_inventory();

        //internal non inherited methods
        void set_inventory(string);
        void set_values();
        vector<string> get_items();
        vector<int> get_item_amounts();
        vector<float> get_costs();




    protected:
        vector<string> items;
        vector<int> amount_of_items;
        vector<float> costs;
        string inventory_name;

};

#endif // INVENTORY_H
