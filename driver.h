#ifndef DRIVER_H_INCLUDED
#define DRIVER_H_INCLUDED
#include <windows.h>
#include <conio.h>
#include <stdexcept>
#include "car.h"
#include "garage.h"
class Driver
{
    friend std::ostream& operator<<(std::ostream& stream, Driver driver);

private:
    std::string m_name;
    int m_age;
    double m_money;
    Car* m_car = new Car;
    Garage* m_garage = new Garage;
    bool m_carExistence;
    bool m_garageExistence;

    void setCar(Car* car);
    void setGarage(Garage* garage);

public:
    explicit Driver():m_name("Name"),m_age(0),m_money(0),m_carExistence(false),m_garageExistence(false) {};
    explicit Driver(std::string name,int age)
    {
        m_name = name;
        m_age = age;
        m_money = 0;
        m_carExistence = false;
        m_garageExistence = false;
    }

    std::string getName() const noexcept;
    int         getAge() const noexcept;
    double      getMoney() const noexcept;
    Car         getCar();
    Garage      getGarage() const;
    bool        getCarExistence() noexcept;
    bool        getGarageExistence() noexcept;

    void setName(std::string name);
    void setAge(int age);
    void setMoney(double money);
    void setCarExistence(bool change);
    void setGarageExistence(bool change);

    void startEngine();
    void addFuel(double fuel);
    void earnMoney();
    void buyCar(Car* car);
    void buyGarage(Garage* garage);
    void sellCar();
    void drive();
    void repairCar();
};


std::string Driver::getName() const noexcept
{
    return m_name;
}

int Driver::getAge() const noexcept
{
    return m_age;
}

double Driver::getMoney() const noexcept
{
    return m_money;
}

Car Driver::getCar()
{
    if(m_carExistence != true)
        throw std::invalid_argument("You don't have a car!");
    return *m_car;
}
bool Driver::getCarExistence() noexcept
{
    return m_carExistence;
}
Garage Driver::getGarage() const
{
    return *m_garage;
}
bool Driver::getGarageExistence() noexcept
{
    return m_garageExistence;
}

//------------------------------------
void Driver::setName(std::string name)
{
    m_name = name;
}

void Driver::setAge(int age)
{
    m_age = age;
}

void Driver::setMoney(double money)
{
    m_money = money;
}

void Driver::setCar(Car* car)
{
    m_car = car;
}
void Driver::setCarExistence(bool change)
{
    m_carExistence = change;
}

void Driver::setGarage(Garage* garage)
{
    m_garage = garage;
}

void Driver::setGarageExistence(bool change)
{
    m_garageExistence = change;
}


//---------------------------------------------

void Driver::addFuel(double fuel)
{
    if(m_carExistence == true)
    {
        m_car->setFuel(m_car->getFuel()+ fuel);
        m_money -= fuel/10;
    }
    else
    {
        std::cout<<"You can't add fuel, because you don't have a car!"<<std::endl;
    }
}

void Driver::buyCar(Car* car)
{
    if(m_money >= car->getCost())
    {
        setCar(car);
        m_carExistence = true;
        std::cout<<"My celebration, "<<m_name<<"! You bought "<<car->getBrand()<<" "<<car->getModel()<<" !!!"<<std::endl;
    }
    else std::cout<<"Not enough money to buy this car! Earn and try again! "<<std::endl;
}

void Driver::buyGarage(Garage* garage)
{
    if(m_money >= garage->getCoast())
    {
        setGarage(garage);
        m_garageExistence = true;
        std::cout<<"My celebration, "<<m_name<<"! You bought a garage!"<<std::endl;
    }
    else std::cout<<"Not enough money to buy this car! Earn and try again! "<<std::endl;
}

void Driver::earnMoney()
{
    m_money += 10;
}


void Driver::sellCar()
{
    if(m_carExistence == true)
    {
        setMoney(m_money + m_car->getCost());
        m_carExistence = false;
        std::cout<<"You sell your car."<<std::endl;
        delete m_car;
    }
}

void Driver::drive()
{
    char key = 0;
    int counter = 0;
    double fuel = m_car->getFuel();
    double consumption = m_car->getFuelConsumption() / 100;

    if(m_car->getEngineSwitch()== false)
        throw std::invalid_argument("You was not start engine!");

    while(key !='z' )
    {
        Sleep(340);
        system("cls");
        if (_kbhit())
        {
            key = _getch();

            switch(key)
            {
            case 'w':
            {
                ++counter;
                fuel -= consumption / 100;
                std::cout<<"/\\"<<std::endl;
                std::cout<<"||"<<std::endl<<std::endl;
            }
            break;
            case 's':
            {
                ++counter;
                fuel -= consumption / 100;
                std::cout<<"||"<<std::endl;
                std::cout<<"\\/"<<std::endl<<std::endl;
            }
            break;
            case 'a':
            {
                std::cout<<"<-"<<std::endl<<std::endl;
            }
            break;
            case 'd':
            {
                std::cout<<"->"<<std::endl<<std::endl;
            }
            break;
            case 'z':
            {
                m_car->motion(counter);
                m_car->switchOfEngine();
            }
            break;
            }
            if(fuel == 0.0)
                break;

        }//доработать случай если кончился безнин в процессе езды
    }
}

void Driver::repairCar()
{
    if(m_carExistence == true && m_money!=0)
    {
        m_car->upCondition();
        --m_money;
    }
}

void Driver::startEngine()
{
    m_car->startEngine();
}

//******************************************************

std::ostream& operator<<(std::ostream& stream, Driver driver)
{
    stream << "Name: "<<driver.getName() <<std::endl;
    stream << "Age: "<<driver.getAge() <<std::endl;
    stream << "Amount of money: " <<driver.getMoney() <<std::endl;
    if(driver.m_carExistence == true)
        stream << "Car: " <<std::endl <<driver.getCar() <<std::endl;
    else
        stream << driver.getName() << " don't have a car" <<std::endl;

    return stream;
}

#endif // DRIVER_H_INCLUDED
