#include <ostream>

class Date{

public:    

    enum class Month{
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };    
    Date (int y, Month m, int d);

    Date& operator=(const Date& a);

    int day() const;
    Month month() const;
    int year() const; 
   
private:
    unsigned int y_, d_;
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
