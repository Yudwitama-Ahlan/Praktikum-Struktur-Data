# Laporan Praktikum Modul 7 - Stack

Yudwitama Ahlan Putra Hayuning Bawana - 109082530016

## Dasar Teori

### A. Pengertian Stack

Stack atau tumpukan adalah struktur data yang cara kerjanya mirip tumpukan barang di tempat yang cuma punya satu pintu di bagian atas. Barang baru dimasukkan lewat pintu itu, dan barang yang diambil juga lewat pintu yang sama, jadi barang yang keluar pertama selalu barang yang terakhir masuk\[1\]. Selain untuk latihan struktur data, stack dipakai untuk menentukan alamat memori, mencocokkan tanda kurung, dan mengubah penulisan ekspresi dari infix ke postfix\[2\].

#### 1. Prinsip LIFO

Prinsip kerja stack disebut LIFO (Last In First Out). Kalau data A, B, lalu C dimasukkan berurutan, data yang bisa diambil lebih dulu adalah C, kemudian B, baru A\[1\]. Data A tidak bisa diambil langsung sebelum C dan B keluar.

#### 2. Top

Stack hanya bisa diakses dari satu titik, yaitu elemen paling atas yang disebut Top\[4\]. Semua operasi tambah dan ambil data terjadi di Top. Pada stack representasi tabel di modul, stack yang masih kosong ditandai dengan Top = 0\[4\].

#### 3. Overflow dan Underflow

Dua kondisi yang harus dicek saat memakai stack adalah overflow dan underflow. Overflow terjadi ketika data dimasukkan ke stack yang sudah penuh, sedangkan underflow terjadi ketika data diambil dari stack yang kosong\[1\]. Karena itu, push perlu memeriksa apakah stack masih punya tempat dan pop perlu memeriksa apakah stack masih berisi.

### B. Operasi Dasar pada Stack

Operasi utama pada stack ada dua, yaitu push untuk memasukkan data dan pop untuk mengambil data\[1\]\[4\].

#### 1. Push

Push menaruh elemen baru di atas tumpukan. Pada representasi tabel, nilai Top dinaikkan satu lalu data disimpan pada posisi Top yang baru\[4\]. Pada representasi pointer, langkahnya sama dengan insert first pada linked list\[4\].

#### 2. Pop

Pop mengambil elemen yang ada di posisi Top, lalu Top turun satu posisi. Pada representasi tabel, data lama tidak dihapus dari array. Posisinya saja yang dilepas dari stack\[4\].

#### 3. Primitif Lain

Selain push dan pop, ADT stack biasanya punya primitif seperti createStack untuk membuat stack kosong, isEmpty untuk mengecek apakah stack kosong, dan prosedur untuk menampilkan isi stack\[1\]\[4\].

### C. Representasi Stack

Stack bisa dibuat dengan dua cara, yaitu pointer dan tabel\[4\].

#### 1. Representasi Pointer

Setiap elemen berisi info dan pointer next yang menunjuk elemen di bawahnya, sedangkan Top menunjuk elemen paling atas. Ukuran stack bisa bertambah sesuai kebutuhan, tetapi memori untuk setiap elemen perlu dialokasikan dan dibebaskan sendiri\[4\].

#### 2. Representasi Tabel

Elemen disimpan dalam array berindeks, jadi jumlah elemennya terbatas sebesar ukuran array. Pada implementasi dengan array, atribut top menunjuk elemen yang paling akhir dimasukkan\[3\]. Cara ini tidak memerlukan alokasi dan dealokasi memori\[4\].

#### 3. Representasi yang Dipakai

Praktikum ini memakai representasi tabel. Guided memakai array 10 elemen yang berisi data NIM dan nama, sedangkan Unguided memakai array 20 elemen bertipe integer.

## Guided

### 1. Header - stack.h

