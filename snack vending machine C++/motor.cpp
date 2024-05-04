#include"motor.h"
#include <iostream>

using namespace std ;

Motor::Motor(int ID): id(ID){};
int Motor::getId()  { return id; }
void Motor::Trigger(){
cout<<"\t\tMoteur "<<id<<" est active"<<endl;
}


