# Laporan Praktikum Modul 3 - Abstract Data Type (ADT)

(Nama Lengkap) - (NIM)

## Dasar Teori

### A. Abstract Data Type (ADT)

Abstract Data Type atau ADT adalah sebuah type beserta sekumpulan operasi dasar (primitif) yang berlaku untuk type tersebut \[1\]. Jadi sebuah ADT tidak hanya soal bentuk datanya, tapi juga apa saja yang boleh dilakukan terhadap data itu. Liskov dan Zilles menjelaskan bahwa ADT adalah kelas objek abstrak yang sifatnya ditentukan sepenuhnya oleh operasi yang tersedia pada objek tersebut \[2\]. Dengan cara ini, pengguna cukup tahu cara memakai type-nya tanpa harus tahu bagaimana data disimpan di dalamnya.

#### 1. Primitif pada ADT

Menurut modul, primitif dikelompokkan menjadi konstruktor (biasanya diawali Make), selector (diawali Get), prosedur pengubah nilai, validator, destruktor, baca/tulis, operator relasional, aritmatika, dan konversi tipe \[1\]. Notasi algoritma pada modul diterjemahkan ke bahasa C++ \[4\], sehingga primitif yang dipakai berupa fungsi dan prosedur biasa, misalnya `inputMhs` untuk membaca data dan `rata2` untuk menghitung nilai.

#### 2. Type dalam ADT

Di C++, type pada ADT ditulis memakai `struct`. Sebuah type juga boleh berisi type lain, misalnya ADT waktu yang terdiri dari ADT jam dan ADT tanggal \[1\].

### B. Pembagian File pada ADT

ADT biasanya dibuat dalam tiga bagian: file header (.h), file realisasi (.cpp), dan file driver atau main \[1\]. Pemisahan ini membuat program lebih rapi karena deklarasi dan isi fungsi tidak bercampur dengan program utama. Topik ADT juga menjadi bab pembuka pada buku struktur data berbahasa C++ karena materi lain seperti array dan linked list dibangun di atasnya \[3\].

#### 1. File Header (.h)

Berisi spesifikasi type dan deklarasi fungsi atau prosedur. Untuk mencegah file yang sama terbaca dua kali oleh compiler dipakai `#ifndef`, `#define`, dan `#endif` \[1\].

#### 2. File Realisasi (.cpp)

Berisi isi dari fungsi dan prosedur yang sudah dideklarasikan di header. Pada file ini header dipanggil dengan `#include "nama.h"` \[1\].

#### 3. File Main (Driver)

Berisi program utama yang memanggil primitif dari ADT. Selama header-nya di-include, main tidak perlu tahu isi fungsinya \[1\].

## Guided

### 1. \[Header - mahasiswa.h\]

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED
struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m);
float rata2 (mahasiswa m);
#endif
```

File ini menyimpan type `mahasiswa` yang punya tiga field, yaitu nim berupa array char dan dua nilai bertipe int. Di bawahnya ada deklarasi dua primitif, `inputMhs` untuk mengisi data dan `rata2` untuk menghitung rata-rata. Tanda `&` pada `inputMhs` dipakai supaya isi variabel aslinya yang berubah, bukan salinannya. Tiga baris `#ifndef`, `#define`, dan `#endif` menjaga agar header tidak terbaca dua kali.

### 2. \[Realisasi - mahasiswa.cpp\]

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input NIM = ";
    cin >> m.nim;

    cout << "Input Nilai 1 = ";
    cin >> m.nilai1;

    cout << "Input Nilai 2 = ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2) / 2;
}
```

Di sini isi dari dua fungsi pada header ditulis. `inputMhs` meminta pengguna mengetik NIM dan dua nilai, lalu menyimpannya ke field milik `m`. `rata2` menjumlahkan dua nilai lalu membaginya dengan 2. Hasil penjumlahan diubah dulu ke `float` supaya pembagiannya tidak dibulatkan, jadi 85 dan 86 menghasilkan 85.5, bukan 85.

### 3. \[Main - main.cpp\]

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main()
{
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata - rata = " << rata2 (mhs);
    return 0;
}
```

Main hanya membuat variabel `mhs` bertipe `mahasiswa`, memanggil `inputMhs` untuk mengisinya, lalu menampilkan hasil `rata2`. Karena `mahasiswa.h` sudah di-include, main bisa memakai type dan fungsinya tanpa tahu cara kerja di dalamnya. Saat dikompilasi, `main.cpp` dan `mahasiswa.cpp` harus ikut dibuild bersama.

## Unguided

### 1. Program yang menyimpan data mahasiswa (paling banyak 10) dalam array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir dihitung dengan fungsi: 0.3*uts + 0.4*uas + 0.3\*tugas.

```C++
#include <iostream>
#include <string>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    mahasiswa mhs[10];
    int n;

    do {
        cout << "Jumlah mahasiswa (1-10) : ";
        cin >> n;
    } while (n < 1 || n > 10);

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cin.ignore();
        cout << "Nama  : ";
        getline(cin, mhs[i].nama);
        cout << "NIM   : ";
        cin >> mhs[i].nim;
        cout << "UTS   : ";
        cin >> mhs[i].uts;
        cout << "UAS   : ";
        cin >> mhs[i].uas;
        cout << "Tugas : ";
        cin >> mhs[i].tugas;
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\nData Mahasiswa" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "UTS         : " << mhs[i].uts << endl;
        cout << "UAS         : " << mhs[i].uas << endl;
        cout << "Tugas       : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }
    return 0;
}
```

### Output Unguided 1 :

##### Output 1

