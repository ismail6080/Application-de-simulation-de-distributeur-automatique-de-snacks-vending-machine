#include <iostream>
#include <string>
#include"CoinSlot.h"
using namespace std;

    CoinSlot::CoinSlot() : coinAmount(0) {}

    int CoinSlot::updateCoinAmount (){
        int nbr;
        system("cls");
        cout<<"\t\t\t=== COLLECT_MONEY: ==="<<endl;
        cout<<"\t\t"; cout<<"inserer une piece ou a entrer -1 pour annuler le processus d'achat"<<endl;
        cout<<"\t\t"; cin>>nbr;
        if(nbr==-1){
        Clear();
        return -1;   }
        else{
            coinAmount=coinAmount+nbr;
            return nbr;}}
    int CoinSlot::getCoinAmount() { return coinAmount; }
    void CoinSlot::Clear() { coinAmount = 0; }

    void CoinSlot::returnCoins (int prix) {
        int n=prix;
        int tab[7];
        for(int i=0;i<7;i++){
            tab[i]=n/coinValues[i];
            n=n%coinValues[i];}

        for(int i=0;i<7;i++){
            if(tab[i]!=0){
             cout<<tab[i]<<"  x  "<<coinValues[i]/100.0<<" euro ,";
              }
        }
        cout<<endl;
}
