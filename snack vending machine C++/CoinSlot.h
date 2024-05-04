#ifndef COINSLOT_H
#define COINSLOT_H


class CoinSlot {

private:

    int coinAmount;
    int numCoinValues = 7;
    int coinValues[7] = {200, 100, 50, 20, 10, 5, 1};

public:
    CoinSlot();

int updateCoinAmount ();
    int getCoinAmount() ;
    void Clear();

 void returnCoins (int prix) ;

};
#endif // COINSLOT_H
