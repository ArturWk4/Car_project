#ifndef GARAGE_H_INCLUDED
#define GARAGE_H_INCLUDED
#include <vector>
#include "car.h"
class Garage
{
private:
    int m_garageNumber;
    double m_coast;
    std::vector<Car*> m_cars;
public:
    explicit Garage(): m_garageNumber(0),m_coast(0) {};
    explicit Garage(int number,double coast)
    {
        m_garageNumber = number;
        m_coast = coast;
    }
    int getGarageNumber() const;
    double getCoast();

    void setGarageNumber(int number);

    void showCars()
    {
        std::vector<Car*>::iterator i = m_cars.begin();
        int j = 0;
        for(i,j; i<m_cars.end(); ++i,++j)
        {
            std::cout<<"At "<<j+1<<" place stay "<<(*i)<<std::endl;
        }
    }
};



double Garage::getCoast()
{
    return m_coast;
}


void Garage::setGarageNumber(int number)
{
    m_garageNumber = number;
}
#endif // GARAGE_H_INCLUDED
