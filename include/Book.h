#ifndef BOOK_H
#define BOOK_H
class Book{

public:

	//Costruttori xForza
    book();
	book(std::string& name, std::string& surname, std::string& title, std::string& isbn, Date::Date date, bool is_available=kDefaultAvailable);
	book(book&& old);       //Move constructor
	book(book& old);        //Costruttore per copia

	//Funzioni membro
	std::string isbn(void)  const {return isbn_;}
	std::string title(void) const {return title_;}
	std::string name(void) const{ return name_;}
	std::string surname(void) const {return surname_;}
	Date::Date date(void) const {return date_;}
	bool isAvailable(void) const {return is_available_;}

	void setIsbn(std::string isbn);
	void setTitle(std::string title);
	void setName(std::string name);
	void setSurname(std::string surname);
	void setDate(Date::Date date);

	//Per gestire il prestito o il ritorno del libro
	void rent();
	void back();

//Overload
	bool operator==(const book& a,const book& b);
	bool operator=!(const book& a,const book& b);


private:
	std::string isbn_;
	std::string title_;
	std::string name_;
	std::string surname_;
	Date::Date date_;
	bool is_available_;
	//Preferisco usare un valore di default anche se è solo un booleano in caso si voglia cambiare
    static constexpr int kDefaultAvailable = true;

};

//Overload Output
ostream& operator<<(ostream& os, book& b);

#endif