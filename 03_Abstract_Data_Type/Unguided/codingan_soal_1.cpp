#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilai_akhir;
};

// Fungsi untuk menghitung nilai akhir
float hitung_nilai_akhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

// Fungsi untuk menambah data mahasiswa
void tambah_mahasiswa(Mahasiswa& mhs) {
    cout << "Nama       : ";
    cin.ignore();
    getline(cin, mhs.nama);
    cout << "NIM        : ";
    getline(cin, mhs.nim);
    cout << "Nilai UTS  : ";
    cin >> mhs.uts;
    cout << "Nilai UAS  : ";
    cin >> mhs.uas;
    cout << "Nilai Tugas: ";
    cin >> mhs.tugas;
    
    // Hitung nilai akhir menggunakan fungsi
    mhs.nilai_akhir = hitung_nilai_akhir(mhs.uts, mhs.uas, mhs.tugas);
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkan_mahasiswa(const Mahasiswa mhs[], int jumlah_mahasiswa) {
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        cout << "\nData Mahasiswa " << i + 1 << endl;
        cout << "Nama       : " << mhs[i].nama << endl;
        cout << "NIM        : " << mhs[i].nim << endl;
        cout << "Nilai UTS  : " << mhs[i].uts << endl;
        cout << "Nilai UAS  : " << mhs[i].uas << endl;
        cout << "Nilai Tugas: " << mhs[i].tugas << endl;
        cout << "Nilai Akhir: " << mhs[i].nilai_akhir << endl;
        cout << "--------------------------" << endl;
    }
}

int main() {
    const int MAX_MAHASISWA = 10;
    Mahasiswa mahasiswa[MAX_MAHASISWA];
    int jumlah_mahasiswa = 0;
    char lanjut;

    // Input data mahasiswa
    do {
        if (jumlah_mahasiswa < MAX_MAHASISWA) {
            cout << "\nInput data mahasiswa ke-" << jumlah_mahasiswa + 1 << endl;
            tambah_mahasiswa(mahasiswa[jumlah_mahasiswa]);
            jumlah_mahasiswa++;

            cout << "Ingin menambah data mahasiswa lagi? (y/n): ";
            cin >> lanjut;
        } else {
            cout << "Data mahasiswa sudah mencapai maksimal." << endl;
            break;
        }
    } while (lanjut == 'y' || lanjut == 'Y');

    // Tampilkan data mahasiswa
    tampilkan_mahasiswa(mahasiswa, jumlah_mahasiswa);

    return 0;
}
