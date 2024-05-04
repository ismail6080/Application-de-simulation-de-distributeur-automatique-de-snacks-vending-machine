#include <iostream>
#include <string>
#include"Keypad.h"
using namespace std;


    int Keypad::getSelection() {
        int selection;
        do {
            cout << "\t\tEnter slot number (or -1 to exit): ";
            cin >> selection;
        } while (selection < -1);
        return selection;
    }
    bool Keypad::getpassword(){
        string username;
        string password;
        system("cls");
         cout << "\t\t\t=== Authentification : ==="<< endl;
        cout << "\t\tEntrez votre nom d'utilisateur :(user)  ";
        cin >> username;
        cout << "\t\tEntrez votre mot de passe :(12345) ";
        cin >> password;
       // Vérifier l'authentification
       if (username=="user"&&password == "12345") {
       return true;

       } else {
        system("cls");
        cout << "Echec de l'authentification. Veuillez reessayer" << endl;
        system("pause");
        return false;
       }


    }
