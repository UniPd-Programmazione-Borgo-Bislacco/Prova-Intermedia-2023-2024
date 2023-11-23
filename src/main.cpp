#include <iostream>
#include "../include/Book.h"
#include "../include/Date.h"
#include "../include/BookShelf.h"

using namespace std;

void tester();
int main(){
    tester();
    BookShelf bs(9);
    return 0;
}

void tester(){
    Date::Month f {Date::Month::mar};
    Date d{2020,Date::Month::mar,1};
    Book mybook("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");
    // Book mybook{"David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4"};
    // Book mybook2{"David2", "Foster Wallace", "Una cosa divertente che non farò mai più", "847-521-837-4"};
    // cout<<mybook;

    cout<<mybook;
}
