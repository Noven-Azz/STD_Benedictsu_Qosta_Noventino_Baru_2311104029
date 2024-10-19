#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List L;
    createList(L);

    address P;

    // Insert 3 elements with 3-digit NIM
    P = allocate(111);
    insertFirst(L, P);

    P = allocate(123);
    insertFirst(L, P);

    P = allocate(147);
    insertFirst(L, P);

    // Print the list
    printInfo(L);

    return 0;
}