!\[Screenshot Output Unguided 1_1\]([https://github.com/(username](https://github.com/%28username) github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Soal ini tidak meminta ADT, jadi semuanya ditulis dalam satu file. Data mahasiswa disimpan di struct `mahasiswa`, lalu dibuat array `mhs[10]` supaya muat sampai 10 orang. Jumlah data yang diinput dijaga lewat `do-while`, kalau angkanya di luar 1 sampai 10 maka program menanyakan ulang. Nilai akhir tidak dihitung langsung di main, tapi lewat fungsi `hitungNilaiAkhir` sesuai permintaan soal. `cin.ignore()` dipakai sebelum `getline` agar sisa enter dari input sebelumnya tidak membuat nama terlewat. Sebagai contoh, UTS 80, UAS 90, dan tugas 70 menghasilkan 24 + 36 + 21 = 81.

### 2. ADT pelajaran (pelajaran.h, pelajaran.cpp, main.cpp)

#### \[Header - pelajaran.h\]

```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);
#endif
```

#### \[Realisasi - pelajaran.cpp\]

```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

#### \[Main - main.cpp\]

```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "SDT";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

!\[Screenshot Output Unguided 2_1\]([https://github.com/(username](https://github.com/%28username) github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Soal kedua memakai konsep ADT seperti pada Guided, jadi dibagi jadi tiga file. Di `pelajaran.h` ada type `pelajaran` dengan dua field string, ditambah deklarasi `create_pelajaran` dan `tampil_pelajaran`. Fungsi `create_pelajaran` berperan sebagai konstruktor, ia menerima nama dan kode lalu mengembalikan satu data `pelajaran` yang sudah terisi. Prosedur `tampil_pelajaran` hanya mencetak isinya. Di `main.cpp` variabel `pel` dibuat lewat konstruktor, lalu ditampilkan. Tulisan "nilai :" pada output sengaja dibuat sama dengan contoh di modul, padahal yang tampil adalah kode mata kuliahnya, yaitu STD.

### 3. Program dengan 2 array 2D integer 3x3 dan 2 pointer integer, berisi fungsi menampilkan array, menukar isi dua array pada posisi tertentu, dan menukar isi variabel yang ditunjuk dua pointer.

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int a[3][3], int b[3][3], int baris, int kolom) {
    int temp = a[baris][kolom];
    a[baris][kolom] = b[baris][kolom];
    b[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int arrayA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arrayB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;
    int baris, kolom;

    cout << "Array A sebelum ditukar :" << endl;
    tampilArray(arrayA);
    cout << "\nArray B sebelum ditukar :" << endl;
    tampilArray(arrayB);

    cout << "\nMasukkan posisi yang ditukar (baris kolom, 0-2) : ";
    cin >> baris >> kolom;

    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        tukarArray(arrayA, arrayB, baris, kolom);
        cout << "\nArray A setelah ditukar :" << endl;
        tampilArray(arrayA);
        cout << "\nArray B setelah ditukar :" << endl;
        tampilArray(arrayB);
    } else {
        cout << "\nPosisi di luar batas array." << endl;
    }

    cout << "\nNilai x dan y sebelum ditukar : " << *p1 << " dan " << *p2 << endl;
    tukarPointer(p1, p2);
    cout << "Nilai x dan y setelah ditukar : " << *p1 << " dan " << *p2 << endl;

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

!\[Screenshot Output Unguided 3_1\]([https://github.com/(username](https://github.com/%28username) github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini memakai dua array 3x3 (`arrayA` dan `arrayB`) serta dua pointer `p1` dan `p2` yang menunjuk ke variabel `x` dan `y`. `tampilArray` mencetak isi array baris demi baris dengan dua `for`. `tukarArray` menukar satu elemen yang sama posisinya di kedua array, dan posisinya dipilih pengguna lewat input baris dan kolom. Kalau angka yang dimasukkan di luar 0 sampai 2, penukaran dibatalkan. Pada `tukarPointer`, yang ditukar adalah nilai yang ditunjuk (`*p1` dan `*p2`), jadi `x` dan `y` ikut berubah. Contohnya input `1 2` membuat elemen baris 1 kolom 2 bertukar, A jadi 4 dan B jadi 6 pada posisi itu, lalu x menjadi 20 dan y menjadi 10.

## Kesimpulan

Dari praktikum ini, ADT terbukti membuat program lebih teratur karena type dan primitifnya dipisah dari program utama. Header berisi deklarasi, file .cpp berisi isi fungsi, dan main tinggal memanggilnya. Pada soal pelajaran, konstruktor `create_pelajaran` jadi satu-satunya jalan membentuk data, sedangkan dua soal lain cukup satu file karena memang tidak membutuhkan ADT. Praktikum ini juga mengulang pemakaian array 2D dan pointer dari modul sebelumnya.

## Referensi

\[1\] Informatics Laboratory, Fakultas Informatika, Telkom University. Modul 3 Abstract Data Type (ADT), Modul Praktikum Struktur Data. Telkom University. \
\[2\] Liskov, B., & Zilles, S. (1974). "Programming with Abstract Data Types". ACM SIGPLAN Notices, 9(4), 50-59. Diakses melalui [https://doi.org/10.1145/942572.807045](https://doi.org/10.1145/942572.807045). \
\[3\] Rahman, S., Hartono, Joni, Dafitri, H., Tanjung, J. P., & Chiuloto, K. (2025). Struktur Data dan Algoritma: Pendekatan Visual dan Praktis dalam C++. Deli Serdang: Universitas Medan Area Press. Diakses melalui [https://phki-pghc.uma.ac.id/wp-content/uploads/2025/06/web-8.pdf](https://phki-pghc.uma.ac.id/wp-content/uploads/2025/06/web-8.pdf). \
\[4\] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses melalui [https://doi.org/10.21070/2020/978-623-6833-67-4](https://doi.org/10.21070/2020/978-623-6833-67-4).
