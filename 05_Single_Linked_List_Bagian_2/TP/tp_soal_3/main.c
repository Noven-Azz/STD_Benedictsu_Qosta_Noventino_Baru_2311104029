#include <stdio.h>
#include <stdlib.h>

// Definisi struktur Node untuk linked list
typedef struct Node {
    int info;
    struct Node* next;
} Node;

typedef Node* List;
typedef Node* address;

// Fungsi untuk mencari elemen dengan nilai tertentu
address findElm(List L, int x) {
    address current = L;
    while (current != NULL) {
        if (current->info == x) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Fungsi untuk menambahkan elemen baru di awal list
void insertFirst(List* L, int info) {
    address newNode = (address)malloc(sizeof(Node));
    newNode->info = info;
    newNode->next = *L;
    *L = newNode;
}

// Fungsi untuk menghitung total info seluruh elemen dalam list
int sumInfo(List L) {
    int sum = 0;
    address current = L;
    while (current != NULL) {
        sum += current->info;
        current = current->next;
    }
    return sum;
}

int main() {
    List L = NULL;  // Inisialisasi list kosong

    // Menambahkan elemen ke dalam list
    insertFirst(&L, 2);
    insertFirst(&L, 0);
    insertFirst(&L, 8);
    insertFirst(&L, 12);
    insertFirst(&L, 9);

    // Menghitung total info seluruh elemen
    int total = sumInfo(L);
    printf("Total info dari kelima elemen adalah %d\n", total);

    return 0;
}
