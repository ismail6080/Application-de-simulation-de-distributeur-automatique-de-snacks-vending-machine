#include "Automat.h"
#include"WideSlot.h"
#include"SmallSlot.h"
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;


int main() {

    Automat automat(20, 5);



   automat.readProductfile();


    char state = 'I';
    char st='I';
    int selection=0;
    int n=0;
    int coin=0;
    Slot *slot;

    while (selection != -1 ) {


        switch (state) {
        case 'I': {
            system("cls");
            cout<<"\t\tIDLE"<<endl;
            automat.displayMenu(automat);
            selection = automat.keypad.getSelection();
            if(selection==-1){break;}
            if(selection==0){state ='M'; break;}
            slot = automat.searchSlot(selection);
            if (slot && automat.isAvailable(selection)) {
                cout << "\t\tPrice: " << automat.getPrice(selection) / 100.0 << " Euro" << endl;
                state ='C';
            } else {
                cout << "\t\tselection est invalide ou le produit n'est pas disponible." << endl;
                state = 'I';
                system("pause");
            }
            break;
        }
        case 'C': {
             system("cls");
            cout<<"\t\t\t=== COLLECT_MONEY: ==="<<endl;
            coin=0;

            while(n<=0 || n>slot->getNumProducts()){
            cout<<"\t\tLe nombre de produits que vous pouvez acheter ( "<<slot->getNumProducts()<<" ) :"<<endl;
            cout<<"\t\t"; cin>>n;
            if(n<=0 || n>slot->getNumProducts()){
            system("cls");
            cout<<"\t\tnombre est invalide"<<endl;

            }
}

           while((automat.coinSlot.getCoinAmount()<(automat.getPrice(selection)*n)) && coin != -1){
            coin = automat.coinSlot.updateCoinAmount();


           }
           if (coin == -1) {
                automat.coinSlot.Clear();
                state = 'I';
                }
           else{state = 'D';}

            break;
        }
        case 'D': {
            system("cls");
            cout<<"\t\t\t=== DROP: ==="<<endl;

            for(int i=0;i<n;i++){
             automat.dropSlot(selection);
             system("pause");
            if (automat.dropCheck.productReleased()) {
                state = 'E';
            }
            }
            break;
        }
        case 'E': {
             system("cls");
             cout<<"\t\t\t=== RETURN_MONEY: ==="<<endl;
             int change=automat.coinSlot.getCoinAmount()-automat.getPrice(selection)*n;
             cout<<"\t\tle prix totale de produis est :"<<automat.getPrice(selection)*n<<endl;
             cout<<"\t\t le montant est "<<automat.coinSlot.getCoinAmount()<<endl;
             cout<<"\t\tchange est :"<<change<<"  ||  ";
            automat.coinSlot.returnCoins(change);
            automat.coinSlot.Clear();
            system("pause");
            automat.productfile();
            automat.displayMenu(automat);
            state = 'I';

            break;
        }
        case 'M' :  {
        //l'authentification :
        bool auth=automat.keypad.getpassword();
        while(!auth){
          auth=automat.keypad.getpassword();
        }
        int n=0;
        while(state!='I'){
        automat.MainMenu();
        selection=automat.keypad.getSelection();

        switch(selection){
        case 1 : {
        string nom;
        int prix=0,id,type,n=0;
        while(n!=1){
         cout << "\t\t\t=== 1. Ajouter un nouvel emplacement (slot) : ==="<<endl;
         cout<<"\t\tSaisir le nom du produit"<<endl;
         cout<<"\t\t"; cin>>nom;
         cout<<"\t\tSaisir le id du produit"<<endl;
         cout<<"\t\t" ;cin>>id;
         cout<<"\t\tSaisir le prix du produit en cents (par exemple, 150 pour 1,50 Euro) :"<<endl;
         cout<<"\t\t"; cin>>prix;
         cout<<"\t\t1.SmallSlot  2.WideSlot :"<<endl;
         cout<<"\t\t"; cin>>type;
         cout<<"\t\tConfirmer l'ajout de l'emplacement par 1 "<<endl;
         cout<<"\t\t"; cin>>n;
        }
        if(prix!=0){
            if(type==1){automat.addSlot(new SmallSlot(nom,id,prix));}
            if(type==2){automat.addSlot(new WideSlot(nom,id,prix));}
            automat.productfile();
        }

            break;}


        case 2 : {
         int id, nprix = 0, n = 0;
string nom;
automat.displayMenu(automat);

while (n != 1) {
    cout << "\t\t\t=== 2. Modifier le nom et le prix d'un emplacement existant: ===" << endl;
    cout << "\t\tVeuillez saisir l'ID du produit que vous souhaitez modifier : ";
    cin >> id;

    if (automat.searchSlot(id)) {
        cout << "\t\tNouveau nom du produit : ";
        cin >> nom;
        cout << "\t\tNouveau prix du produit : ";
        cin >> nprix;
        cout << "\t\tConfirmer les modifications par 1 : ";
        cin >> n;
    } else {
        cout << "\t\tLe produit n'existe pas!" << endl;
    }

    if (nprix != 0) {
        automat.changeSlot(id, nom, nprix);
        automat.productfile();
    }
}


            break;}

        case 3 :{
        int id,nbr;
        cout << "\t\t\t=== 3. remplir un produit spécifique : ==="<<endl;
        cout<<"\t\t saisir id du produit que vous souhaitez remplir :"<<endl;
        cout<<"\t\t"; cin>>id;
        cout<<"\t\t saisir la quantite à ajouter pour le produit  :"<<endl;
        cout<<"\t\t"; cin>>nbr;
        if(automat.isAvailable(id)){
         automat.fill(id,nbr);
         automat.productfile();
        }
        else {cout << "\t\tProduit non trouvé" << endl;}
        break;
        }

        case 4 : {
         system("cls");
         cout << "\t\t\t=== 3. remplir un produit spécifique : ==="<<endl;
         automat.fillAll();
         cout<<"Tous les produits sont remplis "<<endl;
         system("pause");
        break;
        }

        case 5 : {
         automat.productfile();
         state='I';

         break;}

        }
        }
       break;

}
     }
    }

    return 0;
}














