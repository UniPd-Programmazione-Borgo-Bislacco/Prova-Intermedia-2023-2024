class Book{

public:

//Costruttori xForza
    book();
	book(std::string name, std::string surname, std::string title, std::string isbn, Date::Date date, bool is_available);
	book(book&& old);       //Move constructor
	book(book& old);        //Costruttore per copia

//Funzioni membro
	std::string getIsbn();
	std::string getTitle()
	std::string getName();
	std::string getSurname();
	Date::Date getDate();
	bool isAvailable();

	bool rent();
	bool back();

//Overload
	bool operator==(const book& b);
	bool operator=!(const book& b);


private:
	std::string isbn;
	std::string title;
	std::string name;
	std::string surname;
	Date::Date date;
	bool is_available;

};

//Overload Output
ostream& operator<<(ostream& os, book& b);
