#include <iostream>
using namespace std;

int main() {
    int a = 20;
    int *p = &a; // p menunjuk ke alamat a

    cout << "Nilai a: " << a << endl;
    cout << "Nilai yang ditunjuk oleh pointer p: " << *p << endl; // mengakses nilai melalui pointer
    return 0;
}
