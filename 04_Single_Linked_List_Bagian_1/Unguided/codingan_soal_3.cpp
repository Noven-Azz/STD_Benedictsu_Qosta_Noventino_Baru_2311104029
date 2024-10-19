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

// Fungsi untuk menghapus node dengan nilai tertentu
void deleteNode(Node*& head, int value) {
    // Jika linked list kosong
    if (head == nullptr) {
        cout << "Linked list kosong." << endl;
        return;
    }
    
    // Jika node pertama yang harus dihapus
    if (head->data == value) {
        Node* temp = head;
        head = head->next;  // Update head ke node berikutnya
        delete temp;  // Hapus node lama
        cout << "Node dengan nilai " << value << " telah dihapus." << endl;
        return;
    }

    // Menyusuri linked list untuk mencari node yang akan dihapus
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    // Jika node ditemukan
    if (temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;  // Menghubungkan node sebelumnya dengan node setelahnya
        delete nodeToDelete;  // Hapus node
        cout << "Node dengan nilai " << value << " telah dihapus." << endl;
    } else {
        cout << "Node dengan nilai " << value << " tidak ditemukan." << endl;
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

    // Cetak linked list sebelum penghapusan
    cout << "Linked list sebelum penghapusan: ";
    printList(head);

    // Hapus node dengan nilai tertentu (nilai: 10)
    deleteNode(head, 10);

    // Cetak linked list setelah penghapusan
    cout << "Linked list setelah penghapusan: ";
    printList(head);

    return 0;
}
