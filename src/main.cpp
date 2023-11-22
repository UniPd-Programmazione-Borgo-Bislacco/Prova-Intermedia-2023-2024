#include <iostream>
#include "../include/Book.h"
#include "../include/Date.h"

using namespace std;

void tester();
int main(){
    tester();
    return 0;
}

void tester(){
    // Book mybook("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");
   // Book mybook{"David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4"};
    //Book mybook2{"David2", "Foster Wallace", "Una cosa divertente che non farò mai più", "847-521-837-4"};


    Date::Month f {Date::Month::mar};
    // enum Date::Month j;
    // j= Date::Month::jan;
    Date d{2020,f,2};
    cout<<d<<endl;

}
