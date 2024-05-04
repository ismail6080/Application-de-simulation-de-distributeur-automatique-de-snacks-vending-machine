#include <iostream>
#include <string>
#include"Automat.h"

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
    cout << "=== Product Menu ===" << endl;
    for (int i = 0; i < automat.cmp; ++i) {
        Slot* slot = automat.slots[i];
        cout << "Slot " << slot->getId() << ": " << slot->getProductName() << " - Price: " << slot->getPrice() / 100.0 << "  Euro " << " - Nombre de piece "<<slot->getNumProducts() << endl;
    }
    cout << "===================" << endl;
}
    Slot* Automat::searchSlot(int slotID) {
        int n=0;
        if (cached && cached->getId() == slotID) {
            return cached;
        }
        for (int i = 0; i <cmp; ++i) {
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
   void Automat::changeSlot(int slotID, string newName, int newPrice) {
        Slot* slot = searchSlot(slotID);
        if (slot) {
            slot->setProductName(newName);
            slot->setPrice(newPrice);
        }
    }
    int Automat::getPieces(int slotID) {
        Slot* slot = searchSlot(slotID);
        return slot ? slot->getNumProducts() : 0;
    }
    bool Automat::isAvailable(int slotID) {
        Slot* slot = searchSlot(slotID);
        int numm=slot->getNumProducts();
        string nom=slot->getProductName();
        cout<<"nombre de piece de "<< nom <<"est:  "<<numm<<endl;
        return slot && slot->getNumProducts() > 0;
    }
    int Automat::getPrice(int slotID) {
        Slot* slot = searchSlot(slotID);
        return slot ? slot->getPrice() : 0;
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
            slot->setNumProducts(numProducts);
        }
    }
