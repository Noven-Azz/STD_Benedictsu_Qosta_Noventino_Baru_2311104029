#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    // Meminta ukuran dari user
    cout << "Masukkan ukuran dimensi pertama (x): ";
    cin >> x;
    cout << "Masukkan ukuran dimensi kedua (y): ";
    cin >> y;
    cout << "Masukkan ukuran dimensi ketiga (z): ";
    cin >> z;

    // Mendeklarasikan array 3 dimensi dengan ukuran yang diinputkan user
    int array[x][y][z];

    // Input elemen array dari user
    cout << "Masukkan elemen array 3 dimensi:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Elemen [" << i << "][" << j << "][" << k << "]: ";
                cin >> array[i][j][k];
            }
        }
    }

    // Menampilkan isi array 3 dimensi
    cout << "Isi array 3 dimensi adalah:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Elemen [" << i << "][" << j << "][" << k << "] = " << array[i][j][k] << endl;
            }
        }
    }

    return 0;
}
