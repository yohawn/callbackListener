#ifndef CENTERSTATION_H
#define CENTERSTATION_H
#include"GasStation.h"
#include<functional>
 //void setCallbackFunc(void (*Func)(int gasolineprice, int dieselprice)); //

class CenterStation {
public:

    CenterStation();

    void setCallbackFunc(void (*Func)(int gasolineprice, int dieselprice));
    void updateOilPrice(int gasoline, int diesel);
    static CenterStation* getInst();

private:
    void (*callbackFunc)(int gasolineprice, int dieselprice); //callback사용을위한 선언
    int centergasolineprice;
    int centerdieselprice;
};

#endif // CENTER_H
