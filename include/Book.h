#ifndef BOOK_H
#define BOOK_H

// #include <string>
#include <ostream>
#include "Date.h"

class Book{

public:

	//Costruttori xForza
	Book(std::string name, std::string surname, std::string title, std::string isbn, Date copyright_date ,bool is_available=kDefaultAvailable);
	Book(std::string name, std::string surname, std::string title, std::string isbn, bool is_available=kDefaultAvailable);
	Book();
	// Book(std::string name, std::string surname, std::string title, std::string isbn, bool is_available=kDefaultAvailable);
	Book(Book&& old);       //Move constructor
	Book(Book& old);        //Costruttore per copia

	//Funzioni membro
	std::string name(void) const{ return name_;}
	std::string surname(void) const {return surname_;}
	std::string title(void) const {return title_;}
	std::string isbn(void)  const {return isbn_;}
	//TODO vedere costruttore di copia
	Date date(void)  {return copyright_date_;}
	bool isAvailable(void) const {return is_available_;}

	void setName(std::string name);
	void setSurname(std::string surname);
	void setTitle(std::string title);
	void setIsbn(std::string isbn);
	void setDate(Date copyright_date);
	void setAvailable(bool is_available);

	//Per gestire il prestito o il ritorno del libro
	void rent();
	void back();

//Overload


private:
	std::string name_;
	std::string surname_;
	std::string title_;
	std::string isbn_;
	Date copyright_date_;
	bool is_available_;
	//Preferisco usare un valore di default anche se è solo un booleano in caso si voglia cambiare se un libro è disponibile di default o meno
    static constexpr int kDefaultAvailable = true;
   	// Date kDefaultDate = {2020,Date::Month::mar,1};

};
	bool operator==(const Book& a,const Book& b);
	bool operator!=(const Book& a,const Book& b);

//Overload Output
std::ostream& operator<<(std::ostream& os, Book& b);

#endif