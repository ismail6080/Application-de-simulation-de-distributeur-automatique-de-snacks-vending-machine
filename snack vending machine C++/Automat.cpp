#include <iostream>
#include <string>
#include"Automat.h"
#include<fstream>
#include"SmallSlot.h"
#include"WideSlot.h"
#include"slot.h"

using namespace std;

    Automat::Automat(int numSlots, int numProductsPerSlot) : numSlot(numSlots), numProductsPerSlot(numProductsPerSlot),
                                                     slots(new Slot*[numSlots]), cached(nullptr) {}
    Automat::~Automat() {
        for (int i = 0; i < numSlot; ++i) {
            delete slots[i];
        }
        delete[] slots;
    }
    void Automat::addSlot(Slot* slot) {
        if (cmp < numSlot) {
            slots[cmp++] = slot;
        }
    }
    void Automat::displayMenu(Automat& automat) {
        system("cls");

        cout << "\t\t\t=== Menu des produits ===" << endl;
        for (int i = 0; i < cmp; i++) {
            Slot* slot = automat.slots[i];
            cout << "\t\tSlot " << slot->getId() << ": " << slot->getProductName() << " - Prix : " << slot->getPrice() / 100.0 << " Euro " << " - Nombre de pieces : " << slot->getNumProducts()<<endl;
        }
        cout<<"\t\t0 --> Menu Principal:"<<endl;
        cout << "\t\t\t===================" << endl;
        }

    void Automat::MainMenu(){
    system("cls");
    cout << "\t\t\t=== Menu Principal : ===" << endl;
    cout << "\t\t1. Ajouter un nouvel emplacement (slot)" << endl;
    cout << "\t\t2. Modifier le nom et le prix un emplacement existant" << endl;
    cout << "\t\t3. remplir un produit spécifique " << endl;
    cout << "\t\t4. remplir tout les produits " << endl;
    cout << "\t\t5. Afficher le menu des produits " << endl;
    cout << "\t\t\t===================" << endl;
    }
    Slot* Automat::searchSlot(int slotID) {
        int n=0;
        if (cached && cached->getId() == slotID) {
            return cached;
        }
        for (int i = 0; i <cmp; i++) {
          Slot* slot =slots[i];
          if(slot->getId() == slotID){
                cached =slots[i];
                return cached;
        }
        else{
            n++;
        }
        }
        if(n==0){
                return nullptr;
        }

    }
    void Automat::changeSlot(int slotID,string newName, int newPrice) {
        Slot* slot = searchSlot(slotID);
        if (slot) {
            slot->setProductName(newName);
            slot->setPrice(newPrice);
        }
    }

    int Automat::getPieces(int slotID) {
        Slot* slot = searchSlot(slotID);
        return slot->getNumProducts();
    }
    bool Automat::isAvailable(int slotID) {
        Slot* slot = searchSlot(slotID);
        int numm=slot->getNumProducts();
        string nom=slot->getProductName();
        cout<<"\t\tnombre de piece de "<< nom <<" est:  "<<numm<<endl;
        if(slot->getNumProducts() > 0){
           return true;
        }
        else {
            return false;
        }
    }
    int Automat::getPrice(int slotID) {
        Slot* slot = searchSlot(slotID);
        return slot->getPrice();
    }
    void Automat::dropSlot(int slotID) {
        Slot* slot = searchSlot(slotID);
        if (slot && slot->getNumProducts() > 0) {
            slot->drop();
        }
    }
    void Automat::fillAll() {
        for (int i = 0; i < cmp; i++) {
            slots[i]->setNumProducts(numProductsPerSlot);
        }
    }
    void Automat::fill(int slotID, int numProducts) {
        Slot* slot = searchSlot(slotID);
        if (slot) {
            if(numProducts>=0 && numProducts<=numProductsPerSlot)
            slot->setNumProducts(numProducts);
            else {
             cout<<"\t\tle nombre maximal de piece est :"<<numProductsPerSlot<<endl;
            }
        }
    }
    void Automat::productfile(){
    ofstream F ("products.txt");
    if(!F.is_open())
     cout << "Impossible d'ouvrir le fichier en écriture !" << endl;
    else{
    for (int i = 0; i <cmp; ++i) {
         Slot* slot =slots[i];
         if (slot)
         F <<  slot->getId()<< "," << slot->getProductName() << "," << slot->getPrice() <<","<<slot->getNumProducts()<<","<<  slot->typeslot() << endl;
}}
F.close();
}
    void Automat::readProductfile(){
    ifstream F ("products.txt");
     if (!F.is_open()) {
        cout<< "Erreur : Impossible d'ouvrir le fichier "<< endl;
    }
    else  {
        Slot* slot;
        string nom; int id , prix , nbr ,type;
        while (F >> id) {
            F.ignore(); // Ignorer la virgule
            getline(F, nom, ',');
            F >> prix;
            F.ignore();
            F >> nbr;
            F.ignore();
            F >> type;
            if (type == 1){addSlot(new SmallSlot(nom, id, prix));}
            if (type == 2){addSlot(new WideSlot(nom, id, prix));}
            Slot* slot = slots[cmp - 1];
            slot->setNumProducts(nbr);

        }


    }
    F.close();
    }


