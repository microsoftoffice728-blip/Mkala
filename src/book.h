#pragma once
#include <string>

class Book {
public:
    Book() = default;
    Book(int id, const std::string &title, const std::string &author, int year, int copies);

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    int getCopies() const;

    void setTitle(const std::string &title);
    void setAuthor(const std::string &author);
    void setYear(int year);
    void setCopies(int copies);

    bool borrowCopy();
    void returnCopy();

private:
    int id{0};
    std::string title;
    std::string author;
    int year{0};
    int copies{0};
};
