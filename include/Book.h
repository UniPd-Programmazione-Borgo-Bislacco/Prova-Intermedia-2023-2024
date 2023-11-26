//MANCA setDate(va bene anche così), operator= , data defualt
#ifndef BOOK_H
#define BOOK_H

// #include <string>
#include <ostream>
#include "Date.h"

class Book{

public:

//Costruttori 
	Book();
	//Costruttore con parametri. La data di defualt è 1/1/1709: nascita del copyright. 
	//Leggere README.md!
	Book(std::string name, std::string surname, std::string title, std::string isbn, Date copyright_date=Date(1709,Date::Month::jan, 1) ,bool is_available=kDefaultAvailable);

	Book(Book&& old);       //Move constructor
	Book(const Book& old);        //Costruttore per copia

	Book& operator=(const Book& old);
	Book& operator=(Book&& old);

	//Funzioni membro
	std::string name(void) const{ return name_;}
	std::string surname(void) const {return surname_;}
	std::string title(void) const {return title_;}
	std::string isbn(void)  const {return isbn_;}
	Date date(void)  const {return copyright_date_;}

	bool isAvailable(void) const {return is_available_;}
	void setName(std::string name);
	void setSurname(std::string surname);
	void setTitle(std::string title);
	void setIsbn(std::string isbn);
	void setDate(Date copyright_date);
	void setAvailable(bool is_available);

	//Per gestire il prestito o il ritorno del libro. Cambia la flag is_available_ con gli appositi controlli.
	void rent();
	void back();

//Overload


private:
	std::string name_;
	std::string surname_;
	std::string title_;
	std::string isbn_;
	Date copyright_date_;
	//Flag per controllare se il libro è disponibile(true)  o in prestito (false)
	bool is_available_;
	//Preferisco usare un valore di default anche se è solo un booleano in caso si voglia cambiare se un libro è disponibile di default o meno
  	static constexpr int kDefaultAvailable = true;
	// static constexpr Date kDefaultDate = Date(1709,Date::Month::jan, 1);
};
	bool operator==(const Book& a,const Book& b);
	bool operator!=(const Book& a,const Book& b);

//Overload Output
std::ostream& operator<<(std::ostream& os, const Book& b);

#endif
