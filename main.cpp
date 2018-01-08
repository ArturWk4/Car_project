#include <iostream>
#include <string>
#include "driver.h"
#include "car.h"
#include "bmw.h"
#include <conio.h>
using namespace std;

int main()
{
    //Car* car = new Bmw("M3 E30",1987,5);
    Car* silvia = new Car("Nissan","silvia",2002,10,5);
    Driver* driver = new Driver("Artur",16);

    std::cout<< *silvia<<std::endl;;
    cout<< driver->getMoney() <<endl;
    driver->earnMoney();
    cout<< driver->getMoney() <<endl;

    driver->buyCar(silvia);
    cout<< *driver<<std::endl;
    cout<<endl;
    driver->addFuel(2);
    cout<<"fuel = "<<silvia->getFuel()<<endl;

    driver->startEngine();
    driver->drive();
    cout<<endl;
    cout<<endl;
    cout<<"finish!"<<endl<<endl;
    silvia->showInfo();

    return 0;
}
