#include <bits/stdc++.h>
#include "User_DB.h"
using namespace std;

int main () {

    Card card1 ("Seif", "5613549512364792", "486", 12, 2020);
    Card card2 ("Sherif", "4595321598743265", "913", 11, 2021);
    Card card3 ("Karim", "1236458951364237", "793", 10, 2022);

    User * user1  = new User ("Sefo", "sefo1234", "seifeldinashraf11@aucegypt.edu", 56.11631, 13.23216);
    User * user2  = new User ("Shefo", "shefo1234", "sherif.gabr@aucegypt.edu", 50.23163, 11.61633);
    User * user3  = new User ("Kemo", "kemo1234", "kareemikassab@aucegypt.edu", 40.79456, 5.61329);

    user1->addCard(card1);
    user2->addCard(card2);
    user3->addCard(card3);

    User_DB AirCartUsers;

    AirCartUsers.addUser(user1);
    AirCartUsers.addUser(user2);
    AirCartUsers.addUser(user3);

    string username;
    string password;
    string email;
    float x, y;
    string name;
    string card_number;
    string cvc;
    int exp_month, exp_year;
    
    vector <User *> users;
    users.push_back(user1);
    users.push_back(user2);
    users.push_back(user3);


    int options = 1;

    while (options != 0){

        cout << "-------------------------------\n";
        cout << "Options:\n";
        cout << "\t0: Terminate\n";
        cout << "\t1: Log In\n";
        cout << "\t2: Register\n";
        cout << "\t3: Delete Account\n";
        cout << "-------------------------------\n";

        cout << "Pick action: ";
        cin >> options;
        cout << "-------------------------------\n";
        if (options == 0){
            break;
        } else if (options == 1){
            cout << "Log In\n";
            cout << "\tEnter Your Username: ";
            cin >> username;
            cout << "\tEnter Your Password: ";
            cin >> password;
            AirCartUsers.authenticate_user(username, password);
        } else 
            if (options == 2){
                cout << "Register\n";
                cout << "\tEnter Username: ";
                cin >> username;
                cout << "\tEnter Password: ";
                cin >> password;
                cout << "\tEnter Email: ";
                cin >> email;
                cout << "\tEnter Your x-location: ";
                cin >> x;
                cout << "\tEnter Your y-location: ";
                cin >> y;
                users.push_back(new User (username, password, email, x, y));
                AirCartUsers.addUser(users[users.size()-1]);
                cout << "\tCard Information:\n";
                cout << "\t\tEnter card holder name: ";
                cin >> name;
                cout << "\t\tEnter card number: ";
                cin >> card_number;
                cout << "\t\tEnter card CVC: ";
                cin >> cvc;
                cout << "\t\tEnter card expiry month: ";
                cin >> x;
                cout << "\t\tEnter card expiry year: ";
                cin >> y;
                Card * temp_card = new Card (name, card_number, cvc, x, y);
                users[users.size()-1]->addCard(*temp_card);
                cout << "Registered Successfully\n";
        } else 
            if (options == 3){
                cout << "Deleting Account\n";
                cout << "\tEnter Your Username: ";
                cin >> username;
                cout << "\tEnter Your Email: ";
                cin >> email;
                cout << "\tEnter Your Password: ";
                cin >> password;
                if (AirCartUsers.authenticate_user(username, password)){
                    AirCartUsers.deleteUser(username, email);
                } else {
                    cout << "Cannot delete account\n";
                }
            }
    
    
    }
    return 0;
}

