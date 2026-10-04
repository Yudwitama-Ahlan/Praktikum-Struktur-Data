# <h1 align="center">Laporan Praktikum Modul 2 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Yudwitama Ahlan Putra Hayuning Bawana - 109082530016</p>

## Dasar Teori

Array adalah kumpulan data bertipe sama yang memakai satu nama, dan setiap elemennya diambil lewat indeks yang mulai dari 0 [2]. Array bisa satu dimensi, dua dimensi seperti tabel, atau berdimensi banyak. String di C++ juga array, yaitu array karakter yang diakhiri '\0'. Pointer adalah variabel yang isinya alamat variabel lain [1]. Alamat diambil dengan &, dan isi variabel yang ditunjuk diambil dengan \*.

Fungsi adalah blok kode untuk tugas tertentu, sehingga program lebih rapi dan kode tidak ditulis berulang [2]. Fungsi mengembalikan nilai lewat return, sedangkan prosedur bertipe void dan tidak mengembalikan nilai. Parameter bisa dikirim dengan tiga cara. Call by value hanya mengirim salinan, sedangkan call by pointer dan call by reference membuat variabel asli ikut berubah.

## Guided

### 1. Array Satu Dimensi

```C++
#include <iostream>
using namespace std;

int main(){
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 85;
    nilai[2] = 90;
    nilai[3] = 75;
    nilai[4] = 95;

    for(int i = 0; i < 5; i++){
        cout << nilai[i] << endl;
    }

    return 0;
}
```

Array nilai dibuat untuk menyimpan lima bilangan bulat. Setiap data punya nomor indeks yang mulai dari 0, jadi data pertama ada di nilai[0] dan data terakhir ada di nilai[4]. Kelima elemen diisi satu per satu, lalu ditampilkan dengan perulangan for dari indeks 0 sampai 4. Outputnya angka 80, 85, 90, 75, dan 95, masing-masing satu baris.

### 2. Array Dua Dimensi

```C++
#include <iostream>
using namespace std;

int main(){
    int nilai[3][3] = {
        {80,85,90},
        {75,80,85},
        {90,95,100}
    };

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

Array dua dimensi mirip tabel. Indeks pertama untuk baris dan indeks kedua untuk kolom. Array nilai berukuran 3 x 3, jadi ada sembilan data yang langsung diisi saat array dibuat. Untuk menampilkannya dipakai dua perulangan. Perulangan luar (i) berjalan per baris, perulangan dalam (j) berjalan per kolom, dan endl dipakai untuk pindah baris. Hasilnya tiga baris, yaitu 80 85 90, 75 80 85, dan 90 95 100.

### 3. Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;

int main(){
    int data[2][3][3] = {
        {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        },
        {
            {10,11,12},
            {13,14,15},
            {16,17,18}
        }
    };

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                cout << data[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```

Array data[2][3][3] terdiri dari dua tabel 3 x 3, jadi isinya 18 elemen. Indeksnya ada tiga, maka perulangannya juga tiga. Perulangan i memilih tabel, j memilih baris, dan k memilih kolom. Setelah satu baris selesai program pindah baris, dan setelah satu tabel selesai ada satu baris kosong. Outputnya angka 1 sampai 9 untuk tabel pertama, lalu 10 sampai 18 untuk tabel kedua.

### 4. Array Empat Dimensi

```C++
#include <iostream>
using namespace std;

int main(){
    int data[2][2][2][2] = {

        {
            {
                {1,2},
                {3,4}
            },
            {
                {5,6},
                {7,8}
            }
        },
        {
            {
                {9,10},
                {11,12}
            },
            {
                {13,14},
                {15,16}
            }
        }
    };
    cout <<  data[0][0][0][0] << endl;
    cout <<  data[1][1][1][1] << endl;
}
```

Array ini punya empat indeks yang masing-masing berukuran 2, jadi isinya 16 elemen (2 x 2 x 2 x 2). Program tidak menampilkan semua elemen, hanya yang paling awal data[0][0][0][0] dan yang paling akhir data[1][1][1][1]. Outputnya 1 di baris pertama dan 16 di baris kedua.

### 5. Alamat Memori Variabel

```C++
#include <iostream>
using namespace std;

int main(){
    char a;
    int j;
    char arr[6];

    arr[3] = 'b';
    a = 'u';

    cout << a << endl;
    cout << &a << endl;

    cout << j << endl;
    cout << &j << endl;

    cout << &arr[4] << endl;

    return 0;
}
```

