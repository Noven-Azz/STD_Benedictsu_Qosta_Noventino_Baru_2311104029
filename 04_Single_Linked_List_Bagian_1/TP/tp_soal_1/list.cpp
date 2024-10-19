#include <iostream>
#include "list.h"
using namespace std;

// Implementasi fungsi-fungsi List akan ditambahkan di sini
void createList(List &L) {
    /** this procedure will initialize the list L */
    first(L) = NULL;
}

address allocate(infotype x) {
    address P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirst(List &L, address P) {
    /** TODO: Insert the new element pointed by P to the first of list L */
    next(P) = first(L);
    first(L) = P;
}

void printInfo(List L) {
    /** this procedure will output the info of each element in list L */
    address P = first(L);
    while (P != NULL) {
        cout << info(P) << " ";
        P = next(P);
    }
    cout << endl;
}
