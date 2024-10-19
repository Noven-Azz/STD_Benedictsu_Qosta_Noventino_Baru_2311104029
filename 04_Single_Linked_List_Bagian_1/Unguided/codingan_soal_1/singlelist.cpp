#include "singlelist.h"
#include <iostream>
using namespace std;

// Membuat list kosong
void createList(List &L) {
    L.First = NULL;
}

// Alokasi memori untuk elemen baru
address alokasi(infotype x) {
    address P = new ElmList;
    if (P != NULL) {
        P->info = x;
        P->next = NULL;
    }
    return P;
}

// Dealokasi memori elemen
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// Menyisipkan elemen di awal list
void insertFirst(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
    } else {
        P->next = L.First;
        L.First = P;
    }
}

// Mencetak elemen dari list
void printInfo(List L) {
    address P = L.First;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
