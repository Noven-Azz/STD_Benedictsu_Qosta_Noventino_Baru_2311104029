#ifndef SINGLELIST_H
#define SINGLELIST_H

typedef int infotype;
typedef struct Elmlist *address;

struct Elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

// Prosedur dan Fungsi
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
