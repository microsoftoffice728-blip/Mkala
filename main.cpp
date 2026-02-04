#include <iostream>
#include "../include/library.h"
#include "../include/user.h"
#include "../src/book.h"

int main() {
    Library lib;

    Book b1(1, "1984", "George Orwell", 1949, 3);
    Book b2(2, "Brave New World", "Aldous Huxley", 1932, 2);

    lib.addBook(b1);
    lib.addBook(b2);

    auto user = std::make_shared<User>(1, "Alice");
    // can't access private users vector directly; temporarily using library internals for demo
    // ... in real code we'd have addUser method

    std::cout << "Library initialized.\n";
    return 0;
}
