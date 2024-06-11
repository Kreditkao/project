#include "Car.h"
#include "Sponsor.h"
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

    /*вход в аккаунт администратора салона. (Данные о нас загружаються в файл, данные о коллегах загружаются из файла Admins)*/
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


    /*Меню*/
    cout << "------------------------------------\n";
    cout << "               Menu\n";
    cout << "1 - show cars\n";
    cout << "2 - show clients\n";
    cout << "3 - serch sponsors\n";
    cout << "4 - exit           \n";
    cout << "------------------------------------\n";
    cin >> choise;

    /*Если выбор пользователя не 4, то*/
    while (choise != 4)
    {

    if (choise == 1)
    {
        /*Сортировка товара за ценой*/
        vector<Product> products = {
            {"Tesla", 12000},
            {"BMW", 17000},
            {"AUDI", 22000},
            {"Porshe", 14000},
            {"Mercedec", 8000},
            {"Wolwo", 9800}
        };  
        sort(products.begin(), products.end(), compareProducts);

        /*Выведенние списка*/
        for (const Product& product : products) {
            cout << product.name << ": " << product.price << endl;
        }
        /*Меню*/
        cout << "------------------------------------\n";
        cout << "               Menu\n";
        cout << "1 - show cars\n";
        cout << "2 - show clients\n";
        cout << "3 - serch sponsors\n";
        cout << "4 - exit           \n";
        cout << "------------------------------------\n";
        cin >> choise;
    }
    
    else if (choise == 2)
    {

        /*Динамический массив с клиентами*/
        int NClients = 0;
        Client* clients = nullptr;
    #if CREATE_ARRAY == 1 
        NClients = 6;
        clients = new Client[NClients] { 
            {"Marko Maenie", "Tesla", 2000},
            {"Okie Kokrei", "BMW", 0},
            {"Polop Ikaeo", "AUDI", 22000},
            {"Alisa Kororo", "Porshe", 2000},
            {"Malina Huero", " ", 0},
            {"Olivia Galenko", " ", 13000}

        };
    #elif CREATE_ARRAY == 2 //из файла

    #endif

            for (int i = 0; i < NClients; i++) { 
               cout << "\tClient #" << i + 1 << endl; 
               clients[i].showClient(); 
            }
            /*Меню*/
            cout << "------------------------------------\n";
            cout << "               Menu\n";
            cout << "1 - show cars\n";
            cout << "2 - show clients\n";
            cout << "3 - serch sponsors\n";
            cout << "4 - exit           \n";
            cout << "------------------------------------\n";
            cin >> choise;


    }

    else if (choise == 3) {

        /*Поиск компании по первой букве алфавита*/
        vector<string> sponsorLines = { "AliCompany", "BoroCompany", "CylinkCompany", "DiCompany", "EryCompany", "FurtunCompany" };

 
        // Получить имя спонсора от пользователя
        cout << "Input name sponsor (or 'break' for break): \n";
        string sponsorName;
        getline(cin, sponsorName);
        

        // Перебор строк со спонсорами
        for (const string& sponsorLine : sponsorLines) {
            if (containsSponsorName(sponsorName, sponsorLine)) {
                cout << "Sponsor: " << sponsorLine << endl;
            }
            else if (sponsorName == "break") {
                return 0;
            }
        }

        
    }


    else {
        /*Неправильная цифра*/
        cout << "Errror number \n";
    }
   
    }

    /*Выход из программы*/
    cout << "Have a nice day! Goodbay.\n";
    return 0;
}
