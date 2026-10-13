#include <iostream>
#define MAX 3
using namespace std;

int main() {
    int A[MAX][MAX], B[MAX][MAX], hasil[MAX][MAX];
    int i, j, k;

    cout << "Masukkan elemen matriks A :" << endl;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\nMasukkan elemen matriks B :" << endl;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    cout << "\nHasil Penjumlahan (A + B) :" << endl;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan (A - B) :" << endl;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian (A x B) :" << endl;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            hasil[i][j] = 0;
            for (k = 0; k < MAX; k++) {
                hasil[i][j] = hasil[i][j] + A[i][k] * B[k][j];
            }
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}