# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>

<p align="center">Yudwitama Ahlan Putra Hayuning Bawana - 109082530016</p>

## Dasar Teori

Pada singly linked list, simpul hanya bisa dikunjungi satu per satu dari depan ke belakang[2][3]. Akibatnya, untuk mengubah atau mengambil data di simpul tertentu, simpul itu harus ditemukan lebih dulu lewat penelusuran. Karena itulah operasi pencarian (searching) dan pengubahan (update) saling berhubungan, dan keduanya melengkapi operasi tambah dan hapus yang sudah dipelajari di Modul 4. Aplikasi pengolahan data mahasiswa berbasis linked list, misalnya, mencakup operasi tambah, hapus, cari, dan tampilkan[1].

### A. Searching pada Singly Linked List<br/>

Searching adalah operasi pencarian terhadap node tertentu di dalam list.

#### 1. Konsep Searching

Proses searching berjalan dengan mengunjungi setiap node dan berhenti setelah node yang dicari ketemu[4]. Hasil pencarian memudahkan operasi lain seperti insert after, delete after, dan update, karena posisi node acuannya sudah diketahui[4].

#### 2. Pencarian Sekuensial dan Biayanya

Singly linked list hanya bisa dibaca maju, sehingga pencarian dilakukan secara sekuensial ketika datanya tidak terurut[3]. Mengakses elemen tertentu harus menelusuri list dari awal dengan kompleksitas O(n), sedangkan array bisa langsung lewat indeks dengan O(1)[2].

#### 3. Bentuk Pencarian di Modul

Modul mencontohkan fungsi `findElm` yang mengembalikan alamat elemen berisi nilai tertentu atau `Nil` jika tidak ada, dan `fFindElm` yang mengembalikan nilai true atau false untuk pencarian berdasarkan alamat[4]. Pada program Guided, pencarian dibuat dalam tiga bentuk: berdasarkan data, berdasarkan alamat node, dan berdasarkan rentang harga.

### B. Update pada Singly Linked List<br/>

Update adalah operasi untuk mengubah data yang sudah tersimpan di dalam node list[3].

#### 1. Konsep Update

Proses update biasanya diawali dengan pencarian terhadap data atau node yang akan diubah[3]. Berbeda dari insert dan delete, update hanya mengganti isi data node. Pointer `next` tidak disentuh, jadi susunan tautan list tidak berubah.

#### 2. Update First, Last, dan After

Update first langsung mengakses node yang ditunjuk `first`. Update last menelusuri list sampai node yang `next`-nya `Nil`. Update after memakai sebuah node acuan, lalu yang diubah adalah node tepat setelahnya.

#### 3. Kaitan Update dengan Data yang Sering Berubah

Linked list cocok untuk data yang sering berubah karena ukurannya dinamis dan perubahan di tengah list cukup dengan mengatur tautan antar simpul[1][2]. Update melengkapi kebutuhan itu untuk perubahan isi data tanpa perlu menghapus dan menyisipkan ulang node.

## Guided

### 1. [Header - listBuah.h]

