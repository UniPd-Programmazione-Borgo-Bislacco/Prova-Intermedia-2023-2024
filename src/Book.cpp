#include "../include/Book.h"

#include <string>
#include <stdexcept>

Book::Book(std::string name, std::string surname, std::string title, std::string isbn,  bool is_available) 
    :name_{name},surname_{surname},title_{title}, isbn_{isbn},is_available_{is_available}
{
        if (isbn.size() != 13) {
            throw std::invalid_argument("Il codice ISBN deve essere di 13 caratteri.");
        }
    

}


void Book::setIsbn(std::string isbn){
    if (isbn.size() != 13) {
        throw std::invalid_argument("Il codice ISBN deve essere di 13 caratteri.");
    }
    isbn_ = isbn;

}

void Book::setTitle(std::string name){name_ = name;}

void Book::setSurname(std::string surname){surname_ = surname;}

// void Book::setDate(Date::Date date){date_ = date;}

void Book::rent(){
    if(!is_available_) throw std::logic_error("Il libro è già in prestito!");
    is_available_=false;
}

void Book::back(){
    if(is_available_) throw std::logic_error("Il libro era già disponibile. Non può esser stato restituito.");
    is_available_=true;
}

bool operator==(const Book& a,const Book& b){
    return a.isbn()==b.isbn();
}

bool operator!=(const Book& a,const Book& b){
    return a.isbn()!=b.isbn();
}
