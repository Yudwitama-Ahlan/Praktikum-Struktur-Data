# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>

<p align="center">Yudwitama Ahlan Putra Hayuning Bawana - 109082530016</p>

## Dasar Teori

Linked list atau senarai berantai adalah struktur data yang menyimpan sekumpulan elemen dan menyambungkannya satu sama lain lewat pointer, sehingga elemennya tidak harus berdampingan di memori[2]. Pada singly linked list, setiap simpul punya dua bagian, yaitu data dan pointer ke simpul berikutnya, dan penelusurannya hanya satu arah dari simpul awal (head) ke simpul akhir[2]. Karena ukurannya bisa bertambah dan berkurang saat program berjalan, struktur ini cocok untuk data yang sering berubah, misalnya data mahasiswa yang terus ditambah, dihapus, dicari, dan ditampilkan[1].

### A. Konsep Singly Linked List<br/>

Singly linked list adalah model linked list yang hanya punya satu arah pointer[3].

#### 1. Komponen Dasar

Modul menyebut `first` atau `head` sebagai pointer ke elemen pertama list, `next` sebagai pointer yang menunjuk elemen di depannya, dan `Nil` (NULL) sebagai penanda bahwa pointer tidak mengacu ke mana pun[3]. List kosong ditandai dengan `first` bernilai `Nil`, dan simpul terakhir selalu menunjuk `Nil`[3].

#### 2. Perbandingan dengan Array

Array dialokasikan secara statis, jadi ukurannya harus ditentukan sejak deklarasi, tetapi elemennya bisa diakses langsung lewat indeks dengan kompleksitas O(1)[2]. Linked list ukurannya dinamis dan sisip atau hapus di tengah cukup dengan mengubah tautan antar simpul tanpa menggeser elemen lain[2]. Harganya, mengakses elemen tertentu harus menelusuri list dari awal (O(n)) dan tiap simpul butuh ruang tambahan untuk menyimpan pointer[2].

#### 3. Linked List sebagai ADT

Pada C++, prototype fungsi dan tipe data ditaruh di file `.h`, implementasinya di file `.cpp`, dan program utama cukup meng-include file header untuk memakai semua operasinya[3]. Alokasi memori simpul memakai `new` dan pengembaliannya memakai `delete`[3].

### B. Operasi Dasar Singly Linked List<br/>

Operasi dasar pada linked list meliputi pembentukan list, penyisipan, penghapusan, penelusuran, pencarian, dan pengubahan elemen[3]. Praktikum ini memakai lima di antaranya: pembentukan, insert, delete, view, dan penghapusan seluruh list.

#### 1. Insert (First, Last, After)

Insert first menyambungkan `next` simpul baru ke simpul pertama yang lama, baru `first` dipindah ke simpul baru. Insert last menelusuri list sampai simpul akhir (`Q`), lalu `Q->next` diarahkan ke simpul baru. Insert after mengisi `next` simpul baru dengan `next` milik simpul acuan, lalu `next` simpul acuan diarahkan ke simpul baru[3]. Urutan langkahnya tidak boleh tertukar, karena alamat sisa list bisa hilang kalau pointer lama ditimpa lebih dulu.

#### 2. Delete (First, Last, After)

Delete first menyimpan alamat simpul pertama di sebuah pointer, memindahkan `first` ke simpul kedua, lalu mendealokasi simpul yang disimpan tadi[3]. Delete last membutuhkan simpul terakhir dan simpul tepat sebelumnya, kemudian `next` simpul sebelumnya diisi `Nil`[3]. Delete after menghubungkan simpul acuan langsung ke simpul sesudah target, lalu target dilepas dan didealokasi[3].

#### 3. View dan Hapus Seluruh List

View menelusuri setiap simpul dari `first` sambil menampilkan data yang tersimpan[3]. Penghapusan seluruh list (`delAll`) membebaskan semua memori yang dipakai simpul sehingga list kembali kosong[3].

## Guided

### 1. [Header - list.h]

```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedList {
    address first;
};

bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif
```

File ini berisi cetakan dari semua yang dipakai program: tipe data dan daftar fungsi. `#define Nil NULL` dibuat supaya pointer kosong bisa ditulis `Nil`, sesuai istilah di modul. Data tiap simpul dibungkus di `struct mahasiswa` (nama, NIM, umur) lalu diberi nama lain `dataMahasiswa`. Baris `typedef struct node *address;` ditulis sebelum `struct node` karena field `next` di dalam node butuh tipe `address`, sementara node-nya sendiri baru didefinisikan sesudahnya. `linkedList` hanya menyimpan satu pointer, yaitu `first` yang menunjuk simpul pertama. Sisanya adalah prototype fungsi yang diisi di list.cpp. Nama parameter di sini `list` huruf kecil, sedangkan di list.cpp ditulis `List`, dan itu tidak masalah karena nama parameter pada prototype bebas.

### 2. [Source - list.cpp] Pembuatan List dan Alokasi Memori

```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

void createList(linkedList &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}
```

