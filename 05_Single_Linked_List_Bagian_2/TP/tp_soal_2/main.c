#include <stdio.h>
#include <stdlib.h>

// Definisi struktur Node untuk linked list
typedef struct Node {
    int info;
    struct Node* next;
} Node;

typedef Node* List;      // Alias untuk pointer ke Node
typedef Node* address;   // Alias untuk alamat Node

// Fungsi untuk mencari elemen dengan info tertentu
address findElm(List L, int x) {
    address current = L;
    while (current != NULL) {
        if (current->info == x) {
            return current;  // Elemen ditemukan
        }
        current = current->next;
    }
    return NULL;  // Jika tidak ditemukan
}

// Fungsi untuk menambahkan elemen baru di awal list
void insertFirst(List* L, int info) {
    address newNode = (address)malloc(sizeof(Node));
    newNode->info = info;
    newNode->next = *L;
    *L = newNode;
}

int main() {
    List L = NULL;  // Inisialisasi list kosong

    // Tambahkan elemen ke dalam list
    insertFirst(&L, 2);
    insertFirst(&L, 0);
    insertFirst(&L, 8);
    insertFirst(&L, 12);
    insertFirst(&L, 9);

    // Mencari elemen dengan info 8
    int target = 8;
    address result = findElm(L, target);

    if (result != NULL) {
        printf("%d ditemukan dalam list\n", target);
    } else {
        printf("%d tidak ditemukan dalam list\n", target);
    }

    return 0;
}
