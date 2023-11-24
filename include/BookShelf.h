#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "Book.h"
#include <ostream>

class BookShelf{

public:
  BookShelf(int size=1);
  BookShelf(const std::initializer_list<Book>& lst);
  BookShelf(const BookShelf& old);
  BookShelf(BookShelf&& old);

  BookShelf& operator=(const BookShelf& b);
  BookShelf& operator=(BookShelf&& b);

  void pushBack(const Book& b);
  Book& popBack();

  Book& at (int i);
  const Book& at (int i) const;

  void safeSet(int i, const Book& n);
  Book& safeGet(int i);

  void reserve(unsigned d);
  void reduce(unsigned d);
  unsigned size() const     {return size_;};
  unsigned capacity() const {return capacity_;};

  Book operator[](int i) const;
  Book& operator[](int i);

  ~BookShelf();
private:
  Book** v_;
  unsigned long int size_;
  unsigned long int capacity_;
};

bool operator==(const BookShelf& b, const BookShelf& s);
bool operator!=(const BookShelf& b, const BookShelf& s);
bool operator<(const BookShelf& b, const BookShelf& s);
bool operator>(const BookShelf& b, const BookShelf& s);
bool operator<=(const BookShelf& b, const BookShelf& s);
bool operator>=(const BookShelf& b, const BookShelf& s);
std::ostream& operator<<(std::ostream& os, const BookShelf& b);

#endif