```C++
/* file : stack.h
   contoh ADT stack dengan representasi tabel */
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

struct infotype {
    char nim[20];
    char nama[20];
};
struct Stack {
    infotype info[10];
    int Top;
};

/* prototype */
/******** pengecekan apakah Stack kosong *********/
int isEmpty(Stack S);
/* mengembalikan nilai 0 jika stack kosong */

/******** pembuatan Stack ********/
void createStack(Stack &S);
/* I.S. sembarang
   F.S. terbentuk stack dengan Top=0 */

/******** penambahan elemen pada Stack ********/
void push(Stack &S, infotype X);
/* I.S. Stack mungkin kosong
   F.S. menambahkan elemen pada stack dengan nilai X, TOP=TOP+1 */

/******** penghapusan elemen pada Stack ********/
void pop(Stack &S, infotype &X);
/* I.S. stack tidak kosong
   F.S. nilai info pada indeks TOP disimpan pada X, kemudian TOP=TOP-1 */

/******** proses semua elemen Stack *********/
void viewStack(Stack S);
/* I.S. stack mungkin kosong
   F.S. jika stack tidak kosong menampilkan semua info yang ada pada stack
*/
#endif // STACK_H_INCLUDED
```

File header ini berisi cetakan dasar stack yang dipakai di seluruh program. Ada dua struct. Struct infotype menyimpan satu data mahasiswa, yaitu nim dan nama, masing-masing array char berukuran 20. Struct Stack punya array info yang muat 10 data, dan satu integer bernama Top yang mencatat posisi data paling atas. Di bawahnya ada lima prototype, yaitu isEmpty, createStack, push, pop, dan viewStack, lengkap dengan komentar I.S. dan F.S. untuk kondisi awal dan kondisi akhir tiap prosedur. Yang perlu diingat, isEmpty dibuat mengembalikan 0 kalau stack kosong, jadi kebalikan dari kebiasaan umum yang memakai 1 atau true untuk kosong. Pasangan #ifndef dan #endif di atas dan bawah mencegah file ini terbaca dua kali waktu dikompilasi.

### 2. Implementasi - stack.cpp

```C++
#include "stack.h"

int isEmpty(Stack S) {
    /* Top = 0 berarti kosong, sesuai komentar di stack.h dikembalikan 0 */
    if (S.Top == 0) {
        return 0;
    } else {
        return 1;
    }
}

void createStack(Stack &S) {
    S.Top = 0;
}

void push(Stack &S, infotype X) {
    if (S.Top < 10) {
        S.Top = S.Top + 1;
        S.info[S.Top - 1] = X;   /* Top 1..10 dipetakan ke indeks array 0..9 */
    } else {
        cout << "Stack penuh, data tidak bisa ditambahkan" << endl;
    }
}

void pop(Stack &S, infotype &X) {
    if (isEmpty(S) != 0) {
        X = S.info[S.Top - 1];
        S.Top = S.Top - 1;
    } else {
        cout << "Stack kosong, tidak ada data yang bisa diambil" << endl;
    }
}

void viewStack(Stack S) {
    if (isEmpty(S) == 0) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "Isi stack (dari TOP):" << endl;
        for (int i = S.Top; i >= 1; i--) {
            cout << i << ". " << S.info[i - 1].nim << " - "
                 << S.info[i - 1].nama << endl;
        }
    }
}
```

File ini berisi isi dari semua prototype tadi. createStack hanya mengisi Top dengan 0 sebagai tanda stack masih kosong. isEmpty mengecek Top, kalau 0 dia mengembalikan 0 dan kalau bukan 0 dia mengembalikan 1, sesuai komentar di header. Fungsi push mengecek dulu apakah Top masih di bawah 10. Kalau masih, Top ditambah satu lalu data disimpan di S.info\[Top - 1\]. Pengurangan satu itu perlu karena Top dihitung dari 1 sampai 10 sedangkan indeks array mulai dari 0. Kalau stack sudah penuh, yang keluar hanya pesan dan datanya tidak dimasukkan. Fungsi pop jalannya kebalikan. Kalau stack tidak kosong, data di S.info\[Top - 1\] disalin ke X lalu Top dikurangi satu. Datanya sendiri tidak dihapus dari array, posisinya hanya dilepas dan nanti tertimpa kalau ada push baru. viewStack menampilkan isi dari atas ke bawah, jadi perulangannya turun dari Top sampai 1, sesuai dengan sifat LIFO.

