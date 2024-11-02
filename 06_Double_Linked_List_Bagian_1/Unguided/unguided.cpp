#include <iostream>
#include <string>
using namespace std;

struct infotype {
    string nopoli;
    string warna;
    int tahun;
};

struct ElmList {
    infotype info;
    ElmList *next;
    ElmList *prev;
};

struct List {
    ElmList *first;
    ElmList *last;
};

void createList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

ElmList* allocate(infotype x) {
    ElmList* P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void deallocate(ElmList* &P) {
    delete P;
    P = nullptr;
}

void insertLast(List &L, ElmList* P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void printInfo(List L) {
    ElmList* P = L.first;
    cout << "DATA LIST 1" << endl;
    while (P != nullptr) {
        cout << "No polisi  : " << P->info.nopoli << endl;
        cout << "Warna      : " << P->info.warna << endl;
        cout << "Tahun      : " << P->info.tahun << endl;
        cout << endl;
        P = P->next;
    }
}

ElmList* findElm(List L, string nopoli) {
    ElmList* P = L.first;
    while (P != nullptr) {
        if (P->info.nopoli == nopoli) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void deleteFirst(List &L, ElmList* &P) {
    if (L.first != nullptr) {
        P = L.first;
        if (L.first == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = L.first->next;
            L.first->prev = nullptr;
        }
        P->next = nullptr;
    }
}

void deleteLast(List &L, ElmList* &P) {
    if (L.last != nullptr) {
        P = L.last;
        if (L.first == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.last = L.last->prev;
            L.last->next = nullptr;
        }
        P->prev = nullptr;
    }
}

void deleteAfter(ElmList* Prec, ElmList* &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    }
}

int main() {
    List L;
    createList(L);

    int n;
    cout << "Masukkan jumlah data kendaraan: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        infotype x;
        cout << "Masukkan nomor polisi: ";
        cin >> x.nopoli;
        cout << "Masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> x.tahun;

        ElmList* P = allocate(x);
        insertLast(L, P);
    }

    printInfo(L);

    // Mencari elemen dengan nomor polisi tertentu
    string search_nopoli;
    cout << "Masukkan Nomor Polisi yang dicari: ";
    cin >> search_nopoli;
    ElmList* found = findElm(L, search_nopoli);
    if (found != nullptr) {
        cout << "Nomor Polisi : " << found->info.nopoli << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.tahun << endl;
    } else {
        cout << "Nomor polisi tidak ditemukan." << endl;
    }

    // Menghapus elemen dengan nomor polisi tertentu
    string delete_nopoli;
    cout << "Masukkan Nomor Polisi yang akan dihapus: ";
    cin >> delete_nopoli;
    found = findElm(L, delete_nopoli);
    if (found != nullptr) {
        deleteFirst(L, found); // Contoh penggunaan deleteFirst
        deallocate(found);
        cout << "Data dengan nomor polisi " << delete_nopoli << " berhasil dihapus." << endl;
    }

    printInfo(L);

    return 0;
}
