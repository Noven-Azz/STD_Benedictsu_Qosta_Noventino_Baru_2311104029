#include <iostream>
using namespace std;

// Definisi struktur node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node();  // Alokasi memori untuk node baru
    newNode->data = value;
    newNode->next = nullptr;  // Inisialisasi next sebagai null
    return newNode;
}

// Fungsi untuk menambah node di depan
void insertAtFront(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;  // Set next dari node baru ke head
    head = newNode;  // Update head ke node baru
}

// Fungsi untuk menambah node di belakang
void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {  // Jika linked list kosong
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {  // Menyusuri sampai node terakhir
            temp = temp->next;
        }
        temp->next = newNode;  // Hubungkan node terakhir dengan node baru
    }
}

// Fungsi untuk mencetak seluruh isi linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;  // Inisialisasi linked list sebagai kosong

    // Tambah node di depan (nilai: 10)
    insertAtFront(head, 10);
    // Tambah node di belakang (nilai: 20)
    insertAtEnd(head, 20);
    // Tambah node di depan (nilai: 5)
    insertAtFront(head, 5);

    // Cetak linked list
    cout << "Isi linked list: ";
    printList(head);

    return 0;
}
