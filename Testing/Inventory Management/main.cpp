#include <includes.h>
#include <inventory.h>
#include <inventory_manager.h>
#include <order.h>

#define CHAR_NUM 100

void printFrontEnd ();
void printBackEnd ();

int main (){

        Inventory_Manager inventory_manager(new Inventory);
        
        inventory_manager.getInventory()->addProduct(new Product(1, "iPhone", 1000, 2, 8));
        inventory_manager.getInventory()->addProduct(new Product(2, "Samsung", 999, 1.9, 9));
        inventory_manager.getInventory()->addProduct(new Product(3, "OnePlus", 899.99, 2.1, 7));
        inventory_manager.getInventory()->addProduct(new Product(4, "MacBook", 2000, 4, 6));
        inventory_manager.getInventory()->addProduct(new Product(5, "Dell", 2200, 3.1, 7));
        inventory_manager.getInventory()->addProduct(new Product(6, "Lenovo", 1500, 5.3, 10));
        inventory_manager.getInventory()->addProduct(new Product(7, "Desktop", 1800, 10, 11));
        inventory_manager.getInventory()->addProduct(new Product(8, "Monitor", 600, 12, 8));
        inventory_manager.getInventory()->addProduct(new Product(9, "Mouse", 200, 1.5, 12));

        vector <Order*> orders;

        while (true){

                printFrontEnd();
                
                inventory_manager.getInventory()->printInventory();

                int num;
                orders.push_back(new Order());
                while (true){
                        cout << "\n\tWrite item ID to add to cart (enter 0 to order): ";
                        cin >> num;
                        if (num == 0) break;
                        inventory_manager.processOrder(orders[orders.size()-1], num);
                        // if (!inventory_manager.processOrder(num)) break;
                }

                orders[orders.size()-1]->printOrder();
                
                printBackEnd ();
                

                int id, amount;
                while (true){
                        inventory_manager.getInventory()->printInventory();
                        inventory_manager.printStatus();
                        cout << "\n\tWrite item ID to re-stock (enter 0 to exit): ";
                        cin >> id;
                        if (id == 0) break;
                        cout << "\n\tWrite amount being re-stocked (enter 0 to exit): ";
                        cin >> amount;
                        cout << "\n";
                        if (amount == 0) break;
                        inventory_manager.getInventory()->getProduct(id)->incQuantity(amount);
                        inventory_manager.deleteStatus(id);
                }

        }
}

void printFrontEnd (){

        printf("\n\n\n");
        for (int i=0; i<CHAR_NUM; i++){
                printf("=");
        }
        printf("\n");

        cout << "Front-End (User Side): \n\n\n";

}

void printBackEnd (){

        printf("\n\n\n");
        for (int i=0; i<CHAR_NUM; i++){
                printf("+");
        }
        printf("\n");

        cout << "Back-End (Employee Side): \n\n\n";

}