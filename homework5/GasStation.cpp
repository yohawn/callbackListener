#include "GasStation.h"

GasStation::GasStation()
    :GasolinePrice(1500),DieselPrice(1400)  //기본요금
{
}

void GasStation::getoliPrice(int gasolineprice ,int dieselprice){
   GasolinePrice = gasolineprice;
    DieselPrice = dieselprice;
}

void GasStation::test(int gasolineprice,int dieselprice)//돈 바뀌는거 확인
{
        //sendoliPrice(a,b);
    //emit changeOliPrice(gasolineprice, dieselprice);
   GasStation::getInst()->sendoliPrice(gasolineprice,dieselprice);//왜 보내줘야하고 왜 static을 사용여부
}


GasStation* GasStation::getInst()
{
    static GasStation *inst = new GasStation();
    return inst;
}
void GasStation::sendoliPrice(int gasolinePrice1,int dieselPrice1 )
{
    emit changeOliPrice(gasolinePrice1, dieselPrice1);
}


