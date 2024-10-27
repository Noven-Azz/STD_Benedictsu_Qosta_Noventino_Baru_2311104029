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

// Fungsi untuk mencari elemen dengan nilai tertentu
void searchElement(List L, int i) {
    Node* current = L;
    int position = 1;  // Inisialisasi posisi

    // Melakukan perulangan untuk mencari elemen
    while (current != nullptr) {
        if (current->info == i) {
            cout << "Elemen " << i << " ditemukan pada posisi ke " << position 
                 << ", alamat: " << current << endl;
            return;  // Keluar dari fungsi setelah menemukan elemen
        }
        current = current->next;  // Pindah ke node berikutnya
        position++;  // Increment posisi
    }

    // Jika elemen tidak ditemukan
    cout << "Elemen " << i << " tidak ditemukan dalam list." << endl;
}

int main() {
    List L = nullptr;  // Inisialisasi list kosong
    int input;

    // Minta pengguna memasukkan 6 elemen
    cout << "Masukkan 6 elemen integer ke dalam list:" << endl;
    for (int j = 0; j < 6; j++) {
        cout << "Elemen " << (j + 1) << ": ";
        cin >> input;
        insertFirst(L, input);  // Tambahkan elemen ke list
    }

    // Minta pengguna memasukkan nilai yang ingin dicari
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> input;

    // Panggil fungsi untuk mencari elemen
    searchElement(L, input);

    // Pembebasan memori (opsional)
    // Anda dapat menambahkan kode untuk membebaskan memori jika diperlukan

    return 0;
}
