#include <iostream>
#include <stdexcept>
#include "../include/BookShelf.h"

using namespace std;

BookShelf::BookShelf(int size=1)
{
  if(s>=0){
    size_=s;
    v_=new Book::Book[s];
    capacity_=s;
  }else{
    size_=1;
    v_=new Book::Book[1];
    capacity_=1;
  }
}

BookShelf::BookShelf(initializer_list<Book::Book> lst)
  : size_{lst.size()}, v_{new Book::Book[lst.size()]}, capacity_{lst.size()}
{
  copy(lst.begin(), lst.end(), v_);
}

BookShelf(BookShelf&& old)
  : size_{old.size()}, v_{new Book::Book[old.getize()]}, capacity_{old.size()}
{
  std::copy(old[0],old[old.size()-1],v_);
  old.size_=1;
  old.v_=new Book::Book[1];
  old.capacity_=1;
}

BookShelf(BookShelf& old)
  : size_{old.size()}, v_{new Book::Book[old.size()]}, capacity_{old.size()}
{
  std::copy(old[0],old[old.size()-1],v_);
}

BookShelf& operator=(BookShelf& b)
{
  size_=b.size_;
  capacity_=b.capacity_;
  delete[] v_;
  v_=new Book::Book[size_];
  std::copy(b[0],b[b.size()-1],v_);
}

BookShelf& operator=(BookShelf&& b)
{
  size_=b.size_;
  capacity_=b.capacity_;
  delete[] v_;
  v_=new Book::Book[size_];
  std::copy(b[0],b[b.size()-1],v_);
  b.size_=1;
  b.capacity_=1;
  b.v_=new Book::Book[1];
}

void BookShelf::push_back(Book::Book i)
{
  if (size_>=(2*capacity/3))
    reserve(capacity*2);
  v[size_]=i;
  size_++;
}

Book::Book BookShelf::pop_back()
{
  if (size_<=(capacity_/2))
    reduce(2*capacity_/3);
  return v_[size_--];
}

Book::Book& BookShelf::at (int i)
{
  if(i>=size_)
    throw(out_of_range("Out of bounds"));
  return v_[i];
}

const Book::Book& BookShelf::at (int i) const
{
  if(i>=size_)
    throw(out_of_range("Out of bounds"));
  return v_[i];
}

void BookShelf::safe_set(int i, Book::Book b)
{
  if(i>size_ || i<0)
    throw(out_of_range("Out of bounds"));
  v_[i]=b;
}

Book::Book& BookShelf::safe_get(int i)
{
  if(i>size_ || i<0)
    throw(out_of_range("Out of bounds"));
  return v_[i];
}

void BookShelf::reserve(unsigned d)
{
  if(d<=capacity_)
    return;
  Book::Book* t=new Book::Book[d];
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
  Book::Book* t=new Book::Book[d];
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

Book::Book BookShelf::operator[](int i) const
{
  return v_[i];
}

Book::Book& BookShelf::operator[](int i)
{
  return v_[i];
}

BookShelf::~BookShelf()
{
  delete[] v_;
}

