#include <iostream>
#include <string>
using namespace std;

// Array untuk angka 0 sampai 19 dalam bentuk tulisan
string angka[] = {
    "nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan",
    "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"
};

// Array untuk puluhan dalam bentuk tulisan
string puluhan[] = {
    "", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"
};

// Fungsi untuk mengubah angka menjadi tulisan
string angka_ke_tulisan(int n) {
    if (n < 20) {
        return angka[n]; // untuk angka 0-19
    } else if (n == 100) {
        return "seratus"; // kasus khusus untuk 100
    } else {
        int puluh = n / 10; // angka puluhan
        int satuan = n % 10; // angka satuan
        if (satuan == 0) {
            return puluhan[puluh]; // jika tidak ada satuan
        } else {
            return puluhan[puluh] + " " + angka[satuan]; // jika ada satuan
        }
    }
}

int main() {
    int angka_input;
    cout << "Masukkan angka (0-100): ";
    cin >> angka_input;

    if (angka_input < 0 || angka_input > 100) {
        cout << "Angka harus di antara 0 dan 100!" << endl;
    } else {
        cout << angka_input << ": " << angka_ke_tulisan(angka_input) << endl;
    }

    return 0;
}
