#include <iostream>
#include "../include/Book.h"
#include "../include/Date.h"
#include "../include/BookShelf.h"

using namespace std;

void tester();
int main(){
    tester();
    return 0;
}

void tester(){
    // Book mybook("David", "Foster Wallace", "Una cosa divertente che non far� mai pi�", "887-521-837-4");
    // Book mybook{"David", "Foster Wallace", "Una cosa divertente che non far� mai pi�", "887-521-837-4"};
    // Book mybook2{"David2", "Foster Wallace", "Una cosa divertente che non far� mai pi�", "847-521-837-4"};
    // cout<<mybook;

    /*Date::Month f {Date::Month::mar};
    Date d{2020,Date::Month::mar,1};
    cout<<d;*/

    BookShelf bs(9);

}
