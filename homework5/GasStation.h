#ifndef GASSTATION_H
#define GASSTATION_H
#include <QObject>
#include<iostream>
#include<QDebug>

class GasStation :public QObject
{
    Q_OBJECT
public:
    GasStation();
    int GasolinePrice;
    int DieselPrice;
    void getoliPrice(int gasolineprice ,int dieselprice);
    static void test(int gasolineprice,int dieselprice);//callback이걸 cpp,h분리하면 static 으로 지정
    static GasStation*getInst();//생성자
    void sendoliPrice(int gasolinePrice1, int dieselPrice1);
public:
    void displayStatus(){}

signals: //emit
    void changeOliPrice(int gasolinePrice1, int dieselPrice1);

};

#endif // GASSTATION_H


