//MANCA setDate(va bene anche così), operator= , data defualt
#ifndef BOOK_H
#define BOOK_H

// #include <string>
#include <ostream>
#include "Date.h"

class Book{

public:

	//Costruttori xForza
	Book(std::string name, std::string surname, std::string title, std::string isbn, Date copyright_date=Date() ,bool is_available=kDefaultAvailable);
	// Book(std::string name, std::string surname, std::string title, std::string isbn, bool is_available=kDefaultAvailable);
	Book();
	// Book(std::string name, std::string surname, std::string title, std::string isbn, bool is_available=kDefaultAvailable);
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
	//TODO: togliere flag
	bool isDateProvided(void)const{return is_date_provided_;}
	void setName(std::string name);
	void setSurname(std::string surname);
	void setTitle(std::string title);
	void setIsbn(std::string isbn);
	// void setDate(Date copyright_date);
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
	//Flag usata per controllare se è stata passata una data
	bool is_date_provided_;
	//Flag per controllare se il libro è disponibile(true)  o in prestito (false)
	bool is_available_;
	//Preferisco usare un valore di default anche se è solo un booleano in caso si voglia cambiare se un libro è disponibile di default o meno
  	static constexpr int kDefaultAvailable = true;

};
	bool operator==(const Book& a,const Book& b);
	bool operator!=(const Book& a,const Book& b);

//Overload Output
std::ostream& operator<<(std::ostream& os, const Book& b);

#endif
