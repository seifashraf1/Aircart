#include <inventory_manager.h>

Inventory_Manager::Inventory_Manager (Inventory * p_inventory){
        inventory = p_inventory;
}
        
Inventory * Inventory_Manager::getInventory (){
        if (inventory != NULL){
                return inventory;
        }
}
void Inventory_Manager::addToOrder (Order * order, Product* p_item){
        order->addToCart(p_item);
}

bool Inventory_Manager::processOrder (Order * order, long items_id){
        
        if (inventory != NULL){
                Product * item = inventory->getProduct(items_id);
                if (item->getUniqueId() != 0 && item->getQuantity() > 0){
                        int quantity = item->decQuantity();
                        this->addToOrder(order, item);
                        if (quantity <= MIN_STOCK){
                                string problem;
                                problem = "Item " + to_string(items_id) 
                                        + " with name " + inventory->getProduct(items_id)->getName() 
                                        + " is needs re-stocking!";
                                status.insert(pair<int, string>(items_id, problem));  
                        }
                        return true;
                }
                cout << "\t\t\tError! Item Unvailable.";
        }
        return false;
}


bool Inventory_Manager::getInventoryFlag (){
        return inventory_flag;
}
void Inventory_Manager::printStatus (){
        
        cout << "\n\t";
        for (int i=0; i<50; i++)
                cout << "-";
        cout << "\n\tStatus ID"
                << "\tStatus\n";
        map<int, string>::iterator itr;
        for (itr = status.begin(); itr != status.end(); ++itr) { 
                cout << "\t" << itr->first 
                        << "\t\t" << itr->second 
                        << '\n';
        }
}
bool Inventory_Manager::deleteStatus (int value){
        
        if (inventory->getProduct(value)->getQuantity() > MIN_STOCK){
                return status.erase(value);
        }
        else {
                return false;
        }
}

bool Inventory_Manager::inventoryStatus (){
        
        if (inventory != NULL){
                int id = inventory->checkQuantities();
                if (id != 0){
                        string problem;
                        problem = "Item " + to_string(id) 
                                + " with name " + inventory->getProduct(id)->getName() 
                                + " is needs re-stocking. Only " + to_string(inventory->getProduct(id)->getQuantity())
                                + " left!";
                        status.insert(pair<int, string>(id, problem));
                }
        }
        return false;

}

Inventory_Manager::~Inventory_Manager(){
        if (inventory != NULL){
                delete inventory;
        }
}