#ifndef DATE_H
#define DATE_H
#include <ostream>

class Date{

public:

    enum Month{
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
//Costruttori
   
    Date ();                            //Costruttore di defualt: mettendola a quella odierna
    Date (int y, Month m, int d);
    Date(Date&& old);                   //Move constructor
    Date(const Date& old);              //Costruttore per copia

    void setDate(int y, Month m, int d); //Funzione per cambiare la data

    Date& operator=(const Date& a);
    Date& operator=(Date&& a);

    int day() const{return d_;};
    Month month() const{return m_;};
    int year() const{return y_;};

private:
    int y_, d_;
    Month m_;
    bool isLeap();                       //Controllo dell'anno bisestile
    bool isValid(int y, Month m, int d); //Controllo validità della data
};

//Overload operatori. Helper perché non alterano i valori interni dell'oggetto. Commutatività per operatori binari
bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);
bool operator>(const Date& a, const Date& b);
bool operator<(const Date& a, const Date& b);
bool operator>=(const Date& a, const Date& b);
bool operator<=(const Date& a, const Date& b);
std::ostream& operator<<(std::ostream& os, Date a);

#endif
