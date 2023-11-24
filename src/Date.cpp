#include "../include/Date.h"
#include <iostream>
#include <stdexcept>

Date::Date()
{
  y_=1709;
  m_=Month::jan;
  d_=1;
}

Date::Date (int y, Month m, int d)
    {
        if(!isValid(y, m, d))
            throw std::invalid_argument("Data non valida");
        y_= {y}; 
        m_= {m}; 
        d_= {d};
    }

//Non so se sia corretto passarlo come reference const

Date& Date::operator=(const Date& a){
   if(*this==a)
     return *this;
   y_=a.year();
   m_=a.month();
   d_=a.day();
   return *this;
}

Date& Date::operator=(Date&& a)
{
if(*this==a)
return *this;
   y_=a.year();
   m_=a.month();
   d_=a.day();
   a.setDate(1709,Month::jan,1);
   return *this;
 }

void Date::setDate(int y, Month m, int d)
{
    if(!isValid(y, m, d))
        throw std::invalid_argument("Data non valida");
    y_= {y}; 
    m_= {m}; 
    d_= {d};
    
}

//Move constructor
Date::Date(Date&& old)
    : y_{old.year()}, m_{old.month()}, d_{old.day()}
{
  old.setDate(1709,Month::jan,1);
}
//Copy Constructor
Date::Date(const Date& old)
    : y_{old.year()}, m_{old.month()}, d_{old.day()}
{
}

// int Date::day() const{return d_;}
// Date::month() {return m_;}
// int Date::year() const{return y_;}

bool Date::isValid(int y, Month m, int d){     // con parametri
    if(y<1582)
        return false; //Controllo se fa parte del calendario gregoriano
    switch(m){
        case(4):
        case(6):
        case(9):
        case(11):
            if(d<1 || d>30) return false; break;
        case(2):
            if(isLeap()){
                if(d<1 || d>29)
                {
                    return false;
                }
            }
            else{
                if(d<1 || d>28){
                    return false;
                }
            }
            break;
        default:if(d<1 || d>31) return false;
    }
    return true;
}

bool Date::isLeap(){
    if(y_%400==0)
        return true;
    else if(y_%100==0)
        return false;
    else if(y_%4==0)
        return true;
    return false;
}

bool operator==(const Date& a, const Date& b){
    return a.year()==b.year() && a.month()==b.month() && a.day()==b.day();
}
bool operator!=(const Date& a, const Date& b){
    return a.year()!=b.year() || a.month()!=b.month() || a.day()!=b.day();
}
bool operator>(const Date& a, const Date& b){
    if(a.year()>b.year())
        return true;
    if(a.year()==b.year() && a.month()>b.month())
        return true;
    if(a.year()==b.year() && a.month()==b.month() && a.day()>b.day())
        return true;
    return false;
}
bool operator<(const Date& a, const Date& b){
    if(a.year()<b.year())
        return true;
    if(a.year()==b.year() && a.month()<b.month())
        return true;
    if(a.year()==b.year() && a.month()==b.month() && a.day()<b.day())
        return true;
    return false;
}
bool operator>=(const Date& a, const Date& b){
    if(a.year()>=b.year())
        return true;
    if(a.year()==b.year() && a.month()>=b.month())
        return true;
    if(a.year()==b.year() && a.month()==b.month() && a.day()>=b.day())
        return true;
    return false;
}
bool operator<=(const Date& a, const Date& b){
    if(a.year()<=b.year())
        return true;
    if(a.year()==b.year() && a.month()<=b.month())
        return true;
    if(a.year()==b.year() && a.month()==b.month() && a.day()<=b.day())
        return true;
    return false;
}
//TODO: trova modo senza static_cast cast
std::ostream& operator<<(std::ostream& os, Date a)
{
    return os << a.day() << "/" << a.month() << "/" << a.year();
}

