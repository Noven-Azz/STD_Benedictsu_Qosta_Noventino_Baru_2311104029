#include <iostream>

using namespace std;

// Struktur untuk Node linked list
struct Node {
    int data;
    Node* next;
};

// Kelas LinkedList
class LinkedList {
private:
    Node* head;

public:
    // Konstruktor
    LinkedList() : head(nullptr) {}

    // Menambah node di depan
    void addFront(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Menambah node di belakang
    void addBack(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Mencari node dengan nilai tertentu
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true; // Nilai ditemukan
            }
            temp = temp->next;
        }
        return false; // Nilai tidak ditemukan
    }

    // Menghitung panjang linked list
    int length() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Destructor untuk membersihkan memori
    ~LinkedList() {
        Node* current = head;
        Node* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;

    // Menambah node
    list.addFront(10);
    list.addBack(20);
    list.addFront(5);

    // Mencari node
    int searchValue = 20;
    if (list.search(searchValue)) {
        cout << "Node dengan nilai " << searchValue << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << searchValue << " tidak ditemukan." << endl;
    }

    // Menghitung panjang linked list
    cout << "Panjang linked list: " << list.length() << endl;

    return 0;
}
