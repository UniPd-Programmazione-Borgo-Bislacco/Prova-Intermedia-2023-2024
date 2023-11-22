#include "Date.h"

Date::Date (int yy, Month mm, int dd)
    : y{yy}, m{mm}, d{dd}
    {
        
    }

//Non so se sia corretto passarlo come reference const
/*a: nope perché poi non puoi passare una stringa come parametro ma devi usare per forza una variabile
esempio: non puoi fare Date d("blabla") ma devi fare Date d(v)
*/
Date& Date::operator=(const Date a){
    y=a.year();
    m=a.month();
    d=a.day();
    return *this;
}

int Date::day() const{return d_;}
Month Date::month() const{return m_;}
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

//Non so se ci sia bisogno di questo overload, ma nel dubbio l'ho fatto
//da editor mi da errore sul << forse a causa dell'overload di <
std::ostream& operator<<(std::ostream& os, Date a)
{
    return os << a.day() << "/" << a.month() << "/" << a.year();
}

