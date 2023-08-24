#ifndef BRAND_H  //전처리
#define BRAND_H
#include <QObject>
#include <QDebug>
#include <iostream>
#include <map>
#include <string>
#include "GasStation.h"

using namespace  std;
//라인 이유 (사용이유)
enum class OILTYPE
{
    Gasoline,
    Diesel,
    End
};


class brand : public GasStation
{
    Q_OBJECT
public:
    brand() {}
    brand(const string& name, OILTYPE oilType1,  OILTYPE oilType2 = OILTYPE::End); //end의미
    ~brand();
    string Name;
    map<OILTYPE,bool> mapSupportOilType;//map함수의미,그림 ,,표준stl 단어공부 (용어)
    void setName(const string& name);  //브랜드
    void setSupportOilType(OILTYPE eOil);  //브랜드
    string oilTypeToString(OILTYPE oilType);
    void startsolt();
    static brand* getInst();// 정적 변수
    void Init();

public:
    void displayStatus();

public slots:
    void Slot(int a, int b);
};

#endif // BRAND_H

