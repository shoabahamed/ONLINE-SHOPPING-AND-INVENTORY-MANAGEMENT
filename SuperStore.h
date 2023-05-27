#ifndef SUPERSTORE_H
#define SUPERSTORE_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class SuperStore
{
    public:
        SuperStore();
        static void get_website_info();
        virtual void show_inventory() = 0;
        virtual void show_customer_info() = 0;
        virtual void buy_item() = 0;

        void add_to_sells_file(string, string, int,  float);

    protected:
        static string website_name;
        static string company_name;

    private:


};

#endif // SUPERSTORE_H
