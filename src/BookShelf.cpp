#include <ostream>
#include <string>
#include <stdexcept>
#include "../include/BookShelf.h"
#include "../include/Book.h"

BookShelf::BookShelf(int size=1)
{
  if(size>=0){
    size_=size;
    v_=new Book*[size];
    capacity_=size;
  }else{
    size_=1;
    v_=new Book*[1];
    capacity_=1;
  }
}

BookShelf::BookShelf(const std::initializer_list<Book>& lst)
  : size_{lst.size()}, v_{new Book*[lst.size()]}, capacity_{lst.size()}
{
  int i=0;
  for(Book b : lst)
  {
    v_[i++]=new Book{b};
  }
}

BookShelf::BookShelf(const BookShelf& old)
  : size_{old.size()}, v_{new Book*[old.size()]}, capacity_{old.size()}
{
  for(int i=0;i<old.size()-1;i++){
    v_[i]=new Book{old[i]};
  }
}

BookShelf::BookShelf(BookShelf&& old)
  : size_{old.size()}, v_{new Book*[old.size()]}, capacity_{old.size()}
{
  for(int i=0;i<old.size()-1;i++)
    v_[i]=new Book{old[i]};
  old.size_=1;
  old.v_=new Book*[1];
  old.capacity_=1;
}

BookShelf& BookShelf::operator=(const BookShelf& b)
{
  size_=b.size_;
  capacity_=b.capacity_;
  delete[] v_;
  v_=new Book*[size_];
  for(int i=0;i<b.size()-1;i++)
    v_[i]=new Book{b[i]};;
}

BookShelf& BookShelf::operator=(BookShelf&& b)
{
  size_=b.size_;
  capacity_=b.capacity_;
  delete[] v_;
  v_=new Book*[size_];
  for(int i=0;i<b.size()-1;i++)
    v_[i]=new Book{b[i]};;
  b.size_=1;
  b.capacity_=1;
  b.v_=new Book*[1];
}

void BookShelf::pushBack(const Book& i)
{
  if (size_>=(2*capacity_/3))
    reserve(capacity_*2);
  v_[size_]=new Book{i};
  size_++;
}

Book& BookShelf::popBack()
{
  if (size_<=(capacity_/2))
    reduce(2*capacity_/3);
  return *v_[size_--];
}

Book& BookShelf::at (int i)
{
  if(i>=size_)
    throw(std::out_of_range("Out of bounds"));
  return *v_[i];
}

const Book& BookShelf::at (int i) const
{
  if(i>=size_)
    throw(std::out_of_range("Out of bounds"));
  return *v_[i];
}

void BookShelf::safeSet(int i, const Book& b)
{
  if(i>size_ || i<0)
    throw(std::out_of_range("Out of bounds"));
  v_[i]=new Book{b};
}

Book& BookShelf::safeGet(int i)
{
  if(i>size_ || i<0)
    throw(std::out_of_range("Out of bounds"));
  return *v_[i];
}

void BookShelf::reserve(unsigned d)
{
  if(d<=capacity_)
    return;
  Book** t=new Book*[d];
  for(unsigned i=0;i<size_;i++){
    t[i]=v_[i];
  }
  delete[] v_;
  v_=t;
  capacity_=d;
}

void BookShelf::reduce(unsigned d)
{
  if(d>=capacity_)
    return;
  Book** t=new Book*[d];
  for(unsigned i=0;i<size_;i++){
    t[i]=v_[i];
  }
  delete[] v_;
  v_=t;
  capacity_=d;
}

unsigned BookShelf::size() const
{
  return size_;
}

unsigned BookShelf::capacity() const
{
  return capacity_;
}

Book BookShelf::operator[](int i) const
{
  return *v_[i];
}

Book& BookShelf::operator[](int i)
{
  return *v_[i];
}

BookShelf::~BookShelf()
{
  for(int i=0;i<size_;i++)
    delete v_[i];
  delete[] v_;
}

bool operator==(const BookShelf& b, const BookShelf& s)
{
  if(b.size()!=s.size())
    return false;
  for(int i=0;i<b.size();i++)
    if(b.at(i)!=s.at(i))
      return false;
  return true;
}
bool operator!=(const BookShelf& b, const BookShelf& s)
{
  return !(b==s);
}
bool operator<(const BookShelf& b, const BookShelf& s)
{
  if(b.size()<=s.size())
    return true;
  return false;
}
bool operator>(const BookShelf& b, const BookShelf& s)
{
  return !(b<=s);
}
bool operator<=(const BookShelf& b, const BookShelf& s)
{
  return !(s<b);
}
bool operator>=(const BookShelf& b, const BookShelf& s)
{
  return !(b<s);
}

std::ostream& operator<<(std::ostream& os, const BookShelf& b){
  os<<"Books:";
  for(int i=0;i<b.size();i++){
    os<<'\n';
    os<<b.at(i);
  }
  os<<'\n';
  return os;
}

