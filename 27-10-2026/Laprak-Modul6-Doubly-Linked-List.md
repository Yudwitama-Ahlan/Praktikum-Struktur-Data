# <h1 align="center">Laporan Praktikum Modul 6 - Doubly Linked List (Bagian Pertama)</h1>

<p align="center">Yudwitama Ahlan Putra Hayuning Bawana - 109082530016</p>

## Dasar Teori

Doubly linked list adalah linked list yang setiap elemennya punya dua penunjuk, yaitu prev yang menunjuk ke elemen sebelumnya dan next yang menunjuk ke elemen sesudahnya[1]. Karena punya dua arah, list ini bisa dijelajahi maju maupun mundur. Dalam literatur algoritma, elemen doubly linked list juga digambarkan sebagai objek yang menyimpan data beserta penunjuk next dan prev[2].

### A. Konsep Dasar Doubly Linked List<br/>

List dipegang lewat dua pointer utama, yaitu first dan last. List dianggap kosong kalau L.first bernilai Nil[1].

#### 1. Komponen

Ada empat komponen yang dipakai di modul ini: First (menunjuk elemen pertama), Last (menunjuk elemen terakhir), Next (penunjuk ke elemen setelahnya), dan Prev (penunjuk ke elemen sebelumnya)[1].

#### 2. Perbedaan dengan Singly Linked List

Pada singly linked list kita hanya bisa jalan satu arah. Di doubly linked list, elemen sebelumnya bisa langsung dicapai lewat prev, jadi iterasi mundur dan penghapusan elemen yang alamatnya sudah dipegang jadi lebih mudah[1][2]. Harganya, tiap elemen butuh satu pointer tambahan[3].

#### 3. Deklarasi ADT

Seperti singly linked list, doubly linked list juga dibuat sebagai ADT: tipe data elemen dan list dideklarasikan di file header (.h), sedangkan operasinya ditulis di file .cpp[1].

### B. Operasi pada Doubly Linked List<br/>

#### 1. Insert

Insert First memasang elemen baru di depan first. Insert Last memasangnya di belakang last. Insert After menyisipkan elemen baru setelah elemen R, sedangkan Insert Before kebalikannya, hanya beda di cara mencari elemen acuannya[1]. Untuk semua insert, penunjuk next dan prev di kedua sisi elemen baru harus dihubungkan, kalau tidak urutan list bisa putus.

#### 2. Delete

Delete First, Delete Last, Delete After, dan Delete Before melepas elemen dari list lalu mengembalikan alamatnya, atau langsung membebaskan memorinya dengan dealokasi[1]. Kalau alamat elemen yang dihapus sudah dipegang, proses melepasnya cukup mengubah beberapa pointer tanpa perlu menelusuri list[2].

#### 3. Searching, Update, dan View

Pencarian, update, dan view caranya sama dengan singly linked list[1]. Pencarian tetap harus menelusuri elemen satu per satu sehingga waktunya linear terhadap jumlah elemen[2][3].

## Guided

### 1. [Header - Doublylist.h]

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

#define Nil NULL

// Latihan 1
struct infotype
{
    std::string nopol;
    std::string warna;
    int thnBuat;
};
typedef struct elmlist *address;
struct elmlist
{
    infotype info;
    address next;
    address prev;
};
struct List
{
    address First;
    address Last;
};

// Latihan 1
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Latihan 2

address findElm(List L, std::string nopol);

// Latihan 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteElm(List &L, std::string nopol, bool &status);

#endif
```

Doublylist.h isinya cetakan dari seluruh program, jadi semua file lain bergantung ke sini. Di atas ada struct infotype yang menyimpan data kendaraan (nopol, warna, thnBuat). Lalu ada struct elmlist yang jadi satu elemen list, isinya info plus dua pointer, next dan prev. Pointer ke elmlist itu aku beri nama address biar penulisannya lebih pendek. Struct List memegang dua pointer, First untuk elemen paling depan dan Last untuk yang paling belakang. Sisanya cuma deklarasi fungsi dan prosedur yang dikerjakan di Doublylist.cpp, dikelompokkan sesuai nomor latihan. Ada pengaman #ifndef di awal supaya file ini tidak terbaca dua kali, dan Nil sekadar nama lain dari NULL.

### 2. [Implementasi - Doublylist.cpp]

```C++
#include "Doublylist.h"

// Latihan 1
void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void printInfo(List L) {
    address P = L.Last;
    if (P == Nil) {
        std::cout << "List kosong." << std::endl;
        return;
    }
    while (P != Nil) {
        std::cout << "no polisi : " << P->info.nopol << std::endl;
        std::cout << "warna     : " << P->info.warna << std::endl;
        std::cout << "tahun     : " << P->info.thnBuat << std::endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        (L.Last)->next = P;
        L.Last = P;
    }
}

// Latihan 2
address findElm(List L, std::string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Latihan 3
void deleteFirst(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.First;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;
        (L.First)->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.Last;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;
        (L.Last)->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) return;

    P = Prec->next;
    if (P == L.Last) {
        deleteLast(L, P);
    } else {
        Prec->next = P->next;
        (P->next)->prev = Prec;
        P->next = Nil;
        P->prev = Nil;
    }
}

