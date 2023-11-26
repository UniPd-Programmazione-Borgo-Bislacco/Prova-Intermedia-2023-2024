#include <iostream>
#include <string>
#include <stdexcept>
#include "../include/BookShelf.h"
#include "../include/Book.h"

BookShelf::BookShelf(int size, bool blocked) : kBlocked_{blocked}
{
    if (size >= 0)
    {
        size_ = 0;
        v_ = new Book *[size];
        capacity_ = size;
    }
    else
    {
        size_ = 0;
        v_ = new Book *[1];
        capacity_ = 1;
    }
    for (int i = 0; i < size_; i++)
        v_[i] = nullptr;
}

BookShelf::BookShelf(const std::initializer_list<Book> &lst, bool blocked)
    : size_{lst.size()}, v_{new Book *[lst.size()]}, capacity_{lst.size()}, kBlocked_{blocked}
{
    int i = 0;
    for (Book b : lst)
    {
        v_[i++] = new Book{b};
    }
}

BookShelf::BookShelf(const BookShelf &old)
    : size_{old.size()}, v_{new Book *[old.size()]}, capacity_{old.size()}, kBlocked_{old.kBlocked_}
{
    for (int i = 0; i < old.size(); i++)
    {
        v_[i] = new Book{old[i]};
    }
}

BookShelf::BookShelf(BookShelf &&old)
    : size_{old.size()}, v_{new Book *[old.size()]}, capacity_{old.size()}, kBlocked_{old.kBlocked_}
{
    v_ = old.v_;
    old.size_ = 0;
    old.v_ = new Book *[1];
    old.v_[0] = nullptr;
    old.capacity_ = 1;
}

BookShelf &BookShelf::operator=(const BookShelf &b)
{
    if (this == &b)
        return *this;
    capacity_ = b.capacity_;
    if (size_ != b.size_)
    {
        int t_s = size_;
        size_ = b.size_;
        for (int i = 0; i < t_s; i++)
            delete v_[i];
        delete[] v_;
        v_ = new Book *[size_];
    }
    for (int i = 0; i < b.size() - 1; i++)
        v_[i] = new Book{b[i]};
    return *this;
}

BookShelf &BookShelf::operator=(BookShelf &&b)
{
    if (this == &b)
        return *this;
    size_ = b.size_;
    capacity_ = b.capacity_;
    delete[] v_;
    v_ = b.v_;
    b.size_ = 0;
    b.v_ = new Book *[1];
    b.v_[0] = nullptr;
    b.capacity_ = 1;
    return *this;
}

void BookShelf::pushBack(const Book &i)
{
    if (!(kBlocked_) && size_ >= (2 * capacity_ / 3))
        reserve(capacity_ * 2);
    if (size_ != capacity_)
        v_[size_++] = new Book{i};
    else
        throw(std::out_of_range("Libreria piena"));
}

void BookShelf::popBack()
{
    if (size_ == 0)
        throw(std::out_of_range("Indice fuori dai limiti"));
    if (!(kBlocked_) && size_ <= (capacity_ / 2))
        reduce(2 * capacity_ / 3);
    delete v_[(size_--) - 1];
}

Book &BookShelf::at(int i)
{
    if (i >= size_ || i < 0)
        throw(std::out_of_range("Indice fuori dai limiti"));
    return *v_[i];
}

const Book &BookShelf::at(int i) const
{
    if (i >= size_ || i < 0)
        throw(std::out_of_range("Indice fuori dai limiti"));
    if (v_[i] == nullptr)
        throw(std::invalid_argument("Libro non presente"));
    return *v_[i];
}

void BookShelf::safeSet(int i, const Book &b)
{
    if (i > size_ || i < 0)
        throw(std::out_of_range("Indice fuori dai limiti"));
    v_[i] = new Book{b};
}

Book &BookShelf::safeGet(int i)
{
    if (i > size_ || i < 0)
        throw(std::out_of_range("Indice fuori dai limiti"));
    if (v_[i] == nullptr)
        throw(std::invalid_argument("Libro non presente"));
    return *v_[i];
}

void BookShelf::reserve(unsigned d)
{
    if (d <= capacity_)
        return;
    if (kBlocked_)
        throw(std::out_of_range("Dimensione della libreria bloccata"));
    Book **t = new Book *[d];
    for (unsigned i = 0; i < size_; i++)
    {
        t[i] = v_[i];
    }
    delete[] v_;
    v_ = t;
    capacity_ = d;
}

void BookShelf::reduce(unsigned d)
{
    if (d >= capacity_)
        return;
    if (kBlocked_)
        throw(std::out_of_range("Dimensione della libreria bloccata"));
    if (d <= 0)
        throw(std::invalid_argument("Dimensione impossibile"));
    Book **t = new Book *[d];
    for (unsigned i = 0; i < size_; i++)
    {
        t[i] = v_[i];
    }
    delete[] v_;
    v_ = t;
    capacity_ = d;
}

Book BookShelf::operator[](int i) const
{
    return *v_[i];
}

Book &BookShelf::operator[](int i)
{
    return *v_[i];
}

BookShelf::~BookShelf()
{
    size_ = 0;
    capacity_ = 0;
    for (int i = 0; i < size_; i++)
        delete v_[i];
    delete[] v_;
}

bool operator==(const BookShelf &b, const BookShelf &s)
{
    if (b.size() != s.size())
        return false;
    for (int i = 0; i < b.size(); i++)
        if (b.at(i) != s.at(i))
            return false;
    return true;
}
bool operator!=(const BookShelf &b, const BookShelf &s)
{
    return !(b == s);
}
bool operator<(const BookShelf &b, const BookShelf &s)
{
    if (b.size() <= s.size())
        return true;
    return false;
}
bool operator>(const BookShelf &b, const BookShelf &s)
{
    return !(b <= s);
}
bool operator<=(const BookShelf &b, const BookShelf &s)
{
    return !(s < b);
}
bool operator>=(const BookShelf &b, const BookShelf &s)
{
    return !(b < s);
}

std::ostream &operator<<(std::ostream &os, const BookShelf &b)
{
    os << "Books: ";
    for (int i = 0; i < b.size(); i++)
    {
        os << '\n';
        try
        {
            os << b.at(i);
        }
        catch (std::invalid_argument const &e)
        {
            os << "** vuoto **";
        }
    }
    return os;
}
