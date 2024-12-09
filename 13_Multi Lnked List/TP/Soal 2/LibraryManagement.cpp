#include "LibraryManagement.h"
#include <iostream>
using namespace std;

LibraryManagement::LibraryManagement() {
    head = nullptr;
}

void LibraryManagement::addMember(string name, string member_id) {
    Member* newMember = new Member();
    newMember->name = name;
    newMember->member_id = member_id;
    newMember->borrowed_books = nullptr;
    newMember->next = head;
    head = newMember;
}

void LibraryManagement::addBook(string member_id, string title, string return_date) {
    Member* current = head;
    while (current != nullptr) {
        if (current->member_id == member_id) {
            Book* newBook = new Book();
            newBook->title = title;
            newBook->return_date = return_date;
            newBook->next = current->borrowed_books;
            current->borrowed_books = newBook;
            return;
        }
        current = current->next;
    }
    cout << "Member with ID " << member_id << " not found.\n";
}

void LibraryManagement::removeMember(string member_id) {
    Member* prev = nullptr;
    Member* current = head;

    while (current != nullptr) {
        if (current->member_id == member_id) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            cout << "Member " << member_id << " removed.\n";
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Member with ID " << member_id << " not found.\n";
}

void LibraryManagement::displayData() {
    Member* current = head;
    while (current != nullptr) {
        cout << "Member: " << current->name << " (ID: " << current->member_id << ")\n";
        Book* book = current->borrowed_books;
        while (book != nullptr) {
            cout << "  - Book: " << book->title << ", Return Date: " << book->return_date << "\n";
            book = book->next;
        }
        current = current->next;
    }
}
