# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Yudwitama Ahlan Putra Hayuning Bawana - 109082530016</p>

## Dasar Teori

### A. Struktur Dasar dan Tipe Data pada Bahasa C++<br/>

Bahasa C++ merupakan bahasa pemrograman hasil pengembangan dari bahasa C yang ditambahkan fasilitas kelas, sehingga pada awalnya disebut "C with class". Setiap program C++ selalu memiliki fungsi utama bernama main() yang menjadi titik awal eksekusi program, serta dapat memiliki fungsi-fungsi lain yang dideklarasikan secara terpisah. Untuk dapat menyimpan suatu nilai, program membutuhkan variabel dan konstanta yang penamaannya harus mengikuti aturan identifier, misalnya harus diawali huruf atau garis bawah dan tidak boleh mengandung spasi. Setiap variabel juga wajib memiliki tipe data yang menentukan jenis nilai serta ukuran memori yang dipakai, seperti int untuk bilangan bulat, float dan double untuk bilangan pecahan, serta char untuk karakter.

#### 1. Identifier merupakan aturan penamaan untuk variabel, konstanta, maupun fungsi agar dapat dibedakan satu sama lain.

#### 2. Tipe data dasar terdiri atas bilangan bulat, bilangan real presisi tunggal maupun ganda, karakter, dan tipe tak bertipe (void).

#### 3. Variabel dapat diberi nilai awal (inisialisasi) pada saat dideklarasikan, sedangkan konstanta menyimpan nilai yang sifatnya tetap selama program berjalan.

### B. Operator, Struktur Kondisional, dan Perulangan<br/>

Operator digunakan untuk melakukan suatu operasi atau manipulasi terhadap data, mulai dari operator aritmatika, operator pengerjaan (assignment), operator logika, hingga operator kondisional. Selain operator, program juga membutuhkan struktur kondisional seperti if, if-else, dan switch untuk mengambil keputusan berdasarkan suatu kondisi bernilai benar atau salah. Untuk pekerjaan yang berulang, C++ menyediakan struktur perulangan for, while, dan do-while yang masing-masing memiliki kondisi berhenti agar proses eksekusi tidak berjalan tanpa batas.

#### 1. Operator aritmatika digunakan untuk operasi perhitungan seperti penjumlahan, pengurangan, perkalian, pembagian, dan sisa bagi.

#### 2. Struktur kondisional (if, if-else, switch) digunakan untuk menentukan alur program berdasarkan suatu kondisi tertentu.

#### 3. Struktur perulangan (for, while, do-while) digunakan untuk mengeksekusi sekumpulan pernyataan secara berulang selama kondisi masih terpenuhi.

## Guided

### 1. Program Fungsi cout()

```C++
#include <iostream>
using namespace std;

int main(){
    cout << "saya lagi belajar bahasa c++ nih!!!" << endl;
    return 0;
}
```

Program ini mencoba fungsi cout() untuk mencetak teks ke layar. Teks yang mau dicetak ditulis di antara tanda kutip ganda, lalu dikirim ke cout memakai operator "<<". Di akhir baris ditambahkan endl yang fungsinya pindah baris (sama seperti menekan enter), supaya kalau ada cout lagi setelahnya, tulisannya tidak nempel di baris yang sama.

### 2. Program Fungsi cin()

```C++
#include <iostream>
using namespace std;

int main(){
    int inp;
    cin >> inp;
    cout << "nilai =" << inp;
    return 0;
}
```

Program ini mencoba fungsi cin() untuk membaca angka yang diketik user lewat keyboard. Nilai yang diketik langsung masuk ke variabel inp memakai operator ">>" (arah panahnya menunjukkan nilai masuk ke dalam variabel). Setelah itu, nilai inp tinggal dicetak kembali pakai cout supaya kelihatan bahwa program benar-benar sudah menyimpan angka yang diinput.

### 3. Program Operator Aritmatika

```C++
#include <iostream>
using namespace std;

int main(){
    int W,X,Y; float Z;
    X=7; Y=3; W=1;
    Z=(X+Y)/(Y+W);
    cout << "nilai Z =" << Z << endl;
    return 0;
}
```

Program ini mencoba operator aritmatika, dimana X, Y, dan W diberi nilai langsung di dalam kode (bukan lewat input), lalu dihitung dengan rumus (X+Y)/(Y+W). Karena X, Y, dan W semuanya bertipe int, pembagian antar bilangan bulat dibulatkan ke bawah, jadi hasil (7+3)/(3+1) = 10/4 yang secara matematika 2.5, dibulatkan turun jadi 2. Nilai 2 itu baru kemudian dipindahkan ke Z yang bertipe float, sehingga yang tercetak di layar adalah "nilai Z =2", bukan 2.5, karena pembulatannya sudah terjadi lebih dulu sebelum hasilnya sempat disimpan sebagai desimal. Ini jadi pelajaran penting: kalau mau hasil bagi yang presisi (ada desimalnya), minimal salah satu dari operand yang dibagi harus bertipe float atau double sejak awal, bukan cuma variabel penampung hasilnya saja.

