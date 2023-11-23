#ifndef BOOK_H
#define BOOK_H

// #include <string>
#include <ostream>
// #include "Date.h"
class Book{

public:

	//Costruttori xForza
   
	Book(std::string name, std::string surname, std::string title, std::string isbn, bool is_available=kDefaultAvailable);
	// Book(std::string name, std::string surname, std::string title, std::string isbn, bool is_available=kDefaultAvailable);
	Book(Book&& old);       //Move constructor
	Book(Book& old);        //Costruttore per copia

	//Funzioni membro
	std::string name(void) const{ return name_;}
	std::string surname(void) const {return surname_;}
	std::string title(void) const {return title_;}
	std::string isbn(void)  const {return isbn_;}
	// Date::Date date(void) const {return date_;}
	bool isAvailable(void) const {return is_available_;}

	void setName(std::string name);
	void setSurname(std::string surname);
	void setTitle(std::string title);
	void setIsbn(std::string isbn);
	// void setDate(Date::Date date);

	//Per gestire il prestito o il ritorno del libro
	void rent();
	void back();

//Overload
	bool operator==(const Book& b);
	bool operator!=(const Book& b);


private:
	std::string name_;
	std::string surname_;
	std::string title_;
	std::string isbn_;
	// Date date_;
	bool is_available_;
	//Preferisco usare un valore di default anche se è solo un booleano in caso si voglia cambiare se un libro è disponibile di default o meno
    static constexpr int kDefaultAvailable = true;
   	// Date kDefaultDate = {2020,Date::Month::mar,1};

};

//Overload Output
std::ostream& operator<<(std::ostream& os, Book& b);

#endif