void deleteElm(List &L, std::string nopol, bool &status) {
    address P = findElm(L, nopol);
    status = false;

    if (P != Nil) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P);
        status = true;
    }
}
```

Di file ini semua operasi benar-benar dikerjakan. CreateList membuat list kosong dengan mengisi First dan Last pakai Nil. alokasi membuat elemen baru lewat new, mengisi datanya, dan membiarkan next dan prev kosong. dealokasi tinggal membuang elemen dari memori. printInfo mencetak dari Last mundur lewat prev, makanya data yang paling akhir dimasukkan tampil duluan.

insertLast punya dua jalur. Kalau list masih kosong, elemen baru langsung jadi First sekaligus Last. Kalau sudah ada isinya, prev elemen baru diarahkan ke Last yang lama, next dari Last lama diarahkan ke elemen baru, baru Last digeser. findElm menelusuri list dari First sambil membandingkan nopol, lalu mengembalikan alamat elemen yang cocok atau Nil kalau tidak ada.

Untuk delete, deleteFirst dan deleteLast sama-sama menangani kasus list yang isinya cuma satu elemen, di mana First dan Last harus balik jadi Nil. deleteAfter melepas elemen setelah Prec dengan menyambungkan Prec ke elemen sesudahnya, dan kalau elemen itu ternyata yang terakhir, kerjanya dilempar ke deleteLast supaya Last ikut bergeser. deleteElm membungkus semuanya: cari elemennya, pilih delete yang cocok (First, Last, atau tengah), lalu dealokasi dan isi status berhasil atau tidak.

### 3. [Program Utama - main.cpp]

```C++
#include <iostream>
#include "Doublylist.h"
using namespace std;

void inputData(List &L) {
    infotype data;
    address P;

    cout << "masukkan nomor polisi: "; cin >> data.nopol;
    cout << "masukkan warna kendaraan: "; cin >> data.warna;
    cout << "masukkan tahun kendaraan: "; cin >> data.thnBuat;
    if (findElm(L, data.nopol) == Nil) {
        P = alokasi(data);
        insertLast(L, P);
    } else {
        cout << "nomor polisi sudah terdaftar" << endl;
    }
}

int main() {
    List L;
    CreateList(L);
    address P;

    // Latihan 1
    inputData(L);
    inputData(L);
    inputData(L);
    inputData(L);

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    // Latihan 2
    string nopolCari;
    cout << "\nMasukkan Nomor Polisi yang dicari : ";
    cin >> nopolCari;

    P = findElm(L, nopolCari);
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << nopolCari << " tidak ditemukan." << endl;
    }

    // Latihan 3
    string nopolHapus;
    bool hapusBerhasil;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopolHapus;

    deleteElm(L, nopolHapus, hapusBerhasil);

    if (hapusBerhasil) {
        cout << "Data dengan nomor polisi " << nopolHapus << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan." << endl;
    }
    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    return 0;
}
```

main.cpp tempat semua fungsi tadi dicoba. inputData membaca nopol, warna, dan tahun, lalu mengecek dengan findElm. Kalau nopol belum ada, data dialokasi dan dimasukkan lewat insertLast, kalau sudah ada, yang muncul cuma pesan bahwa nomor polisi sudah terdaftar. Fungsi ini dipanggil empat kali untuk mengisi list.

Setelah itu list dicetak, lalu program meminta satu nopol untuk dicari (Latihan 2) dan menampilkan datanya kalau ketemu. Terakhir (Latihan 3), program meminta nopol yang mau dihapus, memanggil deleteElm, memberi tahu berhasil atau tidaknya lewat variabel hapusBerhasil, dan mencetak list sekali lagi untuk melihat hasilnya.

## Unguided

### 1. Pembuatan ADT Dasar dan Insert Data (cek duplikasi kodeBuku)

[Header - Buku.h]

```C++
#ifndef BUKU_H
#define BUKU_H

#include <iostream>
#include <string>
using namespace std;

#define Nil NULL

struct buku {
    string kodeBuku;
    string judul;
    int thnTerbit;
};

typedef buku infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

