#include "LibraryManagement.h"
#include <iostream>
using namespace std;

int main() {
    LibraryManagement lm;

    // Adding members
    lm.addMember("Rani", "A001");
    lm.addMember("Dito", "A002");
    lm.addMember("Vina", "A003");

    // Adding books
    lm.addBook("A001", "Pemrograman C++", "01/12/2024");
    lm.addBook("A002", "Algoritma Pemrograman", "15/12/2024");
    lm.addBook("A001", "Struktur Data", "10/12/2024");

    // Removing a member
    lm.removeMember("A002");

    // Displaying all data
    cout << "Library Member and Borrowed Books Data:\n";
    lm.displayData();

    return 0;
}
