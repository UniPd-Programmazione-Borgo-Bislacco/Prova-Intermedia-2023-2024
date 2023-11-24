#include <iostream>
#include "../include/Book.h"
#include "../include/Date.h"
// #include "../include/BookShelf.h"
#include <string>
#include <stdexcept>

using namespace std;

void tester();
int main(){
    tester();
    return 0;
}

void tester(){
    Date::Month f {Date::Month::mar};

    Date d(2020,Date::Month::mar,1);
    Book mybook("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");
    // Book mybook{"David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4"};
    Book mybook2{"David2", "Foster Wallace", "Una cosa divertente che non farò mai più", "847-521-837-4"};
    // cout<<mybook;

    //TEST DATA
    cout << "\n--------- CONTROLLO COSTRUTTORE VUOTO ---------"<< endl;
    Date data1;
    cout << "Controllo vuoto:" << data1 << endl;

    cout << "\n--------- CONTROLLO DATA PRE-GREGORIANA ---------"<< endl;
    try{
        Date data2(1000, Date::Month::dec, 31);
        cout << data2 << endl ;
    }
    catch(std::invalid_argument const& e){
        cout << e.what() << endl;
    }

    cout << "\n--------- CONTROLLO DATA BISESTILE CORRETTA ---------"<< endl;
    try{
        Date data2(2000, Date::Month::feb, 29);
        cout << data2 << endl ;
    }
    catch(std::invalid_argument const& e){
        cout << e.what() << endl;
    }

    cout << "\n--------- CONTROLLO DATA BISESTILE ERRATA ---------"<< endl;
    try{
        Date data2(2013, Date::Month::feb, 29);
        cout << data2 << endl;
    }
    catch(std::invalid_argument const& e){
        cout << e.what() << endl;
    }

    cout << "\n--------- CONTROLLO DATA NON-BISESTILE d30 ---------"<< endl;
    try{
        Date data3(2013, Date::Month::apr, 30);
        Date data4(2013, Date::Month::jun, 30);
        Date data5(2013, Date::Month::sep, 30);
        Date data6(2013, Date::Month::nov, 30);
        cout << data3 << endl;
        cout << data4 << endl;
        cout << data5 << endl;
        cout << data6 << endl;
    }
    catch(std::invalid_argument const& e){
        cout << e.what() << endl;
    }

    cout << "\n--------- CONTROLLO DATA NON-BISESTILE d31 ---------"<< endl;
    try{
        Date data3(2013, Date::Month::jan, 31);
        Date data4(2013, Date::Month::mar, 31);
        Date data5(2013, Date::Month::may, 31);
        Date data6(2013, Date::Month::jul, 31);
        Date data7(2013, Date::Month::aug, 31);
        Date data8(2013, Date::Month::oct, 31);
        Date data9(2013, Date::Month::dec, 31);
        cout << data3 << endl;
        cout << data4 << endl;
        cout << data5 << endl;
        cout << data6 << endl;
        cout << data7 << endl;
        cout << data8 << endl;
        cout << data9 << endl;
    }
    catch(std::invalid_argument const& e){
        cout << e.what() << endl;
    }

    Date data3(2013, Date::Month::apr, 30);
    Date data4(2020, Date::Month::dec, 31);
    
    cout << "\n--------- CONTROLLO OVERLOAD = ---------"<< endl;

    cout << data3 << endl;
    cout << "Ora modifico valore" << endl;
    data3=data4;
    cout << "Valore modificato: "<< data3 << endl;
    

    Date data5(2013, Date::Month::apr, 30);
    Date data6(2013, Date::Month::apr, 30);
    Date data7(2003, Date::Month::apr, 20);
    
    cout << "\n--------- CONTROLLO OVERLOAD == ---------"<< endl;

    if(data5==data6)
        cout << "Sono uguali" << endl;
    else
        cout << "non sono uguali" << endl;

    data5 = data7;
    cout << "Cambiato valore" << endl;
    if(data5==data6)
        cout << "Sono uguali" << endl;
    else
        cout << "non sono uguali" << endl;

    cout << "\n--------- CONTROLLO OVERLOAD < ---------"<< endl;

    Date data8(2013, Date::Month::apr, 30);
    Date data9(2000, Date::Month::apr, 30);

    if(data8<data9)
        cout << "è minore" << endl;
    else
        cout << "è maggiore" << endl;

}