address findElm(List L, infotype x);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```

[Implementasi - Buku.cpp]

```C++
#include "Buku.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    cout << "DATA LIST 1" << endl;
    address P = L.Last;
    while (P != Nil) {
        cout << "Kode Buku    : " << P->info.kodeBuku << endl;
        cout << "Judul        : " << P->info.judul << endl;
        cout << "Tahun Terbit : " << P->info.thnTerbit << endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        (L.Last)->next = P;
        L.Last = P;
    }
}
```

[Program Utama - main.cpp (bagian input)]

```C++
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

    // bagian soal 2 dan 3 dilanjutkan di bawah
    return 0;
}
```

### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/Yudwitama-Ahlan/Praktikum-Struktur-Data/blob/main/30-10-2026/Output/Output-Unguided1-1.png)

Di soal ini aku bikin ADT buku di Buku.h, isinya struct buku (kodeBuku, judul, thnTerbit) yang dipakai sebagai infotype, lalu ElmList dengan next dan prev, dan List dengan First dan Last. Buku.h aku tulis lengkap sekalian dengan prototype findElm dan tiga prosedur delete untuk soal 2 dan 3, jadi nanti tidak perlu diubah lagi.

Di Buku.cpp, alokasi membuat elemen baru dengan next dan prev yang sama-sama Nil. insertLast punya dua kondisi: kalau list masih kosong, First dan Last langsung diisi P. Kalau sudah ada isinya, prev elemen baru diarahkan ke Last, next dari Last lama diarahkan ke elemen baru, baru Last dipindah. printInfo sengaja jalan dari Last mundur lewat prev, karena contoh output di soal menampilkan data terbaru (B004) paling atas.

Pengecekan duplikasi aku taruh di main.cpp. Sebelum alokasi, kode yang baru diketik dicari dulu pakai findElm. Kalau ketemu, program cuma mencetak pesan "kode buku sudah terdaftar" dan elemen tidak dibuat, jadi B001 kedua (Basis_Data) tidak masuk list.

### 2. Pencarian Elemen (Searching)

[Fungsi findElm - Buku.cpp]

```C++
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil && P->info.kodeBuku != x.kodeBuku) {
        P = P->next;
    }
    return P;
}
```

[Pemanggilan - main.cpp]

```C++
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
```

### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/Yudwitama-Ahlan/Praktikum-Struktur-Data/blob/main/30-10-2026/Output/Output-Unguided2-1.png)

findElm mulai dari First lalu maju lewat next sampai ketemu kodeBuku yang sama atau sampai habis. Kalau ketemu, yang dikembalikan alamat elemennya, kalau tidak ada hasilnya Nil. Karena itu fungsi ini bisa dipakai dua kali: buat cek duplikasi di soal 1 dan buat mencari B001 di soal ini. Di main, hasilnya dicek dulu apakah Nil, kalau bukan baru datanya dicetak.

### 3. Penghapusan Elemen (Delete)

[Prosedur delete - Buku.cpp]

```C++
void deleteFirst(List &L, address &P) {
    P = L.First;
    if (P == Nil) return;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;
        (L.First)->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (P == Nil) return;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;
        (L.Last)->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    if (P != Nil) {
        Prec->next = P->next;
        if (P->next != Nil) {
            (P->next)->prev = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    }
}
```

[Pemanggilan - main.cpp]

```C++
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
```

### Output Unguided 3 :

![Screenshot Output Unguided 3_1](https://github.com/Yudwitama-Ahlan/Praktikum-Struktur-Data/blob/main/30-10-2026/Output/Output-Unguided3-1.png)

Di main, elemen yang mau dihapus dicari dulu pakai findElm, lalu program memilih prosedur yang cocok. Kalau elemennya First, dipanggil deleteFirst. Kalau Last, dipanggil deleteLast. Selain itu berarti elemennya ada di tengah, jadi dipanggil deleteAfter dengan elemen sebelumnya (P->prev) sebagai Prec.

deleteFirst dan deleteLast sama-sama punya kasus khusus kalau list isinya cuma satu elemen, First dan Last harus dua-duanya dikembalikan ke Nil. deleteAfter melompati elemen P dengan menyambungkan Prec langsung ke elemen setelah P, lalu prev elemen itu dibalikkan ke Prec. Setelah dilepas, elemennya dibebaskan dengan dealokasi. B003 ada di tengah list (B004, B003, B001 kalau dibaca dari Last), jadi yang jalan di contoh soal adalah deleteAfter, dan hasil akhirnya tinggal B004 dan B001 seperti di contoh output.

## Kesimpulan

Lewat praktikum ini aku bisa membuat ADT doubly linked list lengkap dengan First, Last, next, dan prev, lalu mengisinya dengan insertLast. Setiap operasi insert dan delete ternyata selalu menyangkut pointer di dua sisi elemen, jadi urutan penyambungan pointer perlu diperhatikan supaya list tidak putus. Kasus khusus seperti list kosong atau list berisi satu elemen juga harus ditangani sendiri di tiap prosedur. Pencarian dengan findElm tetap harus menelusuri elemen satu per satu, tapi hasilnya dipakai ulang untuk cek duplikasi dan untuk menentukan jenis delete yang dipanggil.

## Referensi

[1] Laboratorium Informatika, Fakultas Informatika, Telkom University. Modul 6 Doubly Linked List (Bagian Pertama), Praktikum Struktur Data (Modul_06_STUKDAT).
<br>[2] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to Algorithms (4th ed.). Cambridge, MA: MIT Press. Diakses pada 30 Oktober 2026 melalui https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/.
<br>[3] Naukri Code360. Doubly Linked List in C++. Diakses pada 30 Oktober 2026 melalui https://www.naukri.com/code360/library/double-linked-list-program-in-cpp.
