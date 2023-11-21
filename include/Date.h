#include <ostream>

class Date{

public:    

    Date (int yy, Month mm, int dd);

    Date& operator=(const Date& a);

    int day() const;
    Month month() const;
    int year() const; 

private:
    unsigned int y, d;
    Month m;
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

enum class Month{
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};