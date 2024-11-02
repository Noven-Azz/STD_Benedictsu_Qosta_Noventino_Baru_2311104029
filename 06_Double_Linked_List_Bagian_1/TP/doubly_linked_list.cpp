    #include <iostream>
using namespace std;

// Node class untuk Doubly Linked List
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

// DoublyLinkedList class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan elemen di akhir list
    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }

    // Fungsi untuk menampilkan elemen dari depan ke belakang
    void displayForward() {
        Node* current = head;
        cout << "Daftar elemen dari depan ke belakang: ";
        while (current) {
            cout << current->data;
            if (current->next) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    // Fungsi untuk menampilkan elemen dari belakang ke depan
    void displayBackward() {
        Node* current = head;
        if (!current) return;

        // Pergi ke node terakhir
        while (current->next) {
            current = current->next;
        }

        cout << "Daftar elemen dari belakang ke depan: ";
        while (current) {
            cout << current->data;
            if (current->prev) {
                cout << " <-> ";
            }
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    // Memasukkan 4 elemen
    cout << "Masukkan 4 elemen secara berurutan:" << endl;
    for (int i = 0; i < 4; i++) {
        int element;
        cout << "Masukkan elemen: ";
        cin >> element;
        dll.append(element);
    }

    // Menampilkan elemen dari depan ke belakang dan sebaliknya
    dll.displayForward();
    dll.displayBackward();

    return 0;
}
