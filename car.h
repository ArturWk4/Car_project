#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include <stdexcept>
#include "driver.h"
class Car
{
    friend std::ostream& operator<<(std::ostream& stream, Car car);
private:
    std::string m_brand;
    std::string m_model;
    int m_year;
    double m_fuel;
    int m_cost;
    int m_mileage;
    double m_fuelConsumption;
    int m_condition;
    bool m_engineSwitch;
public:

    explicit Car():m_brand("No name brand"),m_model("No name car"),
        m_year(0),m_cost(0),m_fuel(0),m_mileage(0),m_engineSwitch(false),
        m_fuelConsumption(0),m_condition(0) {}

    explicit Car(std::string brand, std::string model, int year, double fuelConsumption, int cost)
    {
        m_brand = brand;
        m_model = model;
        m_year = year;
        m_fuelConsumption = fuelConsumption/100;
        m_cost = cost;
        m_fuel = 0;
        m_mileage = 0;
        m_condition = 100;
        m_engineSwitch = false;
    }

    std::string getBrand() const noexcept;
    std::string getModel() const noexcept;
    int getYear() const noexcept;
    double getFuel() noexcept;
    int getCost() noexcept;
    int getMileage() noexcept;
    double getFuelConsumption() noexcept;
    int getCondition() noexcept;
    bool getEngineSwitch() noexcept;

    void setBrand(std::string brand);
    void setModel(std::string model);
    void setFuel(double fuel);
    void setYear(int year);
    void setCost(int cost);
    void setMileage(int mileage);
    void setFuelConsumption(double fuelConsumption);
    void setCondition(double condition);
    void setEngineSwitch(bool engineSwitch);

    void startEngine();
    void switchOfEngine();
    void motion(int steps);
    void upCondition();
    void showInfo();
};
//*****************************************************
double Car::getFuel() noexcept
{
    return m_fuel;
}
std::string Car::getBrand() const noexcept
{
    return m_brand;
}
std::string Car::getModel() const noexcept
{
    return m_model;
}
int Car::getCost() noexcept
{
    return m_cost;
}
int Car::getYear() const noexcept
{
    return m_year;
}
int Car::getMileage()noexcept
{
    return m_mileage;
}
bool Car::getEngineSwitch() noexcept
{
    return m_engineSwitch;
}
int Car::getCondition() noexcept
{
    return m_condition;
}
double Car::getFuelConsumption() noexcept
{
    return m_fuelConsumption;
}


//******************************************
void Car::setFuel(double liters)
{
    if(liters < 0)
        throw std::invalid_argument("Fuel can't be negative!");
    m_fuel = liters;
}

void Car::setCost(int cost)
{
    if(cost < 0)
        throw std::invalid_argument("Coast can't be negative!");
    m_cost = cost;
}

void Car::setBrand(std::string brand)
{
    m_brand = brand;
}

void Car::setModel(std::string model)
{
    m_model = model;
}
void Car::setYear(int year)
{
    m_year = year;
}
void Car::setMileage(int mileage)
{
    m_mileage = mileage;
}
void Car::setEngineSwitch(bool engineSwitch)
{
    m_engineSwitch = engineSwitch;
}
void Car::setCondition(double condition)
{
    m_condition = condition;
}
void Car::setFuelConsumption(double fuelConsumption)
{
    m_fuelConsumption = fuelConsumption;
}



//*********************************************
void Car::startEngine()
{
    if(m_fuel == 0)
        std::cout<<"You can't start engine, because your car don't have fuel!"<<std::endl;
    else setEngineSwitch(true);
}
void Car::switchOfEngine()
{
    setEngineSwitch(false);
}
void Car::motion(int steps)
{
   // for(int i=0; i < steps;++i)
    m_fuel -= (steps * m_fuelConsumption) / 100;
    m_mileage += steps * 100;
    --m_condition;
}

void Car::upCondition()
{
    if(m_condition != 100)
        ++m_condition;
    else std::cout<<"Your car in perfect condition!";
}

void Car::showInfo()
{
    std::cout <<"Brand: "<<getBrand()<<std::endl;
    std::cout <<"Model: "<<getModel()<<std::endl;
    std::cout <<"Year of create: "<<getYear()<<std::endl;
    std::cout <<"Mileage: "<<getMileage()<<std::endl;
    std::cout <<"Condition:" <<getCondition()<<std::endl;
    std::cout <<"Fuel consumption: "<<getFuel()<<std::endl;
              std::cout <<"Coast: "<<getCost()<<std::endl;
    std::cout <<"Gas tank fill on "<<getFuel()<<" liters"<<std::endl;
}



//***********************************************
std::ostream& operator<<(std::ostream& stream, Car car)
{
    stream <<car.getBrand()<<" "<<car.getModel()<<" "<<car.getYear()<<" year";
    return stream;
}



// fuel consumption



#endif // CAR_H_INCLUDED
