#include <iostream>
#include <string>

#include"SmallSlot.h"
using namespace std;

    SmallSlot::SmallSlot( string productName, int id, int price) : Slot(productName, id, price,1), motor1(new Motor(id * 2)) {
}
    SmallSlot::~SmallSlot(){delete motor1;}
    void SmallSlot::drop() {
        motor1->Trigger();
        cout <<"\t\t"<< productName <<"delivered from slot " << id << endl;
        numProducts--;
    }