```C++
//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

Strukturnya masih sama dengan header Modul 4, hanya isi datanya yang ganti. Tiap simpul sekarang menyimpan satu buah lewat `struct buah` (nama, jumlah, harga), lalu diberi alias `dataBuah`. Header guard di bagian atas mencegah file ini ter-include dua kali dalam satu program. Dua hal baru ada di bagian prototype: tiga prosedur update untuk materi Modul 5, dan tiga prosedur pencarian (`FindNodeByData`, `FindNodeByAddress`, `FindNodeByRange`). Prosedur update dan pencarian menerima `linkedlist` tanpa tanda `&`, karena keduanya tidak mengubah `first`. Itu akan kelihatan jelas saat masuk ke implementasinya.

### 2. [Source - listBuah.cpp]

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

Dasar list dan insert masih melanjutkan Modul 4. `isEmpty` mengecek apakah `first` masih `Nil`, dan `createList` mengosongkan `first` untuk list baru. `alokasi` membuat simpul dengan `new`, mengisi nama, jumlah, dan harga buah, lalu menyetel `next` ke `Nil`, sedangkan `dealokasi` memutus `next` dan mengembalikan memori lewat `delete`. Pada insert, `insertFirst` mengarahkan `next` simpul baru ke simpul pertama yang lama sebelum `first` dipindah, `insertAfter` menyisipkan simpul baru tepat setelah `Prev`, dan `insertLast` menelusuri list sampai simpul yang `next`-nya `Nil` baru menyambungkan simpul baru di sana. Kalau `Prev` bernilai `Nil`, `insertAfter` hanya mencetak pesan "Node sebelumnya tidak valid!".

Prosedur delete juga sama dengan Modul 4, bedanya sekarang tiap penghapusan mencetak pesan konfirmasi. `delFirst` menyimpan alamat simpul pertama di `nodeHapus`, menggeser `first` ke simpul kedua, lalu mendealokasi simpul lama. `delLast` punya tiga kemungkinan: list kosong, list berisi satu simpul (simpul itu langsung didealokasi), dan list berisi banyak simpul. Untuk kemungkinan terakhir, `nodePrev` berjalan satu langkah di belakang `nodeHapus` supaya `nodePrev->next` bisa diisi `Nil` sebelum simpul akhir dibuang. `delAfter` melompatkan `nodePrev->next` ke `nodeHapus->next`, lalu mendealokasi `nodeHapus`. Nilai `nodeHapus` yang dikirim dari `main` langsung ditimpa di dalam fungsi, jadi tidak terpakai. Lalu `printList` menelusuri list dan mencetak nama buah, jumlah, serta harga setiap simpul, `nbList` menghitung simpul dengan penelusuran yang sama, dan `deleteList` menghapus simpul satu per satu sambil menyimpan alamat simpul berikutnya sebelum simpul sekarang didealokasi.

Materi baru Modul 5 dimulai dari prosedur update. Ketiganya tidak mengubah susunan tautan, hanya isi data node, dan datanya dibaca langsung dari keyboard dengan `cin`. `updateFirst` menulis input ke `List.first->isidata`, `updateLast` menelusuri list sampai `nodeBantu` berada di simpul yang `next`-nya `Nil` lalu menimpa datanya, dan `updateAfter` mengubah simpul tepat setelah `nodePrev`. Kalau `nodePrev` atau `nodePrev->next` kosong, yang muncul pesan "Node sebelumnya (prev) tidak valid!". Parameter `List` pada ketiganya dikirim tanpa `&`, padahal data list berubah. Itu tidak masalah karena `List` yang disalin hanya berisi satu pointer `first`, dan pointer itu tetap menunjuk node yang sama dengan list asli, jadi perubahan data node ikut terbawa. Parameter `&` baru diperlukan kalau prosedurnya mengubah `first`, seperti `insertFirst`. Satu catatan, `cin >>` pada `nama` hanya membaca satu kata, sehingga nama buah yang memakai spasi akan terpotong.

Bagian terakhir adalah tiga prosedur pencarian yang memakai kerangka sama: mulai dari `first`, tambah `posisi` setiap pindah simpul, cek kondisi, lalu maju ke `next`. Karena `posisi` ditambah sebelum pengecekan, simpul pertama dihitung sebagai posisi ke-1. `FindNodeByData` membandingkan `nama` tiap simpul dengan data yang dicari dan berhenti dengan `break` pada kecocokan pertama. Kalau sampai akhir tidak ada yang cocok, `found` tetap `false` dan yang muncul pesan "tidak ditemukan". `FindNodeByAddress` membandingkan alamat simpul dengan alamat yang dikirim, dan kalau cocok, alamat itu ikut dicetak. `FindNodeByRange` mencari berdasarkan harga dan batas atas maupun bawahnya ikut dihitung (`>=` dan `<=`). Prosedur ini tidak memakai `break`, jadi semua buah yang harganya masuk rentang ikut tampil, bukan hanya yang pertama. Ketiganya mencetak baris kosong di akhir supaya hasil pencarian tidak menempel dengan keluaran berikutnya.

### 3. [Main - main.cpp]

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

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

Program utama membuat lima simpul buah dan menyusunnya lewat insert, sehingga urutan list menjadi Jeruk, Pir, Semangka, Apel, Durian dengan jumlah node 5. Tahap update meminta input dari keyboard tiga kali: `updateFirst` mengganti data Jeruk, `updateLast` mengganti data Durian, dan `updateAfter` dengan `nodeD` (Semangka) sebagai acuan mengganti data Apel. Posisi simpul tidak bergeser, hanya isinya yang berubah, jadi jumlah node tetap 5. Tahap searching memakai tiga pencarian: nama "kelapa" (tidak ada di data awal, jadi hasilnya "tidak ditemukan" kecuali nama itu dimasukkan saat update), alamat `nodeC` yang tetap berada di posisi ke-2 karena Pir tidak ikut diubah, dan rentang harga 5000 sampai 10000. Sebagai contoh, saat data update diisi Mangga (50, 8000), Anggur (20, 25000), dan Melon (30, 6000), pencarian rentang harga menemukan Mangga di posisi 1, Pir di posisi 2, dan Melon di posisi 4, sedangkan Semangka (11500) dan Anggur (25000) berada di luar rentang. Tahap delete menjalankan `delFirst` (membuang simpul pertama), `delLast` (membuang simpul terakhir), dan `delAfter` dengan `nodeC` sebagai acuan (membuang simpul tepat setelah Pir), sehingga tersisa dua node. `deleteList` mengosongkan sisanya dan `printList` menampilkan "List kosong." dengan jumlah node 0. Variabel `dtBuah` dideklarasikan tetapi tidak dipakai.

## Unguided

Ketiga soal pada 5.2 Latihan saling berkaitan karena memakai list yang sama (9, 12, 8, 0, 2), jadi semuanya dijawab dengan satu program yang terdiri dari `Singlylist.h`, `Singlylist.cpp`, dan `main.cpp`. Setiap soal punya bagian di `main.cpp` dan outputnya sendiri.

### 1. (Soal nomor 2) Membuat ADT Singly Linked List di `Singlylist.h` dengan `createList`, `alokasi`, `dealokasi`, `printInfo`, dan `insertFirst`, lalu mengimplementasikannya di `Singlylist.cpp` dan menjalankannya di `main.cpp` dengan data 9, 12, 8, 0, 2

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

address findElm(List L, infotype x);
int totalInfo(List L);

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

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

int totalInfo(List L) {
    int total = 0;
    address P = L.First;
    while (P != Nil) {
        total = total + P->info;
        P = P->next;
    }
    return total;
}
```