`isEmpty` mengecek apakah `first` masih `Nil`, kalau iya berarti list kosong. `createList` mengisi `first` dengan `Nil` sehingga list baru langsung berstatus kosong. `alokasi` membuat simpul baru dengan `new`, mengisi nama, NIM, dan umur, lalu menyetel `next` ke `Nil` agar simpul itu tidak menunjuk alamat sembarang sebelum dipasang ke list. `dealokasi` memutus `next` lalu memanggil `delete` untuk mengembalikan memori simpul ke sistem.

### 3. [Source - list.cpp] Insert First, After, dan Last

```C++
void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}
```

`insertFirst` hanya dua langkah: `next` simpul baru diarahkan ke simpul pertama yang lama, baru `first` dipindah ke simpul baru. Kalau urutannya dibalik, alamat simpul lama hilang dan sisa list tidak bisa diakses lagi. Fungsi ini tetap jalan di list kosong karena `next`-nya tinggal berisi `Nil`. `insertAfter` memakai pola yang sama di tengah list: simpul baru mengambil `next` milik `Prev`, lalu `Prev->next` diarahkan ke simpul baru. Kalau `Prev` bernilai `Nil`, yang muncul pesan "Node sebelumnya tidak valid!". `insertLast` punya dua kasus. Pada list kosong, simpul baru langsung jadi `first`. Selain itu, `nodeBantu` berjalan sampai simpul yang `next`-nya `Nil`, lalu simpul baru disambung di situ. List ini tidak menyimpan pointer ke simpul terakhir, jadi insert di belakang harus jalan dari depan setiap kali.

### 4. [Source - list.cpp] Delete First, Last, dan After