Setiap variabel memakai tempat di memori, dan alamatnya bisa dilihat dengan tanda & di depan nama variabel. Program ini menampilkan nilai dan alamat dari a, j, dan arr[4]. Baris pertama menampilkan huruf u. Variabel j belum diisi, jadi nilainya acak dan bisa berbeda di tiap komputer. Alamat j (&j) tampil dalam bentuk heksadesimal dan berubah setiap program dijalankan. Hasil &a dan &arr[4] berbeda dengan yang lain. Keduanya bertipe char\*, jadi cout menganggap alamat itu sebagai string dan menampilkan karakter dari sana sampai bertemu '\0'. Karena itu hasilnya bisa berupa karakter acak, tidak sama dengan alamat x6 dan x21 pada gambar di modul.

### 6. Pointer

```C++
#include <iostream>
using namespace std;

int main(){
    int x, y;
    int *px;

    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat x = " << &x << endl;
    cout << "Isi px = " << px << endl;
    cout << "Isi x = " << x << endl;
    cout << "Nilai yang ditunjuk px = " << *px << endl;
    cout << "Isi y = " << y << endl;

    return 0;
}
```

Pointer adalah variabel yang isinya alamat variabel lain. Di program ini px adalah pointer ke int dan diisi alamat x dengan px = &x. Tanda * di depan px (*px) dipakai untuk mengambil isi variabel yang ditunjuk, jadi y = \*px membuat y bernilai 87. Saat dijalankan, alamat x dan isi px sama karena px menyimpan alamat x (angkanya berbeda di tiap komputer). Tiga baris lain, yaitu isi x, nilai yang ditunjuk px, dan isi y, semuanya 87.

### 7. Input dan Tampilan Array Satu Dimensi dan Dua Dimensi

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main() {
    int i, j;
    float nilai_total, rata_rata;
    float nilai[MAX];

    static int nilai_tahun[MAX][MAX] = {
        {0, 2, 2, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 3, 3, 3, 0},
        {4, 4, 0, 0, 4},
        {5, 0, 0, 0, 5}
    };

    for (i = 0; i < MAX; i++) {
        cout << "masukan nilai ke- " << i + 1 << endl;
        cin >> nilai[i];
    }

    cout << "\ndata nilai siswa :\n";

    for (i = 0; i < MAX; i++)
        cout << "nilai ke- " << i + 1 << "=" << nilai[i] << endl;

    cout << "\n nilai tahunan :\n";

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++)
            cout << nilai_tahun[i][j];

        cout << "\n";
    }

    return 0;
}
```

MAX bernilai 5 dan dipakai sebagai ukuran array. Lima nilai pada array nilai diisi dari keyboard dengan cin, sedangkan nilai_tahun sudah berisi data sejak awal. Setelah input selesai, program menampilkan data nilai siswa dari nilai ke- 1 sampai nilai ke- 5, lalu menampilkan nilai_tahun sebagai tabel 5 x 5. Angka pada tabel tidak diberi spasi, jadi baris pertama tampil sebagai 02200. Variabel nilai_total dan rata_rata dibuat tetapi tidak dipakai di program ini.

### 8. String

```C++
#include <iostream>
using namespace std;

int main(){
    char nama[] = "strukdat";

    cout << nama << endl;
    cout << nama[3] << endl;

    return 0;
}
```

String di C++ adalah array karakter yang diakhiri '\0'. Karena nama diisi "strukdat", ukuran array otomatis 9, yaitu delapan huruf ditambah '\0'. Perintah cout << nama menampilkan seluruh kata strukdat, sedangkan nama[3] hanya mengambil satu huruf, yaitu u, karena indeks mulai dari 0 (s=0, t=1, r=2, u=3).

### 9. Fungsi

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c);

int main() {
    int x, y, z;

    cout << "masukkan nilai bilangan ke-1 = ";
    cin >> x;
    cout << "masukkan nilai bilangan ke-2 =";
    cin >> y;
    cout << "masukkan nilai bilangan ke-3 =";
    cin >> z;

    cout << "nilai maksimumnya adalah = " << maks3(x, y, z);

    return 0;
}

int maks3(int a, int b, int c) {
    int temp_max = a;

    if (b > temp_max)
        temp_max = b;

    if (c > temp_max)
        temp_max = c;

    return (temp_max);
}
```

maks3 adalah fungsi yang mengembalikan nilai, yaitu bilangan terbesar dari tiga bilangan. Mula-mula a dianggap paling besar dan disimpan di temp_max. Jika b lebih besar, temp_max diganti b, dan hal yang sama berlaku untuk c. Hasil akhirnya dikembalikan ke main dengan return. Prototype fungsi ditulis di atas main supaya maks3 sudah dikenal sebelum dipanggil. Contohnya, jika input 10, 25, dan 15, maka yang tampil adalah 25 sebagai bilangan terbesar.

