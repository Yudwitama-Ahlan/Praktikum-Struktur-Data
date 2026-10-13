#include <iostream>
using namespace std;

int main(){
    int n;

    cout << "input: ";
    cin >> n;
    cout << "output:" << endl;

    for(int baris = n; baris >= 0; baris--){
        int jumlahSpasi = (n - baris) * 2;

        for(int s = 0; s < jumlahSpasi; s++){
            cout << " ";
        }
        for(int kiri = baris; kiri >= 1; kiri--){
            cout << kiri << " ";
        }
        cout << "*";
        for(int kanan = 1; kanan <= baris; kanan++){
            cout << " " << kanan;
        }
        cout << endl;
    }

    return 0;
}