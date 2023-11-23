#include "../include/Book.h"
#include <iostream>

#include <string>
#include <stdexcept>

Book::Book(std::string name, std::string surname, std::string title, std::string isbn,  bool is_available) 
<<<<<<< Updated upstream
    :name_{name},surname_{surname},title_{title}, isbn_{isbn},is_available_{is_available}
=======
     :name_{name},surname_{surname},title_{title}, isbn_{isbn},copyright_date_{Date()}, is_available_{is_available}
{
        if (isbn.size() != 13) {
            throw std::invalid_argument("Il codice ISBN deve essere di 13 caratteri.");
        }
}
Book::Book(std::string name, std::string surname, std::string title, std::string isbn, Date copyright_date,  bool is_available) 
     :name_{name},surname_{surname},title_{title}, isbn_{isbn},copyright_date_{copyright_date}, is_available_{is_available}
>>>>>>> Stashed changes
{
        if (isbn.size() != 13) {
            throw std::invalid_argument("Il codice ISBN deve essere di 13 caratteri.");
        }
    

}
<<<<<<< Updated upstream


=======
>>>>>>> Stashed changes
void Book::setIsbn(std::string isbn){
    if (isbn.size() != 13) {
        throw std::invalid_argument("Il codice ISBN deve essere di 13 caratteri.");
    }
    isbn_ = isbn;

}

void Book::setTitle(std::string name){name_ = name;}

void Book::setSurname(std::string surname){surname_ = surname;}

void Book::setDate(Date copyright_date){copyright_date_ = copyright_date;}

void Book::rent(){
    if(!is_available_) throw std::logic_error("Il libro è già in prestito!");
    is_available_=false;
}

void Book::back(){
    if(is_available_) throw std::logic_error("Il libro era già disponibile. Non può esser stato restituito.");
    is_available_=true;
}
//TODO -
bool operator==(const Book& a,const Book& b){
    return a.isbn()==b.isbn();
}

bool operator!=(const Book& a,const Book& b){
    return a.isbn()!=b.isbn();
}
<<<<<<< Updated upstream
// std::ostream& operator<<(std::ostream& os, Book b){
//     return os <<"Titolo: "<<b.title()<<std::endl
//                 <<"Autore: "<<b.name()<<" "<<b.surname()<<std::endl
//                 <<"ISBN: " <<b.isbn()<<std::endl;
=======
std::ostream& operator<<(std::ostream& os, Book& b){
    // if(b.date){
    // std::cout<<"Cout"endl;

    // }
    
    return os <<"Titolo: "<<b.title()<<std::endl
                <<"Autore: "<<b.name()<<" "<<b.surname()<<std::endl
                <<"ISBN: " <<b.isbn()<<std::endl
                <<"Date: "<<b.date()<<std::endl; 
 }
>>>>>>> Stashed changes

// }
std::ostream& operator<<(std::ostream& os, Book b){
    return os <<"Titolo: ";

}

