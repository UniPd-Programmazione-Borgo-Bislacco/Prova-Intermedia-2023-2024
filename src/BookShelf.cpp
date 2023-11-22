#include <iostream>
#include <stdexcept>
#include "../include/BookShelf.h"

using namespace std;

MyVector::MyVector(int s=1)
{
  if(s>=0){
    size=s;
    v=new Book::Book[s];
    capacity=s;
  }else{
    size=1;
    v=new Book::Book[1];
    capacity=1;
  }
}

MyVector::MyVector(initializer_list<Book::Book> lst)
  : size{lst.size()}, v{new Book::Book[lst.size()]}, capacity{lst.size()}
{
  copy(lst.begin(), lst.end(), v);
}

BookShelf(BookShelf&& old)
  : size{old.getSize()}, v{old.v}, capacity{old.getSize()}
{
    old.size=1;
    old.v=new Book::Book[1];
    old.capacity=1;
}

BookShelf(BookShelf& old)
  : size{lst.size()}, v{new Book::Book[old.getSize()]}, capacity{lst.size()}
{
    std::copy(old[0],old[old.getSize()-1],v);
}

BookShelf& operator=(BookShelf& b)
{
    size=b.size;
    capacity=b.capacity;
    for(int i=0;i<size;i++)
        v[i]=b[i];
}

BookShelf& operator=(BookShelf&& b)
{
    size=b.size;
    capacity=b.capacity;
    v=b.v;
    b.size=1;
    b.capacity=1;
    b.v=new Book::Book[1];
}
Book::Book MyVector::operator[](int i) const
{
  return v[i];
}

Book::Book& MyVector::operator[](int i)
{
  return v[i];
}

Book::Book& MyVector::at (int i)
{
  if(i>=size)
    throw(out_of_range("Out of bounds"));
  return v[i];
}

const Book::Book& MyVector::at (int i) const
{
  if(i>=size)
    throw(out_of_range("Out of bounds"));
  return v[i];
}

void MyVector::safe_set(int i, Book::Book b)
{
  if(i>size || i<0)
    throw(out_of_range("Out of bounds"));
  v[i]=b;
}

Book::Book MyVector::safe_get(int i)
{
  if(i>size || i<0)
    throw(out_of_range("Out of bounds"));
  return v[i];
}

void MyVector::push_back(Book::Book i)
{
  if (size>=(2*capacity/3))
    reserve(capacity*2);
  v[size]=i;
  size++;
}

Book::Book MyVector::pop_back()
{
  if (size<=(capacity/2))
    reduce(2*capacity/3);
  return v[size--];
}

void MyVector::reserve(unsigned d)
{
  if(d<=capacity)
    return;
  Book::Book* t=new Book::Book[d];
  for(unsigned i=0;i<size;i++){
    t[i]=v[i];
  }
  delete[] v;
  v=t;
  capacity=d;
}

void MyVector::reduce(unsigned d)
{
  if(d>=capacity)
    return;
  Book::Book* t=new Book::Book[d];
  for(unsigned i=0;i<size;i++){
    t[i]=v[i];
  }
  delete[] v;
  v=t;
  capacity=d;
}

unsigned MyVector::capacity()
{
    return capacity;
}

unsigned MyVector::length()
{
    return size;
}

MyVector::~MyVector()
{
  delete[] v;
}

