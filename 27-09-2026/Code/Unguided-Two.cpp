#include <iostream>
using namespace std;

int main(){
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if(angka == 0){
        cout << angka << " : nol" << endl;
    }
    else if(angka == 100){
        cout << angka << " : seratus" << endl;
    }
    else if(angka < 10){
        cout << angka << " : " << satuan[angka] << endl;
    }
    else if(angka == 10){
        cout << angka << " : sepuluh" << endl;
    }
    else if(angka == 11){
        cout << angka << " : sebelas" << endl;
    }
    else if(angka < 20){
        cout << angka << " : " << satuan[angka-10] << " belas" << endl;
    }
    else{
        int puluh = angka / 10;
        int sisa = angka % 10;

        if(sisa == 0){
            cout << angka << " : " << satuan[puluh] << " puluh" << endl;
        }
        else{
            cout << angka << " : " << satuan[puluh] << " puluh " << satuan[sisa] << endl;
        }
    }

    return 0;
}