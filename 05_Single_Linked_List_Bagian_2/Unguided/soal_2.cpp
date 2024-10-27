#include <iostream>
using namespace std;

// Definisi struktur Node untuk linked list
struct Node {
    int info;
    Node* next;
};

// Tipe List sebagai pointer ke Node
typedef Node* List;

// Fungsi untuk menambahkan elemen baru di awal list
void insertFirst(List& L, int info) {
    Node* newNode = new Node;  // Alokasi memori untuk node baru
    newNode->info = info;
    newNode->next = L;
    L = newNode;
}

// Prosedur untuk menampilkan elemen-elemen dalam list
void printList(List L) {
    Node* current = L;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

// Prosedur untuk mengurutkan list menggunakan Bubble Sort
void bubbleSortList(List& L) {
    if (L == nullptr || L->next == nullptr) return;  // Jika list kosong atau hanya ada satu elemen

    bool swapped;
    do {
        swapped = false;  // Set swapped ke false di awal iterasi
        Node* current = L;

        while (current != nullptr && current->next != nullptr) {
            if (current->info > current->next->info) {
                // Tukar data antara current dan current->next
                swap(current->info, current->next->info);
                swapped = true;  // Set swapped menjadi true karena terjadi pertukaran
            }
            current = current->next;  // Pindah ke node berikutnya
        }
    } while (swapped);  // Ulangi sampai tidak ada lagi pertukaran yang dilakukan
}

int main() {
    List L = nullptr;  // Inisialisasi list kosong
    int input;

    // Minta pengguna memasukkan 5 elemen
    cout << "Masukkan 5 elemen integer ke dalam list:" << endl;
    for (int j = 0; j < 5; j++) {
        cout << "Elemen " << (j + 1) << ": ";
        cin >> input;
        insertFirst(L, input);  // Tambahkan elemen ke list
    }

    cout << "List sebelum diurutkan: ";
    printList(L);  // Tampilkan list sebelum diurutkan

    // Mengurutkan list menggunakan Bubble Sort
    bubbleSortList(L);

    cout << "List setelah diurutkan: ";
    printList(L);  // Tampilkan list setelah diurutkan

    return 0;
}
