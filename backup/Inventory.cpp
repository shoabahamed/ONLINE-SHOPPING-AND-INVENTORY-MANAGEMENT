#include "Inventory.h"
#include <string>
Inventory::Inventory(){}

//show inventory of the selected section from user
void Inventory::show_inventory(){
    set_values();//setting up inventory of particular section
    int len = items.size();

    //display proudcts to user for the particular section
    cout << endl;
    cout << "*******************************************************************************" << endl
    << "Welcome to " << inventory_name << " section. We have the following items available right now" << endl;
    cout << "Item----------------------Amount---------------------Cost Per Item" << endl;
    cout << endl;
    for(int i=0; i<len; i++){
        cout <<  items[i] << "---------------->"
        << amount_of_items[i] << "---------------->"
        << costs[i]<<  endl;
    }
}

//after customer buy anything then updates the inventory of that section
void Inventory::update_inventory(string item_bought, int item_bought_amount){
    int len = items.size();
    int item_remained;
    int item_bought_index;

    //finding the index of item which need to be deleted
    for(int i=0; i<len; i++){
        if(items[i] == item_bought){
            item_bought_index = i;
            break;
        }
    }

    //updating item amount left in inventory after  buying
    item_remained = amount_of_items[item_bought_index] - item_bought_amount;

    //if item remained than updated the item amount
    if(item_remained){
        amount_of_items[item_bought_index] = item_remained;
    }//if item not remained then delete from inventory
    else{
        items.erase(items.begin() + item_bought_index);
        amount_of_items.erase(amount_of_items.begin() + item_bought_index);
        costs.erase(costs.begin() + item_bought_index);
    }

    //updating inventory
    ofstream fout;
    if(inventory_name == "tech")
        fout.open("./inventory/tech.txt");
    else if(inventory_name == "clothes")
        fout.open("./inventory/clothes.txt");
    else if(inventory_name == "cars")
        fout.open("./inventory/cars.txt");
    else
        fout.open("./inventory/grocery.txt");

    if(!fout){
        cout << "Not able to find the file";
    }
    else{
        len = items.size();
        for(int i=0; i<len; i++){
            fout << items[i] << " " << amount_of_items[i] << " " << costs[i] << "\n"; // putting items in file
        }
    }
}

//setting up inventory name recieved from store_type
void Inventory::set_inventory(string inv_name){
    inventory_name = inv_name;
}

//setting up inventory for particular sections
void Inventory::set_values(){
//  clearing any elements from inventory informations arrays
    items.clear();
    amount_of_items.clear();
    costs.clear();

//  taking input from file and saving in three arrays
    ifstream fin;
    if(inventory_name == "tech")
        fin.open("./inventory/tech.txt");
    else if(inventory_name == "clothes")
        fin.open("./inventory/clothes.txt");
    else if(inventory_name == "cars")
        fin.open("./inventory/cars.txt");
    else
        fin.open("./inventory/grocery.txt");

    if(!fin){
        cout << "Not able to find the file";
    }
    else{
        string line;
        string product_name;
        int product_amount;
        float product_cost;

        //reading each line and splitting in three parts then pushing them to vector
        while(getline(fin, line)){
            if(!line.empty()){
                istringstream iss(line);
                iss >> product_name >> product_amount >> product_cost;
                //pushing in vectors
                items.push_back(product_name);
                amount_of_items.push_back(product_amount);
                costs.push_back(product_cost);
            }
        }
    }
}

//return item lists in inventory
vector<string> Inventory::get_items(){
    return items;
}
//return item amounts in inventory
vector<int> Inventory::get_item_amounts(){
    return amount_of_items;
}
//return item costs in inventory
vector<float> Inventory::get_costs(){
    return costs;
}

//setting up redundant virtual methods
void Inventory::show_customer_info(){};
void Inventory::buy_item(){};
