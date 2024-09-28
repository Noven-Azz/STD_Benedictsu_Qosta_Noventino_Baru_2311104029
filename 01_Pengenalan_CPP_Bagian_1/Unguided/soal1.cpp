#include <iostream>
using namespace std;

int main() {
    // Mendeklarasikan variabel
    float bilanganPertama, bilanganKedua;

    // Menerima input dari pengguna
    cout << "Masukkan bilangan pertama: ";
    cin >> bilanganPertama;
    
    cout << "Masukkan bilangan kedua: ";
    cin >> bilanganKedua;

    // Melakukan operasi
    float penjumlahan = bilanganPertama + bilanganKedua;
    float pengurangan = bilanganPertama - bilanganKedua;
    float perkalian = bilanganPertama * bilanganKedua;
    float pembagian;

    // Memeriksa apakah bilangan kedua adalah nol untuk pembagian
    if (bilanganKedua != 0) {
        pembagian = bilanganPertama / bilanganKedua;
        cout << "Hasil Pembagian: " << pembagian << endl;
    } else {
        cout << "Pembagian dengan nol tidak diperbolehkan." << endl;
    }

    // Menampilkan hasil
    cout << "Hasil Penjumlahan: " << penjumlahan << endl;
    cout << "Hasil Pengurangan: " << pengurangan << endl;
    cout << "Hasil Perkalian: " << perkalian << endl;

    return 0;
}
