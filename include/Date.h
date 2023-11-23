#ifndef DATE_H
#define DATE_H
#include <ostream>

class Date{

public:    

    enum Month{
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
    Date (int y, Month m, int d);
    //CHECK se reference o meno
    Date& operator=(const Date& a);

    int day() const{return d_;};
    Month month() const{return m_;};
    int year() const{return y_;}; 

private:
    int y_, d_;
    Month m_;
    bool isLeap();
    bool isValid();
};

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);
bool operator>(const Date& a, const Date& b);
bool operator<(const Date& a, const Date& b);
bool operator>=(const Date& a, const Date& b);
bool operator<=(const Date& a, const Date& b);
std::ostream& operator<<(std::ostream& os, Date a);

//Sono diventato morte...il distruttore di header
#endif
