#include <iostream>

using namespace std;

int kendaraan(int kapasitas_kendaraan, int jumlah_penumpang) {
    int jumlah;
    jumlah = jumlah_penumpang / kapasitas_kendaraan;
    if (jumlah_penumpang % kapasitas_kendaraan) {
        jumlah++;
    }
    return jumlah;
}

int main(){
    int kap_kendaraan, jum_penumpang, banyak_kendaraan;
    cout << "Masukan kapasitas kendaraan : ";
    cin >> kap_kendaraan;
    cout << "Masukan jumlah penumpang : ";
    cin >> jum_penumpang;
    banyak_kendaraan = kendaraan(kap_kendaraan, jum_penumpang);
    cout << "Banyak kendaraan yang disewa" << banyak_kendaraan << endl;
    return 0;
}