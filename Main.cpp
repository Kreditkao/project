#include "Car.h"
#include "Client.h"
#include "Admin.h"
#include <iostream>
#include <algorithm>
#include <vector>




#define CREATE_ARRAY 1
using namespace std;

int choise = 0;

int main()
{

    Admin a;
    Admin b{ "Roma Horuk", "Admin" };
    Admin c{ "Yulia Yula", "Half Admin" };
    Admin d{ "Pasha Demogen", "Admin" };

    a.fillAdmin();

    cout << "---------------------------------------\n\n";

    cout << "Your account\n\n";
    a.showAdmin();
    



    FILE* fileAdmins = nullptr;
    fopen_s(&fileAdmins, "Admins.txt", "w");
    if (fileAdmins != NULL)
    {

        a.saveToTextFile(fileAdmins);
        b.loadFromTextFile(fileAdmins);
        c.loadFromTextFile(fileAdmins);
        d.loadFromTextFile(fileAdmins);


        fclose(fileAdmins);
    }

    b.showAdmin();
    c.showAdmin();
    d.showAdmin();



    cout << "------------------------------------\n";
    cout << "               Menu\n";
    cout << "1 - show cars\n";
    cout << "2 - show clients\n";
    cout << "------------------------------------\n";
    cin >> choise;

    if (choise == 1)
    {
        vector<Product> products = {
            {"Tesla", 12000},
            {"BMW", 17000},
            {"AUDI", 22000},
            {"Porshe", 14000},
            {"Mercedec", 8000},
            {"Wolwo", 9800}
        };  
        sort(products.begin(), products.end(), compareProducts);

            // Виведення відсортованого списку продуктів
        for (const Product& product : products) {
            cout << product.name << ": " << product.price << endl;
        }
        cout << "------------------------------------\n";
        cout << "               Menu\n";
        cout << "1 - show cars\n";
        cout << "2 - show clients\n";
        cout << "------------------------------------\n";
        cin >> choise;
    }
    
    else if (choise == 2)
    {
        int NClients = 0;
        Client* clients = nullptr;
    #if CREATE_ARRAY == 1 
        NClients = 3;
        clients = new Client[NClients] { 
            {"Marko Maenie", "Tesla", 2000},
            {"Okie Kokrei", "BMW", 0},
            {"Polop Ikaeo", "AUDI", 22000},
            {"Alisa Kororo", "Porshe", 2000},
            {"Malina Huero", " ", 0},
            {"Olivia Galenko", " ", 13000}

        };
    #elif CREATE_ARRAY == 2 //із файлу

    #endif

            for (int i = 0; i < NClients; i++) { 
               cout << "\tClient #" << i + 1 << endl; 
               clients[i].showClient(); 
            }
    }


    

    return 0;
}

