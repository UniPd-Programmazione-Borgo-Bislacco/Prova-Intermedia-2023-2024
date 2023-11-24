#include "../include/Book.h"
#include <iostream>

// #include <string>
#include <stdexcept>

/*Book::Book(bool valid)
  :name_{""},surname_{""},title_{""}, isbn_{""},date_{valid},is_available_{false}
{

}*/
Book::Book(std::string name, std::string surname, std::string title, std::string isbn,  bool is_available)
     :name_{name},surname_{surname},title_{title}, isbn_{isbn},copyright_date_{Date()}, is_available_{is_available}
{
        if (isbn.size() != 13) {
            throw std::invalid_argument("Il codice ISBN deve essere di 13 caratteri.");
        }
}
Book::Book(std::string name, std::string surname, std::string title, std::string isbn, Date copyright_date,  bool is_available)
     :name_{name},surname_{surname},title_{title}, isbn_{isbn},copyright_date_{copyright_date}, is_available_{is_available}

{
if (isbn.size() != 13) {
    throw std::invalid_argument("Il codice ISBN deve essere di 13 caratteri.");
  }
}

// Book::Book(std::string name, std::string surname, std::string title, std::string isbn,  bool is_available)
//   :name_{name},surname_{surname},title_{title}, isbn_{isbn},is_available_{is_available}
// {
//   if (isbn.size() != 13) {
//     throw std::invalid_argument("Il codice ISBN deve essere di 13 caratteri.");
//   }
// }

Book::Book(Book&& old)
  :name_{old.name_},surname_{old.surname_},title_{old.title_},isbn_{old.isbn_},copyright_date_{old.copyright_date_},is_available_{old.is_available_}
{
  old.setName("");
  old.setSurname("");
  old.setTitle("");
  old.setIsbn("");
  old.setAvailable(false);
}
Book::Book(const Book& old)
  :name_{old.name_},surname_{old.surname_},title_{old.title_},isbn_{old.isbn_},copyright_date_{old.copyright_date_},is_available_{old.is_available_}
{
}

void Book::setIsbn(std::string isbn){
  if (isbn.size() != 13) {
    throw std::invalid_argument("Il codice ISBN deve essere di 13 caratteri.");
  }
  isbn_ = isbn;
}

void Book::setTitle(std::string title){title_ = title;}
void Book::setName(std::string name){name_ = name;}

void Book::setSurname(std::string surname){surname_ = surname;}

// void Book::setDate(Date copyright_date){copyright_date_ = copyright_date;}

void Book::setAvailable(bool is_available){is_available_ = is_available;}

void Book::rent(){
    if(!is_available_) throw std::logic_error("Il libro è già in prestito!");
    setAvailable(false);
}

void Book::back(){
    if(is_available_) throw std::logic_error("Il libro era già disponibile. Non può esser stato restituito.");
    setAvailable(true);
}

Book& Book::operator=(const Book& old){
  if(old==(*this))
    return *this;
  setName(old.name_);
	setSurname(old.surname_);
	setTitle(old.title_);
	setIsbn(old.isbn_);
	setAvailable(old.is_available_);
  copyright_date_=old.copyright_date_;
  return *this;
}
Book& Book::operator=(Book&& old){
  if(old==(*this))
    return *this;
  setName(old.name_);
	setSurname(old.surname_);
	setTitle(old.title_);
	setIsbn(old.isbn_);
	setAvailable(old.is_available_);
  copyright_date_=old.copyright_date_;

  old.setName("");
	old.setSurname("");
	setTitle("");
	setIsbn("");
	setAvailable(false);
  copyright_date_=old.copyright_date_;
  return *this;
}


bool operator==(const Book& a,const Book& b){
    return a.isbn()==b.isbn();
}

bool operator!=(const Book& a,const Book& b){
    return a.isbn()!=b.isbn();
}
std::ostream& operator<<(std::ostream& os, const Book& b){
    return os <<"Titolo: "<<b.title()<<std::endl
                <<"Autore: "<<b.name()<<" "<<b.surname()<<std::endl
                <<"ISBN: " <<b.isbn()<<std::endl;

 }



