#ifndef DATE_H
#define DATE_H
#include <ostream>

class Date{

public:

    enum Month{
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
    //Costruttori

    Date ();
    Date (int y, Month m, int d);
    Date(Date&& old);       //Move constructor
    Date(const Date& old);        //Costruttore per copia
    //CHECK se reference o meno
    // Date& operator=(const Date& a);
    void setDate(int y, Month m, int d);

    Date& operator=(const Date& a);
    Date& operator=(Date&& a);

    int day() const{return d_;};
    Month month() const{return m_;};
    int year() const{return y_;};

private:
    int y_, d_;
    Month m_;
    bool isLeap();  //Controllo dell'anno bisestile
    bool isValid(int y, Month m, int d); //Controllo validità della data
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
