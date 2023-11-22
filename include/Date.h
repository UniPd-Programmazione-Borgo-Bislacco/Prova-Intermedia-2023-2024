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
    Date& operator=(const Date a);

    int day() const;
    Month month() const;
    int year() const; 

private:
    int y_, d_;
    Month m_;
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
