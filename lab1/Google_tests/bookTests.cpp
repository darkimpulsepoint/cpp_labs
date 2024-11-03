#include <gtest/gtest.h>
#include "BookLibrary.h"

class BookLibraryTest : public ::testing::Test {
protected:
    BookLibrary library;

    void SetUp() override {
        library.addBook(Book("1984", "George Orwell", "Secker & Warburg", 1949, 328, 15.99, BindingType::HARD));
        library.addBook(Book("Animal Farm", "George Orwell", "Secker & Warburg", 1945, 112, 9.99, BindingType::SOFT));
        library.addBook(Book("Brave New World", "Aldous Huxley", "Chatto & Windus", 1932, 311, 14.99, BindingType::HARD));
        library.addBook(Book("Fahrenheit 451", "Ray Bradbury", "Ballantine Books", 1953, 158, 12.99, BindingType::EBOOK));
    }
};

TEST_F(BookLibraryTest, TestBooksByAuthor) {
    auto orwellBooks = library.booksByAuthor("George Orwell");
    ASSERT_EQ(orwellBooks.size(), 2);
    EXPECT_EQ(orwellBooks[0].getName(), "1984");
    EXPECT_EQ(orwellBooks[1].getName(), "Animal Farm");
}

TEST_F(BookLibraryTest, TestBooksByPublisher) {
    auto seckerBooks = library.booksByPublisher("Secker & Warburg");
    ASSERT_EQ(seckerBooks.size(), 2);
    EXPECT_EQ(seckerBooks[0].getName(), "1984");
    EXPECT_EQ(seckerBooks[1].getName(), "Animal Farm");
}


TEST_F(BookLibraryTest, TestBooksByPublisher2) {
    auto seckerBooks = library.booksByPublisher("Chatto & Windus");
    ASSERT_EQ(seckerBooks.size(), 1);
    EXPECT_EQ(seckerBooks[0].getName(), "Brave New World");
}

TEST_F(BookLibraryTest, TestBooksByNotExistingPublisher) {
    auto nasBooks = library.booksByPublisher("NAS");
    EXPECT_TRUE(nasBooks.empty());
}

TEST_F(BookLibraryTest, TestBooksAfterYear) {
    auto recentBooks = library.booksAfterYear(1945);
    ASSERT_EQ(recentBooks.size(), 2);
    EXPECT_EQ(recentBooks[0].getName(), "1984");
    EXPECT_EQ(recentBooks[1].getName(), "Fahrenheit 451");
}

TEST_F(BookLibraryTest, TestBooksAfterYear2) {
    auto recentBooks = library.booksAfterYear(1950);
    ASSERT_EQ(recentBooks.size(), 1);
    EXPECT_EQ(recentBooks[0].getName(), "Fahrenheit 451");
}

TEST_F(BookLibraryTest, TestBooksAfterFutureYear) {
    auto recentBooks = library.booksAfterYear(2052);
    EXPECT_TRUE(recentBooks.empty());
}

TEST_F(BookLibraryTest, TestEmptyAuthorQuery) {
    auto emptyBooks = library.booksByAuthor("Unknown Author");
    EXPECT_TRUE(emptyBooks.empty());
}

TEST(BookTest, AddAuthor) {
    Book book("The Great Gatsby", "F. Scott Fitzgerald", "Scribner", 1925, 218, 10.99, BindingType::HARD);
    book.addAuthor("New Author");

    EXPECT_EQ(book.getAuthors(), "F. Scott Fitzgerald, New Author");
}

TEST(BookTest, RemoveAuthor) {
    Book book("1984", "George Orwell", "Secker & Warburg", 1949, 328, 15.99, BindingType::HARD);
    book.addAuthor("Another Author");
    book.removeAuthor("Another Author");

    EXPECT_EQ(book.getAuthors(), "George Orwell");
}

TEST(BookTest, RemoveExistingAuthor) {
    Book book("Animal Farm", "George Orwell", "Secker & Warburg", 1945, 112, 9.99, BindingType::SOFT);
    book.addAuthor("Another Author");
    book.removeAuthor("George Orwell");

    EXPECT_EQ(book.getAuthors(), "Another Author");
}

TEST(BookTest, RemoveNonexistentAuthor) {
    Book book("Fahrenheit 451", "Ray Bradbury", "Ballantine Books", 1953, 158, 12.99, BindingType::EBOOK);
    book.removeAuthor("Nonexistent Author");

    EXPECT_EQ(book.getAuthors(), "Ray Bradbury");
}

TEST(BookTest, AddMultipleAuthors) {
    Book book("Brave New World", "Aldous Huxley", "Chatto & Windus", 1932, 311, 14.99, BindingType::HARD);
    book.addAuthor("Author 1");
    book.addAuthor("Author 2");

    EXPECT_EQ(book.getAuthors(), "Aldous Huxley, Author 1, Author 2");
}

int main() {
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
}