### 10. Prosedur

```C++
#include <iostream>
using namespace std;

void tulis(int x);

int main() {
    int jum;

    cout << "jumlah baris kata = ";
    cin >> jum;

    tulis(jum);

    return 0;
}

void tulis(int x) {
    for (int i = 0; i < x; i++)
        cout << "baris ke-" << i + 1 << endl;
}
```

Prosedur mirip fungsi, tetapi bertipe void sehingga tidak mengembalikan nilai. Prosedur tulis menerima x, lalu menampilkan kalimat "baris ke-" sebanyak x kali dengan perulangan for. Karena i mulai dari 0, yang ditampilkan adalah i + 1 supaya nomor baris mulai dari 1. Jika pengguna mengetik 3, hasilnya baris ke-1, baris ke-2, dan baris ke-3.

### 11. Call by Value, Call by Pointer, dan Call by Reference

```C++
#include <iostream>
using namespace std;

void tukarValue(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void tukarPointer(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void tukarReference(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 4, b = 6;

    tukarValue(a, b);
    cout << "Setelah Call by Value     -> a = " << a << ", b = " << b << " (Tetap)" << endl;

    tukarPointer(&a, &b);
    cout << "Setelah Call by Pointer   -> a = " << a << ", b = " << b << " (Berubah!)" << endl;

    tukarReference(a, b);
    cout << "Setelah Call by Reference -> a = " << a << ", b = " << b << " (Berubah lagi!)" << endl;

    return 0;
}
```

Ketiga fungsi di program ini sama-sama menukar dua angka, tetapi cara menerima data berbeda. Pada call by value, fungsi hanya menerima salinan, jadi yang tertukar hanya x dan y milik fungsi, sedangkan a dan b di main tidak berubah. Pada call by pointer, yang dikirim adalah alamat (&a dan &b), jadi fungsi bisa mengubah a dan b langsung lewat *x dan *y. Call by reference hasilnya sama, tetapi penulisannya lebih singkat karena parameter cukup diberi & dan pemanggilannya tetap tukarReference(a, b). Dari output, a dan b yang awalnya 4 dan 6 tetap 4 dan 6 setelah call by value, menjadi 6 dan 4 setelah call by pointer, lalu kembali menjadi 4 dan 6 setelah ditukar lagi dengan call by reference.

## Unguided

### 1. Membuat program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
#include <iostream>
#define MAX 3
using namespace std;

int main() {
    int A[MAX][MAX], B[MAX][MAX], hasil[MAX][MAX];
    int i, j, k;

    cout << "Masukkan elemen matriks A :" << endl;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\nMasukkan elemen matriks B :" << endl;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    cout << "\nHasil Penjumlahan (A + B) :" << endl;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan (A - B) :" << endl;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian (A x B) :" << endl;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            hasil[i][j] = 0;
            for (k = 0; k < MAX; k++) {
                hasil[i][j] = hasil[i][j] + A[i][k] * B[k][j];
            }
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/Yudwitama-Ahlan/Praktikum-Struktur-Data/blob/main/01-10-2026/Output/Unguided-One.png)

Matriks A, B, dan hasil sama-sama array 3 x 3. Isi A dan B diinput dengan perulangan for bersarang. Penjumlahan dan pengurangan dilakukan per elemen, jadi hasil[i][j] didapat dari A[i][j] dan B[i][j] di posisi yang sama. Perkalian sedikit berbeda. Satu elemen hasil didapat dari baris ke-i milik A dikali kolom ke-j milik B lalu dijumlah, dan ini dilakukan oleh perulangan k. Sebagai contoh, jika A berisi 1 sampai 9 dan B berisi 9 sampai 1 (berurutan per baris), hasil penjumlahan adalah 10 di semua elemen. Hasil pengurangan adalah -8 -6 -4, -2 0 2, dan 4 6 8, sedangkan hasil perkalian adalah 30 24 18, 84 69 54, dan 138 114 90.

### 2. Membuat program pointer dan reference yang dapat menukar nilai dari 3 variabel