## Unguided

### 1. Buatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
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
```

### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/Yazeelime/Praktikum-Struktur-Data/blob/main/27-09-2026/Run/Unguided-One.png)

Program ini pertama-tama meminta user memasukkan dua bilangan bertipe float lewat cin, lalu keduanya disimpan di variabel bil1 dan bil2. Setelah itu, keempat operasi (+, -, \*, /) langsung dikerjakan di dalam cout, jadi tidak perlu disimpan dulu ke variabel baru, cukup dihitung langsung saat dicetak. Dipilih tipe float karena soal meminta input berupa bilangan pecahan (desimal), bukan bilangan bulat, sehingga hasil pembagian pun tetap bisa menghasilkan angka desimal yang akurat.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100.

```C++
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
```

### Output Unguided 2 :

![Screenshot Output Unguided 2_1](https://github.com/Yazeelime/Praktikum-Struktur-Data/blob/main/27-09-2026/Run/Unguided-Two.png)

Cara berpikirnya adalah memecah angka menjadi kasus-kasus kecil yang mudah dicek satu per satu pakai if-else berantai. Angka 0 dan 100 dicek langsung sebagai kasus khusus karena penyebutannya unik ("nol" dan "seratus"). Angka 1 sampai 9 diambil langsung dari array satuan. Angka 10 dan 11 juga dibuat kasus khusus karena penyebutannya tidak mengikuti pola ("sepuluh" dan "sebelas", bukan "satu belas"). Untuk angka 12 sampai 19, polanya adalah kata satuan ditambah "belas", misalnya 15 diambil dari satuan[15-10] yaitu satuan[5] = "lima", lalu ditambah kata "belas" jadi "lima belas". Untuk angka 20 ke atas, angka dibagi 10 (operator /) untuk mendapatkan angka puluhan, dan sisa baginya dicari dengan operator % untuk mendapatkan angka satuan di belakang, contohnya 79 dibagi 10 hasilnya 7 (puluh) dan sisa baginya 9 (satuan), sehingga digabung jadi "tujuh puluh sembilan".

### 3. Buatlah program yang dapat memberikan input dan output seperti pada Gambar 1.25 (Mirror).

```C++
#include <iostream>
using namespace std;

int main(){
    int n;

    cout << "input: ";
    cin >> n;
    cout << "output:" << endl;

    for(int baris = n; baris >= 0; baris--){
        int jumlahSpasi = (n - baris) * 2;

        for(int s = 0; s < jumlahSpasi; s++){
            cout << " ";
        }
        for(int kiri = baris; kiri >= 1; kiri--){
            cout << kiri << " ";
        }
        cout << "*";
        for(int kanan = 1; kanan <= baris; kanan++){
            cout << " " << kanan;
        }
        cout << endl;
    }

    return 0;
}
```

### Output Unguided 3 :

![Screenshot Output Unguided 3_1](https://github.com/Yazeelime/Praktikum-Struktur-Data/blob/main/27-09-2026/Run/Unguided-Three.png)

Program ini pakai perulangan for yang bersarang (nested for) sebanyak tiga lapis di dalam satu perulangan for utama. Variabel baris berjalan mundur dari n sampai 0, jadi setiap kali satu baris selesai dicetak, jumlah angka yang tampil berkurang satu. Untuk tiap baris, jumlah spasi di depan dihitung dari (n - baris) _ 2, sehingga makin ke bawah baris makin bergeser ke kanan, itulah yang membuat bentuknya seperti cermin (mirror) yang miring. Setelah spasi, perulangan kedua mencetak angka menurun dari nilai baris sampai 1 (sisi kiri tanda bintang), lalu tanda "_" dicetak sebagai pusat/sumbu cerminnya, dan perulangan ketiga mencetak angka naik dari 1 sampai baris (sisi kanan tanda bintang). Karena sisi kiri dan kanan sama-sama berjalan dari baris yang sama tapi arahnya berlawanan (turun lalu naik), hasilnya simetris seperti bayangan cermin terhadap tanda bintang di tengah.

## Kesimpulan

Dari praktikum modul 1 ini, dapat disimpulkan bahwa dasar-dasar bahasa pemrograman C++ seperti tipe data, variabel, operator, struktur kondisional, dan perulangan merupakan fondasi yang harus dipahami sebelum masuk ke materi struktur data yang lebih kompleks. Melalui latihan unguided, terlihat bahwa satu konsep dasar bisa dipakai untuk menyelesaikan berbagai jenis persoalan, mulai dari operasi aritmatika sederhana pada soal 1, penggunaan if-else berantai untuk memetakan angka ke bentuk tulisan pada soal 2, hingga kombinasi perulangan bersarang untuk membentuk suatu pola cetak pada soal 3. Hal ini menunjukkan bahwa penguasaan logika dasar seperti percabangan dan perulangan sangat menentukan kemampuan menyelesaikan soal pemrograman yang lebih rumit di kemudian hari.

## Referensi

[1] Informatics Laboratory. (2026). *Modul 1: Code Blocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)*. Bandung: Fakultas Informatika, Telkom University.
