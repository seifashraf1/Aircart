#include <inventory.h>


Inventory::Inventory (){
        inventory.insert(pair<long, Product*>(0, new Product(0, "-", 0, 0, 100)));
}

bool Inventory::addProduct (Product * p_product){
        
        long unique_id = p_product->getUniqueId();
        if (inventory.find(unique_id) == inventory.end()){
                inventory.insert(pair<long, Product*>(unique_id, p_product));
                return true;
        }
        else {
                return false;
        }
}

bool Inventory::removeProduct (long unique_id){
        
        if (inventory.erase(unique_id) == 0){
                return false;
        }
        else {
                return true;
        }
}

Product * Inventory::getProduct (long unique_id){

        if (inventory.find(unique_id) == inventory.end()){
                return inventory.at(unique_id);
        }
        else {
                return inventory.at(unique_id);;
        }
}

long Inventory::checkQuantities (){
        
        map<long, Product*>::iterator itr;
        for (itr = inventory.begin(); itr != inventory.end(); ++itr) { 
                if (itr->second->getQuantity() <= MIN_STOCK){
                        return itr->first;
                }
        }
        return 0;
}

void Inventory::printInventory (){

        map<long, Product*>::iterator itr;
        
        cout << "Inventory:\n" 
                << "\tUnique_ID"
                << "\tName"
                << "\t\tPrice"
                << "\t\tWeight"
                << "\t\tLeft In Stock"
                << "\n";

        for (itr = inventory.begin(); itr != inventory.end(); ++itr) { 
                if (itr->first != 0)
                        cout << '\t' << itr->first 
                                << "\t\t" << itr->second->getName() 
                                << "\t\t" << itr->second->getPrice()
                                << "\t\t" << itr->second->getWeight()
                                << "\t\t" << itr->second->getQuantity()   
                                << '\n'; 
        }
}

Inventory::~Inventory (){

        map<long, Product*>::iterator itr;
        for (itr = inventory.begin(); itr != inventory.end(); ++itr) { 
                if (itr->second != NULL){
                        delete itr->second;
                }
        }

}