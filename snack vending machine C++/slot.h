#ifndef SLOT_H
#define SLOT_H


#include <iostream>
#include <string>
#include"Motor.h"

using namespace std;

class Slot {
 protected:
    string productName;
    int id;
    int numProducts;
    int price;
    int type ;
 public:
     Slot(string productName, int id, int price,int t );
     ~Slot();
   virtual void drop()=0;
    string getProductName();
    void setProductName(const string& newName);
    int getNumProducts();
    void setNumProducts(int newNum) ;
    int getPrice();
    void setPrice(int newPrice) ;
    int getId() ;
    int typeslot ();
};
#endif // SLOT_H
