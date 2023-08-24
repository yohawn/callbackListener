#include "brand.h"
#include <iostream>
#include<QtDebug>
#include<iostream>
#include"CenterStation.h"
using namespace std;

brand::brand(const string& name, OILTYPE oilType1, OILTYPE oilType2)
{
    setName(name);
    setSupportOilType(oilType1);
    setSupportOilType(oilType2);
    connect(GasStation::getInst(), SIGNAL(changeOliPrice(int , int )), this, SLOT(Slot(int, int)),Qt::AutoConnection);
}

brand::~brand()
{
    disconnect(GasStation::getInst(), SIGNAL(changeOliPrice(int , int )), this, SLOT(Slot(int, int)));
}

void brand::setName(const string& name)
{
    Name = name;
}
void brand::setSupportOilType(OILTYPE eOil)
{
    mapSupportOilType[eOil] = true;
}

string brand::oilTypeToString(OILTYPE oilType)
{
    switch (oilType)
    {
    case OILTYPE::Gasoline:
        return "Gasoline";
    case OILTYPE::Diesel:
        return "Diesel";
    default:
        return "";
    }

}
void brand::displayStatus()
{
    cout << "Gas Station: " << Name << endl;
    cout << "Supported Oils: ";
    for (const auto& choice : mapSupportOilType)
    {
        if (choice.second)
        {
            cout << oilTypeToString(choice.first) << " ";
        }
    }
    cout << endl;

    if (mapSupportOilType[OILTYPE::Gasoline])
    {
        cout << "Gasoline Price: " << GasolinePrice << endl;
    }
    else
    {
        cout << "Don't sell gasoline" << endl;
    }

    if (mapSupportOilType[OILTYPE::Diesel])
    {
        cout << "Diesel Price: " << DieselPrice << endl;
    }
    else
    {
        cout << "Don't sell Diesel" << endl;
    }

  //  getoliPrice(int gasolineprice ,int dieselprice);//?
}

//void GasStation::getoliPrice(int gasolineprice, int dieselprice){

//}


brand* brand::getInst()
{
    static brand *inst = new brand();
    return inst;
}
void brand::Init(){

}

void brand::Slot(int a, int b)
{
    cout << "Gas Station: " << Name << endl;
    cout << "Supported Oils: ";
    for (const auto& choice : mapSupportOilType)
    {
        if (choice.second)
        {
            cout << oilTypeToString(choice.first) << " ";
        }
    }
    cout << endl;

    if (mapSupportOilType[OILTYPE::Gasoline])
    {
        cout << "Gasoline Price: " << a << endl;
    }
    else
    {
        cout << "Don't sell gasoline" << endl;
    }

    if (mapSupportOilType[OILTYPE::Diesel])
    {
        cout << "Diesel Price: " << b << endl;
    }
    else
    {
        cout << "Don't sell Diesel" << endl;
    }
}




