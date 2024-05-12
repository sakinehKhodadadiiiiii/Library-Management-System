#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

public:
    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i), available(true) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getISBN() const { return isbn; }
    bool isAvailable() const { return available; }

    void borrowBook() { available = false; }
    void returnBook() { available = true; }
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& b) { books.push_back(b); }
    
    Book* findBook(const std::string& title) {
        auto it = std::find_if(books.begin(), books.end(), [&](const Book& b) { return b.getTitle() == title; });
        if (it != books.end()) {
            return &(*it);
        }
        return nullptr;
    }

    void displayBooks() const {
        std::cout << "Available Books:\n";
        for (const auto& book : books) {
            if (book.isAvailable()) {
                std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << "\n";
            }
        }
    }
};

int main() {
    Library library;

    // Add some books to the library
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", "9780061120084"));
    library.addBook(Book("1984", "George Orwell", "9780451524935"));

    // Display available books
    library.displayBooks();

    // Search for a book and borrow it
    Book* book = library.findBook("1984");
    if (book) {
        std::cout << "Found book: " << book->getTitle() << "\n";
        book->borrowBook();
    } else {
        std::cout << "Book not found\n";
    }

    // Display available books after borrowing
    library.displayBooks();

    return 0;
}
