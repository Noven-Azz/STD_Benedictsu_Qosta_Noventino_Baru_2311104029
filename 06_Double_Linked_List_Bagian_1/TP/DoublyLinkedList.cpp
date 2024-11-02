#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;
};

void createList(DoublyLinkedList &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

Node* allocate(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertFirst(DoublyLinkedList &L, int data) {
    Node* newNode = allocate(data);
    if (L.head == nullptr) {  // Jika list kosong
        L.head = newNode;
        L.tail = newNode;
    } else {
        newNode->next = L.head;
        L.head->prev = newNode;
        L.head = newNode;
    }
}

void insertLast(DoublyLinkedList &L, int data) {
    Node* newNode = allocate(data);
    if (L.tail == nullptr) {  // Jika list kosong
        L.head = newNode;
        L.tail = newNode;
    } else {
        newNode->prev = L.tail;
        L.tail->next = newNode;
        L.tail = newNode;
    }
}

void printList(DoublyLinkedList L) {
    Node* current = L.head;
    cout << "DAFTAR ANGGOTA LIST: ";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    DoublyLinkedList L;
    createList(L);

    int elemenPertama, elemenDiAwal, elemenDiAkhir;

    // Memasukkan elemen pertama
    cout << "Masukkan elemen pertama = ";
    cin >> elemenPertama;
    insertLast(L, elemenPertama);

    // Memasukkan elemen di awal
    cout << "Masukkan elemen kedua di awal = ";
    cin >> elemenDiAwal;
    insertFirst(L, elemenDiAwal);

    // Memasukkan elemen di akhir
    cout << "Masukkan elemen ketiga di akhir = ";
    cin >> elemenDiAkhir;
    insertLast(L, elemenDiAkhir);

    // Menampilkan list dari depan ke belakang
    printList(L);

    return 0;
}
