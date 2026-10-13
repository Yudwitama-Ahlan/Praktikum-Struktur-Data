#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int a[3][3], int b[3][3], int baris, int kolom) {
    int temp = a[baris][kolom];
    a[baris][kolom] = b[baris][kolom];
    b[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int arrayA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arrayB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;
    int baris, kolom;

    cout << "Array A sebelum ditukar :" << endl;
    tampilArray(arrayA);
    cout << "\nArray B sebelum ditukar :" << endl;
    tampilArray(arrayB);

    cout << "\nMasukkan posisi yang ditukar (baris kolom, 0-2) : ";
    cin >> baris >> kolom;

    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        tukarArray(arrayA, arrayB, baris, kolom);
        cout << "\nArray A setelah ditukar :" << endl;
        tampilArray(arrayA);
        cout << "\nArray B setelah ditukar :" << endl;
        tampilArray(arrayB);
    } else {
        cout << "\nPosisi di luar batas array." << endl;
    }

    cout << "\nNilai x dan y sebelum ditukar : " << *p1 << " dan " << *p2 << endl;
    tukarPointer(p1, p2);
    cout << "Nilai x dan y setelah ditukar : " << *p1 << " dan " << *p2 << endl;

    return 0;
}