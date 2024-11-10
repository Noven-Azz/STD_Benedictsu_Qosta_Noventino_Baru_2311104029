#include "stack.h"
#include <iostream>
using namespace std;

// Fungsi untuk menampilkan isi stack secara terbalik (dari top ke bawah)
void printReverse(stack S) {
    while (!isEmpty(S)) {
        cout << pop(S) << " ";
    }
    cout << endl;
}

int main() {
    stack S;

    // Digit terakhir NIM MOD 4 sisa 0
    cout << "Digit terakhir NIM MOD 4 sisa 0 :" << endl;
    createStack(S);
    push(S, 'I'); push(S, 'F'); push(S, 'L'); push(S, 'A'); push(S, 'B'); push(S, 'J'); push(S, 'A'); push(S, 'Y'); push(S, 'A');
    cout << "Output:" << endl;
    printInfo(S); // Isi stack awal
    cout << endl;
    pop(S); pop(S); pop(S); pop(S); // Mengeluarkan beberapa elemen
    printReverse(S); // Isi stack setelah pop
    cout << endl;

    // Digit terakhir NIM MOD 4 sisa 1
    cout << "Digit terakhir NIM MOD 4 sisa 1 :" << endl;
    createStack(S);
    push(S, 'H'); push(S, 'A'); push(S, 'L'); push(S, 'O'); push(S, 'B'); push(S, 'A'); push(S, 'N'); push(S, 'D'); push(S, 'U'); push(S, 'N'); push(S, 'G');
    cout << "Output:" << endl;
    printInfo(S); // Isi stack awal
    cout << endl;
    pop(S); pop(S); pop(S); pop(S); pop(S); pop(S); // Mengeluarkan beberapa elemen
    printReverse(S); // Isi stack setelah pop
    cout << endl;

    // Digit terakhir NIM MOD 4 sisa 2
    cout << "Digit terakhir NIM MOD 4 sisa 2 :" << endl;
    createStack(S);
    push(S, 'P'); push(S, 'E'); push(S, 'R'); push(S, 'C'); push(S, 'A'); push(S, 'Y'); push(S, 'A'); push(S, 'D'); push(S, 'I'); push(S, 'R'); push(S, 'I');
    cout << "Output:" << endl;
    printInfo(S); // Isi stack awal
    cout << endl;
    pop(S); pop(S); pop(S); pop(S); pop(S); // Mengeluarkan beberapa elemen
    printReverse(S); // Isi stack setelah pop
    cout << endl;

    // Digit terakhir NIM MOD 4 sisa 3
    cout << "Digit terakhir NIM MOD 4 sisa 3 :" << endl;
    createStack(S);
    push(S, 'S'); push(S, 'T'); push(S, 'R'); push(S, 'U'); push(S, 'K'); push(S, 'T'); push(S, 'U'); push(S, 'R'); push(S, 'D'); push(S, 'A'); push(S, 'T'); push(S, 'A');
    cout << "Output:" << endl;
    printInfo(S); // Isi stack awal
    cout << endl;
    pop(S); pop(S); pop(S); pop(S); pop(S); pop(S); pop(S); // Mengeluarkan beberapa elemen
    printReverse(S); // Isi stack setelah pop
    cout << endl;

    return 0;
}
