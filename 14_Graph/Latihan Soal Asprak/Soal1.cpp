#include <iostream>
#include <vector>
#include <iomanip> // Untuk format output tabel

using namespace std;

int main() {
    int n;

    // Meminta jumlah simpul dari pengguna
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> n;

    vector<string> nodes(n);

    // Meminta nama simpul
    for (int i = 0; i < n; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    // Membuat matriks bobot dengan ukuran n x n
    vector<vector<int>> weights(n, vector<int>(n, 0));

    cout << "\nSilakan masukkan bobot antar simpul\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) { // Jika bukan simpul ke diri sendiri
                cout << nodes[i] << " --> " << nodes[j] << " = ";
                cin >> weights[i][j];
            } else {
                weights[i][j] = 0; // Bobot ke diri sendiri adalah 0
            }
        }
    }

    // Menampilkan matriks bobot
    cout << "\nMatriks Bobot:\n";
    cout << setw(10) << " "; // Header baris kosong
    for (const auto& node : nodes) {
        cout << setw(10) << node;
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(10) << nodes[i]; // Nama simpul di sisi kiri
        for (int j = 0; j < n; j++) {
            cout << setw(10) << weights[i][j];
        }
        cout << endl;
    }

    return 0;
}
