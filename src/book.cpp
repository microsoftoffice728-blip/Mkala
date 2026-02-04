#include "book.h"

Book::Book(int id, const std::string &title, const std::string &author, int year, int copies)
    : id(id), title(title), author(author), year(year), copies(copies) {}

int Book::getId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
int Book::getCopies() const { return copies; }

void Book::setTitle(const std::string &title) { this->title = title; }
void Book::setAuthor(const std::string &author) { this->author = author; }
void Book::setYear(int year) { this->year = year; }
void Book::setCopies(int copies) { this->copies = copies; }

bool Book::borrowCopy() {
    if (copies > 0) {
        --copies;
        return true;
    }
    return false;
}

void Book::returnCopy() {
    ++copies;
}
