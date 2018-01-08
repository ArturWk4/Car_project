#ifndef BMW_H_INCLUDED
#define BMW_H_INCLUDED
#include "car.h"
#include "driver.h"
class Bmw : public Car
{
    friend std::ostream& operator<<(std::ostream& stream, Bmw bmw);
private:
    std::string m_country;
public:
    explicit Bmw()
    {
        setBrand("BMW");
        setCountry("German");
    }
    explicit Bmw(std::string model,int year,int cost)
    {
        setBrand("BMW");
        setModel(model);
        setYear(year);
        setCost(cost);
    }
    std::string getCountry() const noexcept;

    void setCountry(std::string country);
};

std::string Bmw::getCountry() const noexcept
{
    return m_country;
}

void Bmw::setCountry(std::string country)
{
    m_country = country;
}


#endif // BMW_H_INCLUDED
