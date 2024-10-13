#include <iostream>

using namespace std;

// Prosedur untuk menampilkan isi array 2D berukuran 3x3
void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Prosedur untuk menukarkan isi dua array 2D pada posisi tertentu
void tukarIsiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

// Prosedur untuk menukarkan isi dari variabel yang ditunjuk oleh dua pointer
void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    // Deklarasi dua array 2D berukuran 3x3
    int array1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int array2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // Dua pointer integer
    int a = 10;
    int b = 20;
    int *p1 = &a;
    int *p2 = &b;

    // Menampilkan isi array sebelum pertukaran
    cout << "Isi Array 1 sebelum pertukaran:" << endl;
    tampilArray(array1);
    cout << "Isi Array 2 sebelum pertukaran:" << endl;
    tampilArray(array2);

    // Menukarkan isi array pada posisi tertentu (misal posisi [1][1])
    tukarIsiArray(array1, array2, 1, 1);

    // Menampilkan isi array setelah pertukaran
    cout << "\nIsi Array 1 setelah pertukaran di posisi [1][1]:" << endl;
    tampilArray(array1);
    cout << "Isi Array 2 setelah pertukaran di posisi [1][1]:" << endl;
    tampilArray(array2);

    // Menampilkan nilai yang ditunjuk oleh pointer sebelum pertukaran
    cout << "\nNilai yang ditunjuk pointer sebelum pertukaran:" << endl;
    cout << "p1 menunjuk nilai: " << *p1 << endl;
    cout << "p2 menunjuk nilai: " << *p2 << endl;

    // Menukarkan nilai yang ditunjuk oleh kedua pointer
    tukarPointer(p1, p2);

    // Menampilkan nilai yang ditunjuk oleh pointer setelah pertukaran
    cout << "\nNilai yang ditunjuk pointer setelah pertukaran:" << endl;
    cout << "p1 menunjuk nilai: " << *p1 << endl;
    cout << "p2 menunjuk nilai: " << *p2 << endl;

    return 0;
}