### 3. Main - main.cpp

```C++
#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    infotype data, hasil;

    createStack(S);
    cout << "Stack baru dibuat, Top = " << S.Top << endl;
    viewStack(S);

    cout << endl << "--- Push 3 data ---" << endl;
    strcpy(data.nim, "103112400001");
    strcpy(data.nama, "Andi");
    push(S, data);

    strcpy(data.nim, "103112400002");
    strcpy(data.nama, "Budi");
    push(S, data);

    strcpy(data.nim, "103112400003");
    strcpy(data.nama, "Citra");
    push(S, data);
    viewStack(S);

    cout << endl << "--- Pop 1 data ---" << endl;
    pop(S, hasil);
    cout << "Data yang diambil: " << hasil.nim << " - " << hasil.nama << endl;
    viewStack(S);

    cout << endl << "--- Pop sampai kosong ---" << endl;
    pop(S, hasil);
    pop(S, hasil);
    pop(S, hasil);
    viewStack(S);

    return 0;
}
```

Di main, stack S dibuat dulu dengan createStack lalu langsung ditampilkan. Hasilnya Top = 0 dan tulisan "Stack kosong". Setelah itu tiga data dimasukkan satu per satu, yaitu Andi, Budi, dan Citra. Karena nim dan nama bertipe array char, isinya diisi dengan strcpy, itulah alasan ada `#include <cstring>`. Tanda sama dengan tidak bisa dipakai untuk array char. Waktu viewStack dipanggil, Citra muncul paling atas dengan nomor 3 karena dia masuk paling akhir. Berikutnya pop dipanggil sekali dan yang keluar Citra, sisanya Budi dan Andi. Bagian terakhir memanggil pop tiga kali padahal isi stack tinggal dua. Dua pop pertama mengambil Budi dan Andi, sedangkan pop ketiga menampilkan pesan "Stack kosong, tidak ada data yang bisa diambil" karena sudah tidak ada yang bisa diambil. Setelah itu viewStack menampilkan "Stack kosong".

## Unguided

### 1. Buatlah ADT Stack menggunakan array (maksimal 20 integer) di dalam file stack.h dengan prosedur createStack, push, fungsi pop, printInfo, dan balikStack. Buat implementasinya di stack.cpp dan main.cpp.

#### \[Header - stack.h\]

```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

#### \[Implementasi - stack.cpp\]

```C++
#include "stack.h"

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < 20) {
        S.top++;
        S.info[S.top - 1] = x;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = 0;
    if (S.top > 0) {
        x = S.info[S.top - 1];
        S.top--;
    } else {
        cout << "Stack kosong" << endl;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int kiri = 0;
    int kanan = S.top - 1;
    while (kiri < kanan) {
        infotype temp = S.info[kiri];
        S.info[kiri] = S.info[kanan];
        S.info[kanan] = temp;
        kiri++;
        kanan--;
    }
}
```

#### \[Main - main.cpp\]

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/Yudwitama-Ahlan/Praktikum-Struktur-Data/blob/main/10-11-2026/Output/Output-Unguided1-1.png)

Soal pertama meminta ADT Stack dari array yang memuat 20 integer. Di stack.h, infotype diubah menjadi int dan ukuran array info menjadi 20. Bedanya dengan Guided, pop di sini berupa fungsi yang mengembalikan nilai, sesuai ADT di soal, jadi data yang diambil langsung dikembalikan ke pemanggil. Kalau hasilnya tidak ditampung, seperti di main, nilainya dibuang begitu saja. printInfo mencetak \[TOP\] lalu isi stack dari atas ke bawah. balikStack membalik urutan isi stack memakai dua penanda, kiri di dasar dan kanan di puncak. Isi keduanya ditukar, lalu penanda bergerak ke tengah sampai bertemu. Di PDF, main memanggil Push dengan huruf P besar, sedangkan ADT-nya mendefinisikan push dengan huruf kecil. C++ membedakan huruf besar dan kecil, jadi di kode ini dipakai push. Kalau ditelusuri dari dasar ke puncak, isi stack berubah begini: push 3, 4, 8 menghasilkan 3 4 8, pop membuangnya jadi 3 4, push 2 dan 3 jadi 3 4 2 3, pop jadi 3 4 2, lalu push 9 jadi 3 4 2 9. Karena itu printInfo menampilkan 9 2 4 3, dan setelah dibalik menjadi 3 4 2 9, sama dengan Gambar 7-11 di modul.

### 2. Tambahkan prosedur pushAscending(in/out S : Stack, in x : integer).

#### \[Header - stack.h\]

```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int x);

