#include "../include/Date.h"
Date::Date ()
    : y_{0}, m_{Month::jan}, d_{1}
    {
    }
Date::Date (int y, Month m, int d)
    : y_{y}, m_{m}, d_{d}
    {
    }

//Non so se sia corretto passarlo come reference const

Date& Date::operator=(const Date& a){
    y_=a.year();
    m_=a.month();
    d_=a.day();
    return *this;
}
//Move constructor
Date::Date(Date&& old)
    : y_{old.year()}, m_{old.month()}, d_{old.day()}
{

    //Qua bisogna scegliere cosa fare con la vecchia data

}  
//Copy Constructor     
Date::Date(Date& old)
    : y_{old.year()}, m_{old.month()}, d_{old.day()}
{
}

// int Date::day() const{return d_;}
// Date::month() {return m_;}
// int Date::year() const{return y_;} 

bool Date::isValid(){
    switch(m_){
        case(4,6,9,11):if(d_<1 || d_>30) return false; break;
        case(2): 
            if(isLeap())
                if(d_<1 || d_>29)
                {                        
                    return false; 
                }
            else
                if(d_<1 || d_<28)
                    return false;
            break;
        default:if(d_<1 || d_>31) return false;
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

