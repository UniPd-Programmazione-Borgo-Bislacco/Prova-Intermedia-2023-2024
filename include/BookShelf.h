#ifndef "BOOKSHELF_H"
#define "BOOKSHELF_H"
#include "Book.h"
#include <ostream>

class BookShelf{

public:
    BookShelf(int size);
    BookShelf(std::initializer_list<Book> lst);
    BookShelf(BookShelf&& old);
    BookShelf(BookShelf& old);

    BookShelf& operator=(BookShelf& b);
    BookShelf& operator=(BookShelf&& b);

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

bool operator==(BookShelf b, BookShelf s);
bool operator!=(BookShelf b, BookShelf s);
bool operator<(BookShelf b, BookShelf s);
bool operator>(BookShelf b, BookShelf s);
bool operator<=(BookShelf b, BookShelf s);
bool operator>=(BookShelf b, BookShelf s);
ostream& operator<<(ostream& os, BookShelf b);

#endif
