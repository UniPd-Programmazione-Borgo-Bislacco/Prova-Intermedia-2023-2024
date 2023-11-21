#include <iostream>

void tester();

int main(){
    tester();
    return 0;
}

void tester(){
    Book mybook("David", "Foster Wallace", "Una cosa divertente che
        non farò mai più", "887-521-837-4");
    BookShelf shelf(10);
    shelf.pop_back();
    std::cout<<"Test";
}
