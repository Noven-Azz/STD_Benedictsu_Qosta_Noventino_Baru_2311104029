#include <iostream>
#include "singlelist.h"
using namespace std;

// Membuat list kosong
void createList(List &L) {
    L.first = NULL;
}

// Mengalokasikan memori untuk elemen baru
address alokasi(infotype x) {
    address P = new Elmlist;
    P->info = x;
    P->next = NULL;
    return P;
}

// Mengembalikan memori elemen ke sistem
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// Menambahkan elemen baru di awal list
void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

// Mencetak semua elemen di list
void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
