#include "Book.h"

class BookShelf{

public:
    BookShelf(int size);
    BookShelf(std::initializer_list<Book> lst);
    BookShelf(BookShelf&& old);
    BookShelf(BookShelf& old);

    void pushBack(Book::Book b);
    Book::Book popBack();

    Book::Book& at (int i);
    const Book::Book& at (int i) const;

    void safeSet(int i, Book::Book n);
    double safeGet(int i);

    void reserve(unsigned d);
    void reduce(unsigned d);
    unsigned getSize();
    unsigned getCapacity();

    Book::Book operator[](int i) const;
    Book::Book& operator[](int i);

    ~BookShelf();
private:
    Book::Book* v;
    unsigned long int size;
    unsigned long int capacity;
};
