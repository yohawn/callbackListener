#include "CenterStation.h"
#include <iostream>

CenterStation::CenterStation() {

}
//함수 등록
void CenterStation::setCallbackFunc(void (*Func)(int gasolineprice, int dieselprice))
{
    callbackFunc = Func;
}

void CenterStation::updateOilPrice(int newGasolinePrice, int newDieselPrice) {
    callbackFunc(newGasolinePrice, newDieselPrice);  //순서의 따라 초기값이 나오고 안나옴
}

CenterStation* CenterStation::getInst()
{
    static CenterStation *inst = new CenterStation();
    return inst;
}


//void GasStation::getoliPrice(int gasolineprice, int dieselprice){}
