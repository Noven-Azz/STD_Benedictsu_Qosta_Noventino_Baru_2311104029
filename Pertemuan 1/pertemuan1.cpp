// #include <iostream>

// using namespace std;

// int main() {
//     cout << "Saya belajar bahasa pemograman c++" << endl;
//     return 0;
// }

// #include <iostream>

// using namespace std;

// int main() {
//     int inp;
//     cin >> inp;
//     cout << "nilai = " << inp;
//     return 0;
// }

// #include <iostream>
// #include <stdio.h>

// using namespace std;

// int main() {
//     int W, X, Y;
//     float Z;
    
//     X = 7;
//     Y = 3;
//     W = 1;

//     Z = (X + Y) / (Y + W);

//     cout << "Nilai Z = " << Z << endl;
//     return 0;
// }

/* contoh penggunaan 'if' */
#include <iostream>
using namespace std;

int main() {
    double tot_pembelian, diskon;
    cout << "total pembelian: Rp";
    cin >> tot_pembelian;

    diskon = 0;

    if (tot_pembelian >= 100000) {
        diskon = 0.05 * tot_pembelian;
    }

    cout << "besar diskon = Rp" << diskon;
}