#endif
```

#### \[Implementasi - stack.cpp\]

```C++
#include "stack.h"

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < 20) {
        S.top++;
        S.info[S.top - 1] = x;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = 0;
    if (S.top > 0) {
        x = S.info[S.top - 1];
        S.top--;
    } else {
        cout << "Stack kosong" << endl;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int kiri = 0;
    int kanan = S.top - 1;
    while (kiri < kanan) {
        infotype temp = S.info[kiri];
        S.info[kiri] = S.info[kanan];
        S.info[kanan] = temp;
        kiri++;
        kanan--;
    }
}

void pushAscending(Stack &S, int x) {
    Stack bantu;
    createStack(bantu);

    while (S.top > 0 && S.info[S.top - 1] > x) {
        push(bantu, pop(S));
    }

    push(S, x);

    while (bantu.top > 0) {
        push(S, pop(bantu));
    }
}
```

#### \[Main - main.cpp\]

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/Yudwitama-Ahlan/Praktikum-Struktur-Data/blob/main/10-11-2026/Output/Output-Unguided2-1.png)

Soal kedua menambah prosedur pushAscending. stack.h dan stack.cpp di atas sudah memuat semua prosedur dari soal 1, jadi yang baru hanya pushAscending. Setiap data baru dimasukkan di tempat yang pas supaya isi stack dari dasar ke puncak selalu urut naik, jadi angka terbesar ada di puncak. Caranya memakai satu stack bantu. Selama elemen paling atas stack utama lebih besar dari x, elemen itu di-pop lalu dipindah ke stack bantu. Setelah itu x di-push ke stack utama, dan semua elemen di stack bantu dikembalikan satu per satu. Contohnya saat angka 2 masuk ke stack yang isinya 3 4 8 (dasar ke puncak). Angka 8, 4, dan 3 dipindah dulu ke stack bantu, 2 di-push, lalu 3, 4, 8 dikembalikan sehingga isinya menjadi 2 3 4 8. Syarat perulangannya memakai "lebih besar" tanpa tanda sama dengan. Waktu angka 3 yang kedua masuk, 3 yang lama tidak ikut dipindah, jadi 3 yang baru duduk tepat di atasnya. Setelah enam angka masuk, printInfo menampilkan 9 8 4 3 3 2, dan setelah balikStack menjadi 2 3 3 4 8 9, sama dengan Gambar 7-13.

### 3. Tambahkan prosedur getInputStream(in/out S : Stack). Prosedur terus membaca input user dan memasukkannya ke stack sampai user menekan Enter.

#### \[Header - stack.h\]

```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int x);
void getInputStream(Stack &S);

