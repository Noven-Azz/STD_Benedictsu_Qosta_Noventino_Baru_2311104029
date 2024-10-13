#include <iostream>
#include <cmath>
using namespace std;

class Kerucut {
private:
    double jariJari;
    double tinggi;

public:
    // Constructor
    Kerucut(double r, double t) : jariJari(r), tinggi(t) {}

    // Fungsi untuk menghitung volume
    double volume() {
        return (1.0 / 3) * M_PI * pow(jariJari, 2) * tinggi;
    }

    // Fungsi untuk menghitung luas permukaan
    double luasPermukaan() {
        double s = sqrt(pow(jariJari, 2) + pow(tinggi, 2)); // Panjang garis pelukis
        return M_PI * jariJari * (jariJari + s);
    }

    // Fungsi untuk menampilkan informasi kerucut
    void info() {
        cout << "Jari-Jari: " << jariJari << endl;
        cout << "Tinggi: " << tinggi << endl;
        cout << "Volume: " << volume() << endl;
        cout << "Luas Permukaan: " << luasPermukaan() << endl;
    }
};

int main() {
    Kerucut k(5.0, 10.0); // Membuat objek kerucut
    k.info(); // Menampilkan informasi kerucut
    return 0;
}
