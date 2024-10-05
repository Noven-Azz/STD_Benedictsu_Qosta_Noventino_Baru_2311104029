#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> data;
    vector<int> genap, ganjil;
    int n, num;
    
    // Input jumlah data
    cout << "Masukkan jumlah angka: ";
    cin >> n;

    // Input data dari user
    cout << "Masukkan angka-angka: ";
    for(int i = 0; i < n; i++) {
        cin >> num;
        data.push_back(num);
        if (num % 2 == 0)
            genap.push_back(num);
        else
            ganjil.push_back(num);
    }

    // Menampilkan Data Array
    cout << "Data Array  : ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    // Menampilkan Nomor Genap
    cout << "Nomor Genap : ";
    for (int i = 0; i < genap.size(); i++) {
        cout << genap[i];
        if (i != genap.size() - 1) cout << ", ";
    }
    cout << "," << endl;

    // Menampilkan Nomor Ganjil
    cout << "Nomor Ganjil: ";
    for (int i = 0; i < ganjil.size(); i++) {
        cout << ganjil[i];
        if (i != ganjil.size() - 1) cout << ", ";
    }
    cout << "," << endl;

    return 0;
}