#endif
```

#### \[Implementasi - stack.cpp\]

```C++
#include "stack.h"

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < 20) {
        S.top++;
        S.info[S.top - 1] = x;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = 0;
    if (S.top > 0) {
        x = S.info[S.top - 1];
        S.top--;
    } else {
        cout << "Stack kosong" << endl;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int kiri = 0;
    int kanan = S.top - 1;
    while (kiri < kanan) {
        infotype temp = S.info[kiri];
        S.info[kiri] = S.info[kanan];
        S.info[kanan] = temp;
        kiri++;
        kanan--;
    }
}

void pushAscending(Stack &S, int x) {
    Stack bantu;
    createStack(bantu);

    while (S.top > 0 && S.info[S.top - 1] > x) {
        push(bantu, pop(S));
    }

    push(S, x);

    while (bantu.top > 0) {
        push(S, pop(bantu));
    }
}

void getInputStream(Stack &S) {
    char c;
    c = cin.get();
    while (c != '\n') {
        if (c >= '0' && c <= '9') {
            push(S, c - '0');
        }
        c = cin.get();
    }
}
```

#### \[Main - main.cpp\]

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

### Output Unguided 3 :

![Screenshot Output Unguided 3_1](https://github.com/Yudwitama-Ahlan/Praktikum-Struktur-Data/blob/main/10-11-2026/Output/Output-Unguided3-1.png)

Soal ketiga menambah getInputStream. stack.h dan stack.cpp di atas sudah memuat semua prosedur dari soal 1 dan 2, jadi yang baru hanya getInputStream. Prosedur ini yang membaca ketikan user satu karakter demi satu karakter sampai Enter ditekan. Dipakai cin.get() karena setiap dipanggil dia mengambil satu karakter, termasuk Enter yang terbaca sebagai '\\n'. Perulangan while berjalan selama karakter yang terbaca bukan '\\n'. Setiap karakter yang berupa angka diubah menjadi nilai integernya dengan c - '0', lalu di-push. Pengurangan itu perlu karena karakter '4' sebenarnya menyimpan kode ASCII 52, jadi harus dikurangi kode '0' yaitu 48 supaya hasilnya 4. Karakter selain angka dilewati. Dengan input 4729601, angka masuk dari kiri ke kanan sehingga 1 masuk paling akhir dan berada di puncak. printInfo menampilkan 1 0 6 9 2 7 4, dan setelah dibalik menjadi 4 7 2 9 6 0 1, sama dengan Gambar 7-15.

## Kesimpulan

Stack ternyata sederhana karena semua aksesnya lewat satu titik, yaitu Top. Push menaikkan Top lalu menaruh data, pop mengambil data lalu menurunkan Top. Di representasi tabel, titik yang gampang keliru adalah selisih satu antara Top dan indeks array, makanya di kode selalu ada S.Top - 1. Guided juga menunjukkan kenapa push dan pop perlu mengecek kondisi penuh dan kosong dulu, supaya tidak terjadi overflow dan underflow. Pada Unguided, balikStack dan pushAscending memperlihatkan bahwa isi stack bisa diatur ulang dengan menukar langsung di array atau memakai stack lain sebagai tempat sementara. getInputStream memperlihatkan bahwa angka yang diketik dari keyboard bisa langsung ditumpuk dan dibaca dalam urutan terbalik.

## Referensi

\[1\] Naya, C. (2021). Perancangan Aplikasi Pembelajaran Ekspresi Matematika dengan Metode Stack Menggunakan Delphi 2010. SIGMA - Jurnal Teknologi Pelita Bangsa, 12(1), 25-30. [https://jurnal.pelitabangsa.ac.id/index.php/sigma/article/download/1267/820/2623](https://jurnal.pelitabangsa.ac.id/index.php/sigma/article/download/1267/820/2623) \
\[2\] Arianty, R. (2008). Converting Infix Notation to Postfix Notation Using Stack Application in Data Structure. Jurnal Ilmiah Informatika Komputer, 13(3). Universitas Gunadarma. [https://ejournal.gunadarma.ac.id/index.php/infokom/article/download/67/65](https://ejournal.gunadarma.ac.id/index.php/infokom/article/download/67/65) \
\[3\] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to Algorithms (4th ed.). Cambridge, MA: The MIT Press. ISBN 978-0-262-04630-5. [https://mitpressbookstore.mit.edu/book/9780262046305](https://mitpressbookstore.mit.edu/book/9780262046305) \
\[4\] Laboratorium Informatika. (n.d.). Modul 7 Stack. Modul Praktikum Struktur Data. Fakultas Informatika, Telkom University.
