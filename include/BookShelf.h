#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "Book.h"
#include <ostream>

class BookShelf
{

public:
    BookShelf(int size = 1, bool blocked = false);                           // Costruttore con solo la dimensione in ingresso, utilizzabile di default
    BookShelf(const std::initializer_list<Book> &lst, bool blocked = false); // Costruttore con initializer list
    BookShelf(const BookShelf &old);                                         // Costruttore per copia
    BookShelf(BookShelf &&old);                                              // Move constructor

    BookShelf &operator=(const BookShelf &b); // Deep copy, non copia kBlocked
    BookShelf &operator=(BookShelf &&b);      // Move copy, non copia kBlocked

    void pushBack(const Book &b); // Può chiamare reserve(int) in caso l'array sia quasi pieno
    Book &popBack();              // Può chiamare reduce(int) in caso l'array sia quasi vuoto

    Book &at(int i);
    const Book &at(int i) const;

    void safeSet(int i, const Book &n);
    Book &safeGet(int i);

    void reserve(unsigned d); // Rialloca l'array con una dimensione maggiore
    void reduce(unsigned d);  // Rialloca l'array con una dimensione minore
    unsigned size() const { return size_; };
    unsigned capacity() const { return capacity_; };

    Book operator[](int i) const;
    Book &operator[](int i);

    ~BookShelf(); // Distruttore
private:
    Book **v_;                   // Puntatore utilizzato per puntare ad un array di puntatori a Book
    unsigned long int size_;     // Numero di Libri presenti
    unsigned long int capacity_; // Capacità massima
    const bool kBlocked_;
};

bool operator==(const BookShelf &b, const BookShelf &s);
bool operator!=(const BookShelf &b, const BookShelf &s);
bool operator<(const BookShelf &b, const BookShelf &s);
bool operator>(const BookShelf &b, const BookShelf &s);
bool operator<=(const BookShelf &b, const BookShelf &s);
bool operator>=(const BookShelf &b, const BookShelf &s);
std::ostream &operator<<(std::ostream &os, const BookShelf &b);

#endif
