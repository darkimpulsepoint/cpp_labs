#pragma once
#include <gtest/gtest.h>

using namespace std;

enum class BindingType: int{
    HARD = 0,
    SOFT = 1,
    EBOOK = 2,
};

class Book {

private:
    string title;
    string authors;
    string publisher;
    int year;
    BindingType type;
    unsigned int pages;
    double cost;

public:
    void setTitle(string name);
    void addAuthor(string author);
    void removeAuthor(string author);
    void setPublisher(string pub);
    void setYear(int year);
    void setPages(unsigned int pages);
    void setCost(double cost);
    void setBindingType(BindingType type);

    Book(const std::string& title, const std::string& authors, const std::string& publisher,
         int year, int pages, double price, BindingType bindingType);

    std::string toString() const;

    string getName() const;
    string getAuthors() const;
    string getPublisher() const;
    int getYear() const;
    unsigned int getPages() const;
    double getCost() const;

};