**[Main - main.cpp]**

```C++
#include <iostream>
#include "Singlylist.h"
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
    cout << endl;

    address hasil = findElm(L, 8);
    if (hasil != Nil) {
        cout << "8 ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }
    cout << endl;

    cout << "Total info dari kelima elemen adalah " << totalInfo(L) << endl;

    return 0;
}
```

### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/Yudwitama-Ahlan/Praktikum-Struktur-Data/blob/main/20-10-2026/Output/Unguided-One.png?raw=true)

Header memuat `infotype` (int), `address` sebagai pointer ke `ElmList`, struct `ElmList` yang berisi `info` dan `next`, struct `List` yang menyimpan `First`, serta prototype prosedur dan fungsi untuk ketiga soal. Di `Singlylist.cpp`, `createList` mengisi `First` dengan `Nil`, `alokasi` membuat simpul berisi nilai `x`, `dealokasi` membebaskan memorinya, `printInfo` menelusuri list sambil mencetak `info` tiap simpul, dan `insertFirst` memasang simpul baru di depan list. Nilai 2, 0, 8, 12, 9 dimasukkan berurutan dengan `insertFirst`. Karena tiap simpul baru selalu ditaruh paling depan, urutan di dalam list jadi kebalik dari urutan insert, yaitu 9 12 8 0 2, sama dengan ilustrasi di soal. Pada soal, prosedur ditulis `CreateList` sedangkan `main` memanggil `createList`, jadi di kode ini dipakai `createList` agar sesuai dengan `main`. Titik koma setelah `printInfo(L)` juga ditambahkan supaya program bisa di-compile.

### 2. (Soal nomor 3) Mencari elemen dengan info 8 dengan membuat fungsi baru `findElm(L, x) : address`

