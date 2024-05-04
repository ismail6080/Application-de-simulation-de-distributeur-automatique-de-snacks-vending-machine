#ifndef WIDESLOT_H
#define WIDESLOT_H
#include<string>

#include"motor.h"
#include"Slot.h"

using namespace std;

class WideSlot : public Slot {
private:
    Motor* motor1;
    Motor* motor2;
public:
   WideSlot( string productName, int id, int price);
    ~WideSlot();
    void drop() ;

};
#endif // WIDESLOT_H
