#include "SuperStore.h"

SuperStore::SuperStore(){}

//show superstore information
void SuperStore::get_website_info(){
    cout << "Website name: " << SuperStore::website_name << endl;
    cout << "Website company: " << SuperStore::company_name << endl;
}

void SuperStore::add_to_sells_file(string cs_name, string cs_product, int cs_amount,  float cs_cost){
    //updating inventory
    ofstream fout("./inventory/sells_log.txt", ios_base::app);

    if(!fout){
        cout << "Not able to find the file";
    }
    else{

        fout << cs_name << " " << cs_product << " " << cs_amount << " " <<  cs_cost << "\n"; // putting items in file

    }
}

//defining static website name and company name
string SuperStore::website_name = "ABCDSHOP";
string SuperStore::company_name = "ABCDLIMITED";
