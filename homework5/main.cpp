#include "CenterStation.h"
#include "GasStation.h"
#include "brand.h"
#include <functional> //event.setCallbackFunc(work.test); 이게 포인터를 사용하라해서
//functional로 지정

int main()
{
    CenterStation event;
    GasStation work;
    event.setCallbackFunc(work.test); //Callback을 받을 함수 등록

    brand soli("Soli Gas Station", OILTYPE::Gasoline,OILTYPE::Diesel);
    brand sk("SK Gas Station", OILTYPE::Gasoline);
    brand gs("GS Gas Station", OILTYPE::Diesel);

    soli.displayStatus();
    sk.displayStatus();
    gs.displayStatus();

    event.updateOilPrice(1500, 1420);
    event.updateOilPrice(1580, 1450);
    event.updateOilPrice(1540, 1450);


    return 0;
}



