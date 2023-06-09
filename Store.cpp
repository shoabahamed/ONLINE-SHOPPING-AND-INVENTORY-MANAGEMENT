#include "Store.h"

Store::Store(){}

//return store_type
void Store::get_store_type(){
    cout << "Store name: " << store_type <<endl;
}
//get total cell by each customer at any given time
void Store::get_total_sell(){
    cout << "Total sell: " << total_sell << endl;
}

//set up store and inventory type after taking input from user
void Store:: set_store(int input){
    string st_name;
    if(input == 1)
        st_name = "grocery";
    else if(input == 2)
        st_name = "clothes";
    else if(input == 3)
        st_name = "tech";
    else
        st_name = "cars";

    store_type = st_name;
    inv.set_inventory(st_name);
    inv.set_values();
}

//return inventory object from user
Inventory Store::get_inventory(){
    return inv;
}
