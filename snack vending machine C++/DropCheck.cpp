#include "DropCheck.h"
#include <random>

bool DropCheck::productReleased(){
 int aleatoire = rand()%10;

    if (aleatoire < 9) {
        return true;
    } else {
        return false;
    }

}
