#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "Book.h"
#include <ostream>

class BookShelf{

public:
  BookShelf(int size);
  BookShelf(std::initializer_list<Book> lst);
  BookShelf(BookShelf& old);
  BookShelf(BookShelf&& old);

  BookShelf& operator=(BookShelf& b);
  BookShelf& operator=(BookShelf&& b);

  void pushBack(Book b);
  Book popBack();

  Book& at (int i);
  const Book& at (int i) const;

  void safeSet(int i, Book n);
  Book& safeGet(int i);

  void reserve(unsigned d);
  void reduce(unsigned d);
  unsigned size() const;
  unsigned capacity() const;

  Book operator[](int i) const;
  Book& operator[](int i);

  ~BookShelf();
private:
  Book* v_;
  unsigned long int size_;
  unsigned long int capacity_;
};

bool operator==(BookShelf b, BookShelf s);
bool operator!=(BookShelf b, BookShelf s);
bool operator<(BookShelf b, BookShelf s);
bool operator>(BookShelf b, BookShelf s);
bool operator<=(BookShelf b, BookShelf s);
bool operator>=(BookShelf b, BookShelf s);
std::ostream& operator<<(std::ostream& os, BookShelf b);

#endif
