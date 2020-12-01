#include <order.h>


Order::Order(){
        total_price = 0;
        total_weight = 0;
}
void Order::addToCart (Product * p_product){
        cart.push_back(p_product);
        total_price += p_product->getPrice();
        total_weight += p_product->getWeight();
}
float Order::computeTotalPrice (){

        int price = 0;
        for (int i=0; i<cart.size(); i++){
                price += cart[i]->getPrice();
        }
        total_price = price;
        return total_price;
}
float Order::getTotalPrice (){

        return total_price;

}
float Order::computeTotalWeight (){

        int weight = 0;
        for (int i=0; i<cart.size(); i++){
                weight += cart[i]->getWeight();
        }
        total_weight = weight;
        return total_weight;
}
float Order::getTotalWeight (){

        return total_weight;

}
void Order::printOrder (){

        cout << "\n\nOrder:\n" 
                << "\tUnique_ID"
                << "\tName"
                << "\t\tPrice"
                << "\t\tWeight"
                << "\n";
        
        for (int i=0; i<cart.size(); i++){
                cout << '\t' << cart[i]->getUniqueId() 
                                << "\t\t" << cart[i]->getName() 
                                << "\t\t" << cart[i]->getPrice()
                                << "\t\t" << cart[i]->getWeight() 
                                << '\n';
        }

        cout << "\t\t\t\t\t";
        for (int j=0; j<10; j++){
                cout << "-";
        }
        cout << "\n\t\t\t\tTotal Price: \t" << total_price << "";
        cout << "\n\t\t\t\tTotal Weight: \t" << total_weight << "\n";

}
Order::~Order(){
        
        for (int i=0; i<cart.size(); i++){
                if (cart[i] != NULL){
                        delete cart[i];
                }
        }
        
}
