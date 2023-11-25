#include <iostream>
#include "../include/Book.h"
#include "../include/Date.h"
#include "../include/BookShelf.h"
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
    cout<<mybook;

    //TEST DATA
    cout << "\n--------- DATE: CONTROLLO COSTRUTTORE VUOTO ---------"<< endl;
    Date data1;
    cout << "Controllo vuoto:" << data1 << endl;

    cout << "\n--------- DATE: CONTROLLO DATA PRE-GREGORIANA ---------"<< endl;
    try{
        Date data2(1000, Date::Month::dec, 31);
        cout << data2 << endl ;
    }
    catch(std::invalid_argument const& e){
        cout << e.what() << endl;
    }

    cout << "\n--------- DATE: CONTROLLO DATA BISESTILE CORRETTA ---------"<< endl;
    try{
        Date data2(2000, Date::Month::feb, 29);
        cout << data2 << endl ;
    }
    catch(std::invalid_argument const& e){
        cout << e.what() << endl;
    }

    cout << "\n--------- DATE: CONTROLLO DATA BISESTILE ERRATA ---------"<< endl;
    try{
        Date data2(2013, Date::Month::feb, 29);
        cout << data2 << endl;
    }
    catch(std::invalid_argument const& e){
        cout << e.what() << endl;
    }

    cout << "\n--------- DATE: CONTROLLO DATA NON-BISESTILE d30 ---------"<< endl;
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

    cout << "\n--------- DATE: CONTROLLO DATA NON-BISESTILE d31 ---------"<< endl;
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

    cout << "\n--------- DATE: CONTROLLO OVERLOAD = ---------"<< endl;

    cout << data3 << endl;
    cout << "Ora modifico valore" << endl;
    data3=data4;
    cout << "Valore modificato: "<< data3 << endl;


    Date data5(2013, Date::Month::apr, 30);
    Date data6(2013, Date::Month::apr, 30);
    Date data7(2003, Date::Month::apr, 20);

    cout << "\n--------- DATE: CONTROLLO OVERLOAD == ---------"<< endl;

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

    cout << "\n--------- DATE: CONTROLLO OVERLOAD < ---------"<< endl;

    Date data8(2013, Date::Month::apr, 30);
    Date data9(2000, Date::Month::apr, 30);

    if(data8<data9)
        cout << "è minore" << endl;
    else
        cout << "è maggiore" << endl;

    cout << "\n--------- BOOKSHELF: CONTROLLO COSTRUTTORE VUOTO < ---------"<< endl;

    BookShelf bs1;
    cout<<bs1<<endl;

    cout << "\n--------- BOOKSHELF: CONTROLLO COSTRUTTORE INIZIALIZER LIST < ---------"<< endl;

    BookShelf bs2{mybook,mybook2};
    cout<<bs2<<endl;

    cout << "\n--------- BOOKSHELF: CONTROLLO CREAZIONE LIBRERIA A DIMENSIONE FISSA < ---------"<< endl;

    BookShelf bs_b{4,true};
    cout<<"\n\t - dimensione massima: "<<bs_b.capacity()<<", aggiunta "<<(bs_b.capacity()+1)<<" libri < ---------"<<endl;
    try{
      for(int i=0;i<=bs_b.capacity();i++){
        bs_b.pushBack(mybook);
        cout<<"Libro numero "<<(i+1)<<" inserito"<<endl;
      }
    }catch(std::out_of_range const& e){
      cout<<e.what()<<endl;
    }

    cout << "\n--------- BOOKSHELF: CONTROLLO COSTRUTTORE PER COPIA < ---------"<< endl;

    BookShelf bs3{bs2};
    cout<<bs3<<endl;

    cout << "\n--------- BOOKSHELF: CONTROLLO MOVE CONSTRUCTOR < ---------"<< endl;

    BookShelf bs4{std::move(bs2)};
    cout<<bs4<<endl;

    cout << "\n--------- BOOKSHELF: CONTROLLO ASSEGNAZIONE < ---------"<< endl;

    cout<<"\n\t - creazione libro < ---------"<<endl;
    Book new_book("Giorgio","Barberi Squarotti","AUTORI e OPERE","88-268-1570-1");
    cout<<"\n\t - assegnazione libro al precedente BookShelf< ---------"<<endl;
    bs4[0]=new_book;
    cout<<bs4<<endl;

    cout << "\n--------- BOOKSHELF: CONTROLLO PUSH E RESERVE < ---------"<< endl;

    cout<<"\n\t - capacita' iniziale: "<<bs4.capacity()<<" < ---------"<<endl;
    for(int i=0;i<80;i++)
      bs4.pushBack(new_book);
    cout<<"\n\t - capacita' finale: "<<bs4.capacity()<<" < ---------"<<endl;

    cout << "\n--------- BOOKSHELF: CONTROLLO POP E REDUCE < ---------"<< endl;

    cout<<"\n\t - capacita' iniziale: "<<bs4.capacity()<<" < ---------"<<endl;
    for(int i=0;i<79;i++)
      bs4.popBack();
    Book last_book=bs4.popBack();
    cout<<"\n\t - capacita' finale: "<<bs4.capacity()<<" ed ultimo libro estratto: < ---------"<<endl<<endl;
    cout<<last_book<<endl;

    cout << "\n--------- BOOKSHELF: CONTROLLO OVERLOAD < ---------"<< endl;

    cout<<"\n\t - confronto prima e seconda BookShelf: < ---------"<<endl;
    if(bs1==bs2)
      cout<<"\n\t\t - uguali"<<endl;
    else
      cout<<"\n\t\t - diverse"<<endl;
    cout<<"\n\t - confronto seconda e quarta BookShelf per numero di libri: < ---------"<<endl;
    if(bs2>bs4)
      cout<<"\n\t\t - bs2>b4"<<endl;
    else
      cout<<"\n\t\t - bs2<=bs4"<<endl;
}
