#include "singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    P->next = Nil;
    delete P;
    P = Nil;
}

void printInfo(List L) {
    if (L.First == Nil) {
        cout << "List kosong" << endl;
    } else {
        address P = L.First;
        while (P != Nil) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L) {
    if (L.First == Nil) {
        cout << "List kosong" << endl;
    } else {
        address P = L.First;
        L.First = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.First == Nil) {
        cout << "List kosong" << endl;
    } else if (L.First->next == Nil) {
        address P = L.First;
        L.First = Nil;
        dealokasi(P);
    } else {
        address Q = L.First;
        while (Q->next->next != Nil) {
            Q = Q->next;
        }
        address P = Q->next;
        Q->next = Nil;
        dealokasi(P);
    }
}

void deleteAfter(List &L, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        address P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
        dealokasi(P);
    } else {
        cout << "Node sebelumnya tidak valid" << endl;
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.First;
    while (P != Nil) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

void deleteList(List &L) {
    address P = L.First;
    while (P != Nil) {
        address berikutnya = P->next;
        dealokasi(P);
        P = berikutnya;
    }
    L.First = Nil;
    cout << "- List Berhasil Terhapus -" << endl;
}