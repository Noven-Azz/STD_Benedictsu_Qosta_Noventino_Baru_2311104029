#include <iostream>
#include "stack.h"

using namespace std;

void createStack(Stack &S) {
    S.top = -1;  // Menginisialisasi stack sebagai kosong
}

void push(Stack &S, infotype x) {
    if (S.top < MAX_SIZE - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack overflow" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack underflow" << endl;
        return -1;  // Mengembalikan -1 sebagai tanda error
    }
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack tempStack;
    createStack(tempStack);

    while (S.top >= 0) {
        push(tempStack, pop(S));
    }

    while (tempStack.top >= 0) {
        push(S, pop(tempStack));
    }
}

void pushAscending(Stack &S, infotype x) {
    // Buat stack sementara untuk menyimpan elemen yang lebih besar dari x
    Stack tempStack;
    createStack(tempStack);

    // Pindahkan elemen yang lebih besar dari x ke tempStack
    while (S.top >= 0 && S.info[S.top] > x) {
        push(tempStack, pop(S));
    }

    // Tambahkan x ke stack S
    push(S, x);

    // Kembalikan elemen dari tempStack ke S
    while (tempStack.top >= 0) {
        push(S, pop(tempStack));
    }
}

void getInputStream(Stack &S) {
    char input;
    cout << "Masukkan angka-angka secara berurutan, akhiri dengan Enter: ";

    // Menggunakan cin.get() untuk membaca satu karakter setiap kali
    while (cin.get(input) && input != '\n') {
        // Memastikan karakter yang dibaca adalah digit
        if (isdigit(input)) {
            int num = input - '0';  // Konversi karakter ke integer
            push(S, num);  // Masukkan ke stack
        }
    }
}