Soal ini memakai file yang sama dengan Unguided 1. Bagian yang menjawabnya adalah fungsi `findElm` di `Singlylist.cpp` dan blok "Unguided 2" di `main.cpp`.

### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/Yudwitama-Ahlan/Praktikum-Struktur-Data/blob/main/20-10-2026/Output/Unguided-Two.png?raw=true)

`findElm` memulai penelusuran dari `First`, membandingkan `info` setiap simpul dengan `x`, dan langsung mengembalikan alamat simpul begitu nilainya cocok. Kalau penelusuran sampai `Nil` tanpa kecocokan, fungsi mengembalikan `Nil`. Pada list 9 12 8 0 2, angka 8 ada di simpul ketiga, jadi `findElm` mengembalikan alamat simpul itu, dan `main` mencetak "8 ditemukan dalam list" karena hasilnya tidak sama dengan `Nil`. Fungsi mengembalikan alamat, bukan sekadar true atau false, supaya hasil pencarian bisa dipakai untuk operasi lanjutan seperti insert after atau update pada node tersebut.

### 3. (Soal nomor 4) Menghitung jumlah total info seluruh elemen list (9+12+8+0+2 = 31)

Soal ini juga memakai file yang sama. Bagian yang menjawabnya adalah fungsi `totalInfo` di `Singlylist.cpp` dan blok "Unguided 3" di `main.cpp`.

### Output Unguided 3 :

![Screenshot Output Unguided 3_1](https://github.com/Yudwitama-Ahlan/Praktikum-Struktur-Data/blob/main/20-10-2026/Output/Unguided-Three.png?raw=true)

`totalInfo` menelusuri list dari `First` dan menjumlahkan `info` setiap simpul ke variabel `total`. Variabel `total` mulai dari 0, lalu bertambah 9, 12, 8, 0, dan 2 berturut-turut sampai `P` bernilai `Nil`, sehingga hasil akhirnya 31. Penelusurannya sama dengan `printInfo` dan `nbList`, hanya saja yang dilakukan di setiap simpul adalah penjumlahan, bukan mencetak atau menghitung banyak simpul. Kalimat "Total info dari kelima elemen adalah" ditulis langsung di `main` agar sama dengan output yang diminta soal.

## Kesimpulan

Searching dan update pada singly linked list sama-sama bertumpu pada penelusuran dari `first` lewat pointer `next`. Pada Guided, tiga bentuk pencarian (data, alamat, dan rentang harga) memakai kerangka yang sama dan hanya berbeda di kondisi pengecekannya. `FindNodeByRange` tidak berhenti di kecocokan pertama sehingga semua buah dalam rentang tampil, sedangkan dua lainnya berhenti begitu simpulnya ketemu. Prosedur update tidak mengubah tautan, hanya isi data node, sehingga parameter list cukup dikirim tanpa `&` selama `first` tidak berubah. Program Guided menghasilkan 5 node setelah insert dan update, 2 node setelah delete, dan 0 node setelah `deleteList`. Pada Unguided, `printInfo` menghasilkan 9 12 8 0 2, `findElm` menemukan angka 8 di simpul ketiga, dan `totalInfo` menjumlahkan seluruh info menjadi 31, sama dengan output yang diminta soal. Karena singly linked list tidak punya akses langsung ke simpul tertentu, ketiga operasi itu selalu menelusuri list dari awal dengan kompleksitas O(n).

## Referensi

[1] Mbejo, M. T., Nopa, L. A., Putri, J. S., & Risky, M. (2025). Analisis Struktur Data Linked List Dalam Pengolahan Data Mahasiswa. Jurnal Sains Informatika Terapan, 4(2), 441-444. Diakses melalui https://doi.org/10.62357/jsit.v4i2.591.
<br>[2] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH, 5(2), 484-498. Diakses melalui https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/download/4263/pdf.
<br>[3] Fakultas Informatika, Telkom University. Modul 4: Singly Linked List (Bagian Pertama). Modul Praktikum Struktur Data (Modul_04_STUKDAT.pdf).
<br>[4] Fakultas Informatika, Telkom University. Modul 5: Singly Linked List (Bagian Kedua). Modul Praktikum Struktur Data (Modul_05_STUKDAT.pdf).