```C++
void delFirst(linkedList &List) {
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List) {
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

`delFirst` menyimpan alamat simpul pertama di `nodeHapus`, menggeser `first` ke simpul kedua, lalu mendealokasi simpul lama. Kalau `first` digeser tanpa menyimpan alamatnya, simpul lama tidak bisa di-delete dan memorinya bocor. `delLast` menangani tiga keadaan: list kosong, list berisi satu simpul (`first` dikembalikan ke `Nil`), dan list berisi banyak simpul. Untuk keadaan terakhir, `nodePrev` membuntuti `nodeHapus` satu langkah di belakang. Begitu `nodeHapus` sampai di simpul akhir, `nodePrev->next` diisi `Nil` dan simpul akhir dibuang. Pointer pembuntut ini diperlukan karena singly linked list tidak bisa berjalan mundur. `delAfter` menghapus simpul tepat setelah `nodePrev` dengan cara melompatkan `nodePrev->next` ke `nodeHapus->next`, lalu `nodeHapus` didealokasi. Parameter `nodeHapus` langsung ditimpa di dalam fungsi dengan `nodePrev->next`, jadi nilai yang dikirim dari `main` sebenarnya tidak terpakai. Kalau `nodePrev` atau `nodePrev->next` kosong, yang muncul pesan "Node sebelumnya (prev) tidak valid!".

### 5. [Source - list.cpp] Print, Hitung Node, dan Hapus List

```C++
void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(linkedList &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```

`printList` menelusuri list dari `first` dan mencetak nama, NIM, dan usia tiap simpul sampai `nodeBantu` bernilai `Nil`. Kalau list kosong, langsung tercetak "List kosong.". `nbList` memakai penelusuran yang sama, tetapi isinya hanya menambah `count` untuk setiap simpul, lalu mengembalikan jumlahnya. `deleteList` menghapus simpul satu per satu. `nodeBantu` dimajukan ke simpul berikutnya sebelum `nodeHapus` didealokasi, sebab `next` milik simpul yang sudah di-delete tidak boleh dibaca lagi. Di akhir, `first` diisi `Nil` dan muncul pesan "List sudah terhapus!".

### 6. [Main - main.cpp]

```C++
#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211100014", 21);
    nodeC = alokasi("Rizal", "2311100029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

Program utama membuat list kosong, mengalokasi lima simpul (Dhimas, Arvin, Rizal, Satrio, Joshua), lalu menyusunnya lewat insert. Isi list berubah seperti ini: `insertFirst` Dhimas membuat list berisi Dhimas; `insertLast` Arvin menjadikannya Dhimas, Arvin; `insertAfter` Rizal setelah Dhimas menjadi Dhimas, Rizal, Arvin; `insertAfter` Satrio setelah Rizal menjadi Dhimas, Rizal, Satrio, Arvin; terakhir `insertLast` Joshua. Hasil cetaknya lima node dengan urutan Dhimas, Rizal, Satrio, Arvin, Joshua. Tahap delete dimulai dari `delFirst` yang membuang Dhimas, `delLast` yang membuang Joshua, lalu `delAfter` dengan `nodeC` (Rizal) sebagai acuan yang membuang Satrio, sehingga tersisa Rizal dan Arvin dengan jumlah node 2. `deleteList` mengosongkan sisanya, jadi `printList` menampilkan "List kosong." dan `nbList` bernilai 0. Variabel `mhs` pada program ini dideklarasikan tetapi tidak pernah dipakai.

## Unguided

### 1. Membuat ADT Singly Linked List dengan `CreateList`, `alokasi`, `dealokasi`, `printInfo`, `insertFirst`, lalu menjalankannya di `main.cpp` untuk data 9, 12, 8, 0, 2

**[Header - singlylist.h]**

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

**[Source - singlylist.cpp]**

```C++
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
```

**[Main - main.cpp]**

```C++
#include <iostream>
#include "singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```

### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/Yudwitama-Ahlan/Praktikum-Struktur-Data/blob/main/13-10-2026/Output/Output-Unguided1-1.png)

Header memuat tipe `infotype` (int), `address` sebagai pointer ke `ElmList`, struct `ElmList` yang berisi `info` dan `next`, struct `List` yang menyimpan `First`, dan lima prosedur yang diminta soal. Di `Singlylist.cpp`, `createList` mengisi `First` dengan `Nil`, `alokasi` membuat simpul baru berisi nilai `x` dengan `next` bernilai `Nil`, `dealokasi` membebaskan memorinya, `printInfo` menelusuri list dan mencetak `info` tiap simpul, dan `insertFirst` memasang simpul baru di depan list. Pada `main`, nilai 2, 0, 8, 12, 9 dimasukkan berurutan memakai `insertFirst`. Karena setiap simpul baru selalu ditaruh paling depan, urutan di dalam list jadi kebalik dari urutan insert, yaitu 9 12 8 0 2, sama dengan gambar linked list di soal. Pada soal, baris `printInfo(L)` tidak diberi titik koma, jadi di kode ini titik komanya ditambahkan supaya bisa di-compile.

### 2. Dari soal pertama, hapus node 9 dengan `deleteFirst()`, node 2 dengan `deleteLast()`, dan node 8 dengan `deleteAfter()`, lalu tampilkan jumlah node dengan `nbList()` dan hapus seluruh node dengan `deleteList()`

**[Header - singlylist.h]**

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif
```

**[Source - singlylist.cpp]**

```C++
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
```

**[Main - main.cpp]**

```C++
#include <iostream>
#include "singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    deleteFirst(L);       // hapus node 9
    deleteLast(L);        // hapus node 2
    deleteAfter(L, P4);   // hapus node 8 (setelah node 12)

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    return 0;
}
```

### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/Yudwitama-Ahlan/Praktikum-Struktur-Data/blob/main/13-10-2026/Output/Output-Unguided2-1.png)

Soal kedua memakai list yang sama dengan soal pertama (9 12 8 0 2), jadi header dan source ditambah lima prosedur baru: `deleteFirst`, `deleteLast`, `deleteAfter`, `nbList`, dan `deleteList`. `deleteFirst` membuang node 9 dengan cara menggeser `First` ke node 12. `deleteLast` berjalan memakai `Q` sampai `Q->next->next` bernilai `Nil`, artinya `Q` berhenti tepat sebelum simpul terakhir, lalu node 2 dilepas. Node 8 berada tepat setelah node 12, jadi `deleteAfter` dipanggil dengan `P4` (node 12) sebagai `Prec`, dan `Prec->next` dilompatkan ke node 0. Sisa list adalah 12 0 dan `nbList` menghitung 2 node. Terakhir, `deleteList` membuang semua simpul satu per satu, menyimpan alamat simpul berikutnya sebelum simpul sekarang didealokasi, lalu mencetak "- List Berhasil Terhapus -". `nbList` setelah itu bernilai 0, sesuai output yang diminta soal.

## Kesimpulan

Semua operasi pada singly linked list ini pada dasarnya adalah mengatur ulang pointer `next` dan `first`, dan urutan pengaturannya menentukan hasil. Saat insert, simpul baru disambungkan ke sisa list lebih dulu sebelum pointer lama diubah supaya tidak ada simpul yang hilang. Saat delete, alamat simpul yang akan dihapus disimpan dulu sebelum pointer digeser, dan delete last butuh satu pointer tambahan yang berjalan di belakang karena list hanya bisa ditelusuri maju. Program Guided menghasilkan 5 node setelah insert, 2 node setelah delete, dan 0 node setelah `deleteList`. Dua program Unguided mencetak 9 12 8 0 2, lalu 12 0 dengan jumlah node 2 dan 0 setelah list dihapus, sama dengan output yang diminta soal. Insert last dan `nbList` perlu menelusuri list dari awal, sedangkan insert first cukup memindahkan satu pointer, karena list hanya menyimpan pointer `first`.

## Referensi

[1] Mbejo, M. T., Nopa, L. A., Putri, J. S., & Risky, M. (2025). Analisis Struktur Data Linked List Dalam Pengolahan Data Mahasiswa. Jurnal Sains Informatika Terapan, 4(2), 441-444. Diakses melalui https://doi.org/10.62357/jsit.v4i2.591.
<br>[2] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH, 5(2), 484-498. Diakses melalui https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/download/4263/pdf.
<br>[3] Fakultas Informatika, Telkom University. Modul 4: Singly Linked List (Bagian Pertama). Modul Praktikum Struktur Data (Modul_04_STUKDAT.pdf).
