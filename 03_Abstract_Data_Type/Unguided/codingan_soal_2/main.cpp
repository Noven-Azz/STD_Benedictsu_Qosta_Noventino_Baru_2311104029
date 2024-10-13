#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    // Membuat objek pelajaran menggunakan fungsi create_pelajaran
    pelajaran pel = create_pelajaran(namapel, kodepel);

    // Menampilkan data pelajaran
    tampil_pelajaran(pel);

    return 0;
}
