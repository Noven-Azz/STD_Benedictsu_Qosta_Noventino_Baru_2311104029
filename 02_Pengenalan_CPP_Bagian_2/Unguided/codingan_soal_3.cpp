#include <iostream>
using namespace std;

void findMaximum(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "Nilai maksimum adalah: " << max << endl;
}

void findMinimum(int arr[], int size) {
    int min = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "Nilai minimum adalah: " << min << endl;
}

void findAverage(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    double average = (double)sum / size;
    cout << "Nilai rata-rata adalah: " << average << endl;
}

int main() {
    int size;
    
    // Input ukuran array
    cout << "Masukkan jumlah elemen array: ";
    cin >> size;

    int arr[size];

    // Input elemen array
    cout << "Masukkan elemen array:" << endl;
    for(int i = 0; i < size; i++) {
        cout << "Elemen ke-" << i+1 << ": ";
        cin >> arr[i];
    }

    int choice;
    
    do {
        // Menu pilihan
        cout << "\nPilih operasi yang diinginkan:" << endl;
        cout << "1. Cari Nilai Maksimum" << endl;
        cout << "2. Cari Nilai Minimum" << endl;
        cout << "3. Cari Nilai Rata-rata" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;

        // Menjalankan operasi berdasarkan pilihan
        switch(choice) {
            case 1:
                findMaximum(arr, size);
                break;
            case 2:
                findMinimum(arr, size);
                break;
            case 3:
                findAverage(arr, size);
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while(choice != 4);

    return 0;
}
