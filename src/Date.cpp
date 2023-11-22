#include "../include/Date.h"

Date::Date (int y, Month m, int d)
    : y_{y}, m_{m}, d_{d}
    {
    }

//Non so se sia corretto passarlo come reference const
/*a: nope perché poi non puoi passare una stringa come parametro ma devi usare per forza una variabile
esempio: non puoi fare Date d("blabla") ma devi fare Date d(v)
*/
Date& Date::operator=(const Date a){
    y_=a.year();
    m_=a.month();
    d_=a.day();
    return *this;
}

int Date::day() const{return d_;}
Date::Month Date::month() const{return m_;}
int Date::year() const{return y_;} 

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