```C++
#include <iostream>
using namespace std;

void tukarPointer(int *x, int *y, int *z)
{
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukarReference(int &x, int &y, int &z)
{
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main()
{
    int a = 4, b = 6, c = 8;

    cout << "Sebelum ditukar : a = " << a << ", b = " << b << ", c = " << c << endl;
    tukarPointer(&a, &b, &c);
    cout << "Setelah Call by Pointer   : a = " << a << ", b = " << b << ", c = " << c << endl;

    a = 4;
    b = 6;
    c = 8;

    cout << "\nSebelum ditukar : a = " << a << ", b = " << b << ", c = " << c << endl;
    tukarReference(a, b, c);
    cout << "Setelah Call by Reference : a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}
```

### Output Unguided 2 :

![Screenshot Output Unguided 2_2](https://github.com/Yudwitama-Ahlan/Praktikum-Struktur-Data/blob/main/01-10-2026/Output/Unguided-Two.png)

Soal ini melanjutkan guided sebelumnya, hanya saja variabel yang ditukar ada tiga. Pada tukarPointer, alamat a, b, dan c dikirim ke fungsi dan isinya diubah lewat *x, *y, dan \*z. Pada tukarReference, x, y, dan z adalah nama lain dari a, b, dan c karena parameternya memakai &. Cara menukarnya sama di kedua fungsi. Nilai x disimpan dulu di temp, x diisi nilai y, y diisi nilai z, lalu z diisi nilai temp. Dengan a = 4, b = 6, dan c = 8, hasilnya a = 6, b = 8, dan c = 4. Sebelum call by reference, nilai dikembalikan ke 4, 6, 8 supaya kedua cara dimulai dari kondisi yang sama. Hasilnya pun sama.

### 3. Membuat program menu untuk mencari nilai minimum, maksimum, dan rata-rata dari array

```C++
#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n);
int cariMaksimum(int arr[], int n);
void hitungRataRata(int arr[], int n);

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata - rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Isi array : ";
            for (int i = 0; i < 10; i++) {
                cout << arrA[i] << " ";
            }
            cout << endl;
            break;
        case 2:
            cout << "Nilai maksimum = " << cariMaksimum(arrA, 10) << endl;
            break;
        case 3:
            cout << "Nilai minimum = " << cariMinimum(arrA, 10) << endl;
            break;
        case 4:
            hitungRataRata(arrA, 10);
            break;
        case 5:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia." << endl;
        }
    } while (pilihan != 5);

    return 0;
}

int cariMinimum(int arr[], int n) {
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

int cariMaksimum(int arr[], int n) {
    int maks = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maks)
            maks = arr[i];
    }

    return maks;
}

void hitungRataRata(int arr[], int n) {
    float total = 0;
    float rata_rata;

    for (int i = 0; i < n; i++) {
        total = total + arr[i];
    }

    rata_rata = total / n;
    cout << "Nilai rata - rata = " << rata_rata << endl;
}
```

### Output Unguided 3 :

![Screenshot Output Unguided 3_1](https://github.com/Yudwitama-Ahlan/Praktikum-Struktur-Data/blob/main/01-10-2026/Output/Unguided-Three.png)

Data disimpan di array arrA. Menu dibuat dengan switch-case di dalam do-while, jadi bisa dipilih berkali-kali sampai pengguna memilih 5. Opsi Keluar ini tambahan karena soal hanya menyebut empat menu. cariMaksimum() dan cariMinimum() mengembalikan nilai int. Keduanya mengambil elemen pertama sebagai patokan, lalu memeriksa elemen lain satu per satu dan mengganti patokan jika ada yang lebih besar (atau lebih kecil pada cariMinimum). hitungRataRata() adalah prosedur void, jadi hasilnya langsung ditampilkan di dalamnya, bukan dikembalikan. Semua elemen dijumlah (totalnya 214) lalu dibagi 10. Untuk pilihan 1 tampil 11 8 5 7 12 26 3 54 33 55, pilihan 2 menampilkan 55 sebagai nilai terbesar, pilihan 3 menampilkan 3 sebagai nilai terkecil, dan pilihan 4 menampilkan rata-rata 21.4.

## Kesimpulan

Praktikum Modul 2 ini membahas array, pointer, fungsi, dan prosedur. Array menyimpan banyak data dalam satu nama, pointer menyimpan alamat variabel, dan fungsi atau prosedur memecah program menjadi bagian kecil. Pada percobaan menukar nilai, call by value tidak mengubah variabel asli, sedangkan call by pointer dan call by reference mengubahnya. Semua konsep itu dipakai pada latihan mandiri, yaitu operasi matriks, penukaran tiga variabel, dan program menu array.

## Referensi

[1] Ma'arif, A. (2020). Buku Ajar Dasar Pemrograman C++. Universitas Ahmad Dahlan. Isinya mencakup array, fungsi, dan pointer https://eprints.uad.ac.id/32726/
