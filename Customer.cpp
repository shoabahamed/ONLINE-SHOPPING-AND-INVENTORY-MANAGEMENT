#include "Customer.h"

Customer::Customer(){}
Customer::Customer(string c_name, int c_balance):name{c_name}, balance{c_balance}{
    cout << endl;
    cout << "*******************************************************************************" << endl;
    cout<< "Welcome to our online shopping ceter ABCDSHOP " << c_name
    << " Here you will find all kinds of products ranging"<< endl
    <<"from day to day products to electronics even cars. Choose what type of product do you want to buy: "<<endl;
}
Customer::~Customer(){
    cout << endl;
    cout << "*******************************************************************************" << endl;
    cout << "Thank you. Come again" << endl;
}

//overloading << operator
ostream& operator<<(ostream &out, Customer &c){
    c.show_customer_info();
    return out;
}


void Customer::show_customer_info(){
    cout << endl;
    cout << "*******************************************************************************" << endl;
    cout << "You shopping information: " << endl;
    cout << "Customer Name: " << name << endl;
    cout << "Balance: " << balance << endl;
    cout << "Total cost: " << total_cost << endl;

    int len = items_bought.size();
    //if customer has bought any item then
    if(len > 0){
        for(int i=0; i<len; i++){
            cout << "Item name: " << items_bought[i] << " item costs: " <<  items_cost[i] << endl;
        }
    }
    else{
        cout << "You do not have anything in you shopping cart yet" << endl;
    }

}

//taking input from user what to buy and updates inventory and customer cart at the end
void Customer::buy_item(){
    //taking input from user
    cout << endl;
    string req_product_name;
    int req_amount;
    cout << "Enter the product name you want to buy: ";
    cin >> req_product_name;
    cout << "Enter the amount you want in numbers: ";
    cin >> req_amount;

    //checking if the item specified is in the inventory of not
    bool has_item = false;
    string buy;
    int len = inv.get_items().size();
    vector<string> products = inv.get_items();
    vector<int> amounts = inv.get_item_amounts();
    vector<float> product_costs = inv.get_costs();

    string item_bought;
    int item_amount_avaliable;
    float total_item_cost;
    float per_item_cost;

    for(int i=0; i<len; i++){
        cout << products[i] <<  " "<< req_product_name << endl;
        if(products[i] == req_product_name){
            item_bought = products[i];
            item_amount_avaliable = amounts[i];
            per_item_cost = product_costs[i];
            total_item_cost = product_costs[i] * req_amount;
            has_item = true;
        }
    }


    cout << endl;
    cout << "*******************************************************************************" << endl;
    //if in inventory
    if(has_item){
        //if in inventory but does not have the required amount
        if(req_amount>item_amount_avaliable){
            cout << "You requested " << req_amount << " " << item_bought << " but we only have "
            << item_amount_avaliable << " available choose again" << endl;
            return;
        }
        //if has sufficient amount
        cout << "Item: " << item_bought << endl;
        cout << "Item amount: " << req_amount << endl;
        cout << "Total cost: " << total_item_cost << endl;

        cout << "Confirm buying by writting yes for confirmation and no to go back: ";
        cin >> buy;


        //taking conformation if the user want to buy again
        if(buy == "yes"){
            //if balance is not enough then cancel buy
            if(total_item_cost > balance){
                cout << "You do not have enough money choose again what you want to buy" << endl;
            }
            else{//has enough money
                cout << "*******************************************************************************" << endl
                << "adding " << item_bought << " to shopping curt" << endl;
                //pushing item to customer shopping curt and updating cost
                items_bought.push_back(item_bought);
                items_cost.push_back(total_item_cost);
                balance = balance - total_item_cost;
                total_cost += total_item_cost;
                cout << "You spent " << total_cost << " dollar and have " << balance << " dollar left" << endl;

                //updating inventory after buying
                inv.update_inventory(item_bought, req_amount);
                //updating sells log
                add_to_sells_file(name, item_bought, req_amount, per_item_cost);

            }
        }
        else{//if cancels buying then return
            return;
        }
    }
    else{ //if item does not exit
        cout << "No such item exits. Choose something else" << endl;
        return;
    }
}


//redundant virtual functions setup
void Customer::update_inventory(string, int){};
void Customer::show_inventory(){};
