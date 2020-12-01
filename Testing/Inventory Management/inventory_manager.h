#ifndef INV_M_H_
#define INV_M_H_

#include <includes.h>
#include <inventory.h>
#include <order.h>

class Inventory_Manager {

private:
        Inventory * inventory;
        bool inventory_flag;
        map <int, string> status;
public:
        Inventory_Manager (Inventory * p_inventory);
        
        Inventory * getInventory ();
        bool processOrder (Order * order, long items_id);
        void addToOrder (Order* order, Product * p_item);
        bool getInventoryFlag ();
        bool inventoryStatus ();
        void printStatus ();
        bool deleteStatus(int value);

        ~Inventory_Manager();
};

#endif