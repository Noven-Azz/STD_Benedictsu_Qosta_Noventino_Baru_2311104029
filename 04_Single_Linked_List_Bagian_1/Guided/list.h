// /*file : list.h*/
// #ifndef LIST_H_INCLUDED
// #define LIST_H_INCLUDED
// #define Nil NULL
// #define info(P) (P)->info
// #define next(P) (P)->next
// #define first(L) ((L).first)
// using namespace std;
// /*deklarasi record dan struktur data list*/
// struct mahasiswa{
//  char nama[30]
//  char nim[10]
// }
// typedef mahasiswa infotype;
// typdef struct elmlist *address;
// struct elmlist {
//  infotype info;
//  address next;
// };
// struct list{
//  address first;
// };
// #endif // TEST_H_INCLUDED

#ifndef list_H
#define list_H
#include "boolean.h"
#include <stdio.h>
#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
/*deklarasi record dan struktur data list*/
typedef int infotype;
typedef struct elmlist *address;
struct elmlist{
infotype info;
address next;
};
/* definisi list : */
/* list kosong jika First(L)=Nil */
/* setiap elemen address P dapat diacu info(P) atau next(P) */
struct list {
address first;
};
/********* pengecekan apakah list kosong ***********/
boolean ListEmpty(list L);
/*mengembalikan nilai true jika list kosong*/
/********* pembuatan list kosong *********/
void CreateList(list &L);

/* I.S. sembarang
 F.S. terbentuk list kosong*/
 
/********* manajemen memori *********/
void dealokasi(address P);
/* I.S. P terdefinisi
 F.S. memori yang digunakan P dikembalikan ke sistem */
 
/********* penambahan elemen **********/
void insertFirst(list &L, address P);
/* I.S. sembarang, P sudah dialokasikan
 F.S. menempatkan elemen beralamat P pada awal list */
 
void insertAfter(list &L, address P, address Prec);
/* I.S. sembarang, P dan Prec alamt salah satu elemen list
 F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */
void insertLast(list &L, address P);
/* I.S. sembarang, P sudah dialokasikan
 F.S. menempatkan elemen beralamat P pada akhir list */
 
/********** proses semau elemen list *********/
void printInfo(list L);
/* I.S. list mungkin kosong
 F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
int nbList(list L);
/* mengembalikan jumlah elemen pada list */
#endif