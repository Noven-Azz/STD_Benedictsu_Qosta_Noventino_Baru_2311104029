#ifndef LIBRARY_MANAGEMENT_H
#define LIBRARY_MANAGEMENT_H

#include <string>
using namespace std;

struct Book {
    string title;
    string return_date;
    Book* next;
};

struct Member {
    string name;
    string member_id;
    Book* borrowed_books;
    Member* next;
};

class LibraryManagement {
private:
    Member* head;
public:
    LibraryManagement();
    void addMember(string name, string member_id);
    void addBook(string member_id, string title, string return_date);
    void removeMember(string member_id);
    void displayData();
};

#endif
