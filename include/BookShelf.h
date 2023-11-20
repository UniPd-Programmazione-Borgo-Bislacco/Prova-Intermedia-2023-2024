#include "book.h"

class BookShelf{

public:
	bookShelf();
	bookShelf(int size);

	void push_back(book::book b);
	book::book pop_back();

private:
    MyVector::MyVector shelf;
};
