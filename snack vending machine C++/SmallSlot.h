#ifndef SMALLSLOT_H
#define SMALLSLOT_H

#include"motor.h"
#include<string>
#include"Slot.h"
using namespace std;

class SmallSlot : public Slot {
private:
    Motor* motor1;
public:
    SmallSlot( string productName, int id, int price);
    ~SmallSlot();
     void drop() ;
};

#endif // SMALLSLOT_H
