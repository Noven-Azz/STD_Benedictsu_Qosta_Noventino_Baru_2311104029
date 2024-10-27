#include <iostream>
using namespace std;

// Definisi struktur Node untuk linked list
struct Node {
    int info;
    Node* next;
};

// Tipe List sebagai pointer ke Node
typedef Node* List;

// Fungsi untuk menambahkan elemen baru secara terurut
void insertSorted(List& L, Node* P) {
    Node* Q = L;       // Pointer untuk traversing list
    Node* Prev = nullptr; // Pointer untuk elemen sebelumnya
    bool found = false; // Indikator apakah posisi sudah ditemukan

    // Melakukan perulangan sampai posisi ditemukan atau mencapai akhir list
    while (Q != nullptr && !found) {
        if (Q->info < P->info) {
            // Jika info dari node Q lebih kecil dari P, perbarui Prev dan Q
            Prev = Q;
            Q = Q->next;
        } else {
            // Jika tidak, set found ke true
            found = true;
        }
    }

    // Jika Q adalah elemen head (list kosong atau P harus jadi elemen pertama)
    if (Prev == nullptr) {
        P->next = L; // P akan menjadi head baru
        L = P;
    } 
    // Jika Q adalah nullptr (P harus jadi elemen terakhir)
    else if (Q == nullptr) {
        Prev->next = P; // Menambahkan P di akhir list
        P->next = nullptr; // Menunjuk ke null
    } 
    // Jika P harus ditambahkan di tengah
    else {
        Prev->next = P; // Menyambungkan Prev ke P
        P->next = Q;    // Menyambungkan P ke Q
    }
}

// Fungsi untuk menampilkan elemen-elemen dalam list
void printList(List L) {
    Node* current = L;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

// Fungsi untuk menambahkan elemen baru di awal list
Node* createNode(int info) {
    Node* newNode = new Node;  // Alokasi memori untuk node baru
    newNode->info = info;
    newNode->next = nullptr;
    return newNode;
}

int main() {
    List L = nullptr; // Inisialisasi list kosong
    int input;

    // Minta pengguna memasukkan 4 elemen
    cout << "Masukkan 4 elemen integer ke dalam list (harus terurut):" << endl;
    for (int j = 0; j < 4; j++) {
        cout << "Elemen " << (j + 1) << ": ";
        cin >> input;
        // Hanya mengizinkan input terurut
        if (L == nullptr || (L != nullptr && input >= L->info)) {
            Node* newNode = createNode(input);
            insertSorted(L, newNode);
        } else {
            cout << "Input harus terurut. Silakan coba lagi." << endl;
            j--; // Mengurangi j agar pengguna bisa menginput ulang
        }
    }

    // Tampilkan list setelah elemen dimasukkan
    cout << "List sebelum menambahkan elemen baru: ";
    printList(L);

    // Minta pengguna memasukkan elemen tambahan
    cout << "Masukkan elemen tambahan untuk dimasukkan ke list: ";
    cin >> input;
    Node* newNode = createNode(input);
    insertSorted(L, newNode); // Menambahkan elemen baru ke list

    // Tampilkan list setelah elemen baru dimasukkan
    cout << "List setelah menambahkan elemen baru: ";
    printList(L);

    return 0;
}
