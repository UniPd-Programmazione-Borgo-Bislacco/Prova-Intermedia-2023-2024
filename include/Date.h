class Date{

public:    

<<<<<<< Updated upstream
=======
    enum Month{
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
    //Costruttori
    Date();
>>>>>>> Stashed changes
    Date (int y, Month m, int d);
    
    int day() const;
    Month month() const;
    int year() const; 

    bool operator==(const Date& a);
    bool operator!=(const Date& a);
    bool operator>(const Date& a);
    bool operator<(const Date& a);
    bool operator>=(const Date& a);
    bool operator<=(const Date& a);

private:
    int y, d;
    Month m;
    bool isValid();
};



//Sono diventato morte...il distruttore di header

enum class Month{
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};