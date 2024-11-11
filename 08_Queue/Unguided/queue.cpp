#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueueAntrian(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            back = nullptr;
        }
    }
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

int countQueue() {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void viewQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
        return;
    }

    Node* temp = front;
    cout << "Data antrian teller:" << endl;
    int position = 1;
    while (temp != nullptr) {
        cout << position++ << ". Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
        temp = temp->next;
    }
}

void enqueuePriority(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty() || nim < front->nim) {
        newNode->next = front;
        front = newNode;
        if (back == nullptr) {
            back = newNode;
        }
    } else {
        Node* temp = front;
        while (temp->next != nullptr && temp->next->nim < nim) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr) {
            back = newNode;
        }
    }
}

int main() {
    int choice;
    string nama, nim;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Tambah Antrian dengan Prioritas NIM\n";
        cout << "3. Hapus Antrian\n";
        cout << "4. Lihat Antrian\n";
        cout << "5. Hapus Semua Antrian\n";
        cout << "6. Hitung Antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                enqueueAntrian(nama, nim);
                break;
            case 2:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                enqueuePriority(nama, nim);
                break;
            case 3:
                dequeueAntrian();
                break;
            case 4:
                viewQueue();
                break;
            case 5:
                clearQueue();
                break;
            case 6:
                cout << "Jumlah antrian = " << countQueue() << endl;
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 0);

    clearQueue(); // Membersihkan semua node sebelum keluar
    return 0;
}
