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
void Store:: set_store(string st_name){
    store_type = st_name;
    inv.set_inventory(st_name);
    inv.set_values();
}

//return inventory object from user
Inventory Store::get_inventory(){
    return inv;
}
