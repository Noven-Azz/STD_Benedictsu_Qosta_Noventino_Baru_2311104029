#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;

    // Meminta jumlah simpul dan jumlah sisi
    cout << "Masukkan jumlah simpul: ";
    cin >> n;
    cout << "Masukkan jumlah sisi: ";
    cin >> m;

    // Inisialisasi adjacency matrix dengan nilai 0
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    // Meminta pasangan simpul untuk setiap sisi
    cout << "Masukkan pasangan simpul:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Karena graf tidak berarah, simetri harus dijaga
        adjMatrix[u - 1][v - 1] = 1;
        adjMatrix[v - 1][u - 1] = 1;
    }

    // Menampilkan adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
