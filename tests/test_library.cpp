#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../include/library.h"
#include "../include/user.h"
#include "../src/book.h"

TEST_CASE("Book borrow and return") {
    Book b(1, "Test", "Author", 2020, 1);
    REQUIRE(b.getCopies() == 1);
    REQUIRE(b.borrowCopy() == true);
    REQUIRE(b.getCopies() == 0);
    b.returnCopy();
    REQUIRE(b.getCopies() == 1);
}

TEST_CASE("User borrow and return") {
    User u(1, "Bob");
    REQUIRE(u.borrowBook(1) == true);
    REQUIRE(u.borrowBook(1) == false); // duplicate
    REQUIRE(u.returnBook(1) == true);
    REQUIRE(u.returnBook(1) == false);
}

// More tests for Library would require modifying Library to add users
