#include <iostream>
#include "../include/Book.h"

using namespace std;

void tester();

int main(){
    tester();
    return 0;
}

void tester(){
    // Book mybook("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");
    Book mybook{"David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4"};
    Book mybook2{"David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4"};
    // BookShelf shelf(10);
    // shelf.pop_back();
    cout<<"Test"<<endl;
    cout<<mybook2.name()<<endl;
    cout<<mybook2.surname()<<endl;
    cout<<mybook2.title()<<endl;
    cout<<mybook2.isbn()<<endl;
}


