#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n);
int cariMaksimum(int arr[], int n);
void hitungRataRata(int arr[], int n);

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata - rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Isi array : ";
            for (int i = 0; i < 10; i++) {
                cout << arrA[i] << " ";
            }
            cout << endl;
            break;
        case 2:
            cout << "Nilai maksimum = " << cariMaksimum(arrA, 10) << endl;
            break;
        case 3:
            cout << "Nilai minimum = " << cariMinimum(arrA, 10) << endl;
            break;
        case 4:
            hitungRataRata(arrA, 10);
            break;
        case 5:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia." << endl;
        }
    } while (pilihan != 5);

    return 0;
}

int cariMinimum(int arr[], int n) {
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

int cariMaksimum(int arr[], int n) {
    int maks = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maks)
            maks = arr[i];
    }

    return maks;
}

void hitungRataRata(int arr[], int n) {
    float total = 0;
    float rata_rata;

    for (int i = 0; i < n; i++) {
        total = total + arr[i];
    }

    rata_rata = total / n;
    cout << "Nilai rata - rata = " << rata_rata << endl;
}