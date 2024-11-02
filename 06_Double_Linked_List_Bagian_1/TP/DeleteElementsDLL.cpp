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

void deleteFirst(DoublyLinkedList &L) {
    if (L.head == nullptr) {
        cout << "List kosong, tidak ada elemen yang bisa dihapus." << endl;
        return;
    }
    Node* temp = L.head;
    if (L.head == L.tail) {  // Jika hanya ada satu elemen
        L.head = nullptr;
        L.tail = nullptr;
    } else {
        L.head = L.head->next;
        L.head->prev = nullptr;
    }
    delete temp;
}

void deleteLast(DoublyLinkedList &L) {
    if (L.tail == nullptr) {
        cout << "List kosong, tidak ada elemen yang bisa dihapus." << endl;
        return;
    }
    Node* temp = L.tail;
    if (L.head == L.tail) {  // Jika hanya ada satu elemen
        L.head = nullptr;
        L.tail = nullptr;
    } else {
        L.tail = L.tail->prev;
        L.tail->next = nullptr;
    }
    delete temp;
}

void printList(DoublyLinkedList L) {
    if (L.head == nullptr) {
        cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: List kosong." << endl;
        return;
    }
    Node* current = L.head;
    cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
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

    int elemenPertama, elemenKedua, elemenKetiga;

    // Memasukkan elemen-elemen ke dalam list
    cout << "Masukkan elemen pertama = ";
    cin >> elemenPertama;
    insertLast(L, elemenPertama);

    cout << "Masukkan elemen kedua di akhir = ";
    cin >> elemenKedua;
    insertLast(L, elemenKedua);

    cout << "Masukkan elemen ketiga di akhir = ";
    cin >> elemenKetiga;
    insertLast(L, elemenKetiga);

    // Menghapus elemen pertama dan terakhir
    deleteFirst(L);
    deleteLast(L);

    // Menampilkan list setelah penghapusan
    printList(L);

    return 0;
}
