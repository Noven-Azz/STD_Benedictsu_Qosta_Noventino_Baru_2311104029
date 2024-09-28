#include <iostream>
using namespace std;

int main() {
    int n;

    // Meminta input dari user
    cout << "Masukkan angka: ";
    cin >> n;

    // Loop untuk setiap baris
    for (int i = n; i >= 1; i--) {
        // Menampilkan bagian pertama (angka menurun)
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // Menampilkan simbol *
        cout << "* ";

        // Menampilkan bagian kedua (angka menaik)
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        // Pindah ke baris berikutnya
        cout << endl;
    }

    return 0;
}
