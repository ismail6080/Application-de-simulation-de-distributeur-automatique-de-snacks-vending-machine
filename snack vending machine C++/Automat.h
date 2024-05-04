#ifndef AUTOMAT_H
#define AUTOMAT_H


#include"Slot.h"
#include"Keypad.h"
#include"DropCheck.h"
#include"CoinSlot.h"


using namespace std;

class Automat {

private:
    Slot** slots;
    int numSlot;
    int cmp = 0;
    int numProductsPerSlot;
    Slot* cached;
public:
    CoinSlot coinSlot;
    Keypad keypad;
    DropCheck dropCheck;
public:
    Automat(int numSlots, int numProductsPerSlot) ;
    ~Automat() ;
    void addSlot(Slot* slot);
    void addSlot(string Name,int slotID ,int price,int motor1id , int motor2id=0 );
    void displayMenu(Automat& automat) ;
    void MainMenu();
    Slot* searchSlot(int slotID) ;
    void changeSlot(int slotID,string newName, int newPrice) ;
    int getPieces(int slotID);
    bool isAvailable(int slotID) ;
    int getPrice(int slotID);
     void dropSlot(int slotID);
    void fillAll() ;
    void fill(int slotID, int numProducts) ;
    void productfile();
    void readProductfile();

};

#endif // AUTOMAT_H
