#ifndef STORE_H
#define STORE_H
#include "SuperStore.h"
#include "Inventory.h"

class Store: public SuperStore
{
    public:
        Store();

        //internal non inherited methods
        void get_store_type();
        void get_total_sell();
        void set_store(string);
        Inventory get_inventory();

    protected:
        string store_type;
        int total_sell=0;
        Inventory inv;

};

#endif // STORE_H
