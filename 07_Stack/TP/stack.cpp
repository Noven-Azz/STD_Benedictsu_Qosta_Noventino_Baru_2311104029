#include <iostream>
using namespace std;

const int MAX_SIZE = 15; // Ukuran maksimum stack

typedef char infotype;

struct stack {
    infotype info[MAX_SIZE];
    int top;
};

// Membuat stack kosong
void createStack(stack &S) {
    S.top = -1;
}

// Mengecek apakah stack kosong
bool isEmpty(stack S) {
    return S.top == -1;
}

// Mengecek apakah stack penuh
bool isFull(stack S) {
    return S.top == MAX_SIZE - 1;
}

// Menambahkan elemen ke dalam stack
void push(stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh, tidak dapat push." << endl;
    }
}

// Mengeluarkan elemen dari stack
infotype pop(stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong, tidak dapat pop." << endl;
        return '\0'; // Mengembalikan karakter kosong jika stack kosong
    }
}

// Menampilkan semua elemen dalam stack
void printInfo(stack S) {
    if (!isEmpty(S)) {
        for (int i = 0; i <= S.top; i++) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Stack kosong." << endl;
    }
}
