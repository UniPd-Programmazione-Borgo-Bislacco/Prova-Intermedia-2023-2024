#include <iostream>
#include "../include/Book.h"
<<<<<<< Updated upstream
=======
#include "../include/Date.h"
#include "../include/BookShelf.h"
#include <string>
>>>>>>> Stashed changes

using namespace std;

void tester();

int main(){
    tester();
    return 0;
}

void tester(){
<<<<<<< Updated upstream
    // Book mybook("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");
    Book mybook{"David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4"};
    Book mybook2{"David2", "Foster Wallace", "Una cosa divertente che non farò mai più", "847-521-837-4"};
    // BookShelf shelf(10);
    // shelf.pop_back();
    cout<<"Test Cout"<<endl;
    cout << mybook2 <<endl;

    cout<<"Test =="<<endl;
    // if(mybook==mybook2) cout<<"Uguali ISBN"<<endl;

=======
    Date::Month f {Date::Month::mar};
    Date d{2020,Date::Month::mar,1};
    Book mybook("David", "Foster Wallace", "Una cosa divertente che non far� mai pi�", "887-521-837-4");
    // Book mybook{"David", "Foster Wallace", "Una cosa divertente che non far� mai pi�", "887-521-837-4"};
    // Book mybook2{"David2", "Foster Wallace", "Una cosa divertente che non far� mai pi�", "847-521-837-4"};
    cout<<mybook;
    
>>>>>>> Stashed changes
}
