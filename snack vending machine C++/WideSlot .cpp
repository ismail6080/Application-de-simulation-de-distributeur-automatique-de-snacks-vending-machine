#include <iostream>
#include <string>

using namespace std;

#include <iostream>
#include <string>
#include"WideSlot.h"

using namespace std;

    WideSlot::WideSlot( string productName, int id, int price) : Slot(productName, id, price,2), motor1(new Motor(id * 3 - 1)),motor2(new Motor(id * 2)) {}
    WideSlot::~WideSlot() {
        delete motor1;
        delete motor2; }

    void WideSlot::drop() {
        motor1->Trigger();
        motor2->Trigger();
        cout <<"\t\t"<< productName << "delivered from slot " << id << endl;
        numProducts--;
    }
