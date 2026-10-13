#include <iostream>
using namespace std;

int main(){
    float bil1, bil2;

    cout << "Masukkan bilangan pertama: ";
    cin >> bil1;
    cout << "Masukkan bilangan kedua: ";
    cin >> bil2;

    cout << "Hasil penjumlahan = " << (bil1 + bil2) << endl;
    cout << "Hasil pengurangan = " << (bil1 - bil2) << endl;
    cout << "Hasil perkalian   = " << (bil1 * bil2) << endl;
    cout << "Hasil pembagian   = " << (bil1 / bil2) << endl;

    return 0;
}