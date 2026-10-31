#include "Buku.h"

int main() {
    List L;
    infotype x;
    address P;

    CreateList(L);

    for (int i = 0; i < 4; i++) {
        cout << "masukkan kode buku: ";
        cin >> x.kodeBuku;
        cout << "masukkan judul buku: ";
        cin >> x.judul;
        cout << "masukkan tahun terbit: ";
        cin >> x.thnTerbit;

        if (findElm(L, x) != Nil) {
            cout << "kode buku sudah terdaftar" << endl;
        } else {
            P = alokasi(x);
            insertLast(L, P);
        }
        cout << endl;
    }

    printInfo(L);
    cout << endl;

    cout << "Masukkan Kode Buku yang dicari : ";
    cin >> x.kodeBuku;
    P = findElm(L, x);
    if (P != Nil) {
        cout << "Kode Buku    : " << P->info.kodeBuku << endl;
        cout << "Judul        : " << P->info.judul << endl;
        cout << "Tahun Terbit : " << P->info.thnTerbit << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
    cout << endl;

    cout << "Masukkan Kode Buku yang akan dihapus : ";
    cin >> x.kodeBuku;
    P = findElm(L, x);
    if (P == Nil) {
        cout << "Data tidak ditemukan." << endl;
    } else {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(P->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan kode buku " << x.kodeBuku << " berhasil dihapus." << endl;
    }
    cout << endl;

    printInfo(L);
    return 0;
}
