#include <iostream>
#include <string>
#include"Slot.h"
using namespace std;


    Slot::Slot(string productName, int id, int price,int t) :
          productName(productName), id(id), numProducts(0), price(price) ,type(t) {}
    Slot::~Slot() {}
 void Slot::drop(){};
    string Slot::getProductName()
    {
        return productName; }

    void Slot::setProductName(const string& newName) {
        productName = newName;
        }

    int Slot::getNumProducts() {
        return numProducts; }

    void Slot::setNumProducts(int newNum) {
        numProducts = newNum; }

    int Slot::getPrice()  {
        return price ; }

    void Slot::setPrice(int newPrice) {
        price = newPrice; }

    int Slot::getId()  {
        return id; }
    int Slot::typeslot(){
    return this->type;
    }

