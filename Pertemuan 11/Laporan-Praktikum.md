# Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Fa'iq Jagadhita Hardiana
- **NIM**: 103112430015
- **Kelas**: 12-IF-05


## 2. Motivasi Belajar Struktur Data
tentunya karena harus lulus stuktur data biar lulus, dan mungkin agak semangat dikit belajar bahasa baru yaitu c++ ya walaupun susah di cerna di saya lebih tepatnya butuh waktu ibaratnya loading wakk bissmillah BISA BROKKK

## 3. Dasar Teori
Multi-linked list adalah jenis daftar khusus yang memiliki dua atau lebih urutan kunci logis. Sebelum memahami lebih jauh tentang multi-linked list, kita perlu melihat kembali apa itu linked list. Linked list adalah struktur data yang tidak memiliki batasan ukuran selama memori heap masih tersedia. Kita telah mengenal beberapa jenis linked list, seperti _Singly Linked List_, _Circular Linked List_, dan _Doubly Linked List_. Pada bagian ini, kita akan membahas mengenai multi-linked list.

## 4. Guided
### 4.1 multilist.h

```cpp
#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#define Nil NULL

typedef int infotype;
typedef struct elemen_induk *address_induk;
typedef struct elemen_anak *address_anak;

struct elemen_anak {
    infotype info;
    address_anak next, prev;
};

struct list_anak {
    address_anak first, last;
};

struct elemen_induk {
    infotype info;
    list_anak anak;
    address_induk next, prev;
};

struct list_induk {
    address_induk first, last;
};

void createList(list_induk &L);
address_induk alokasi(infotype x);
void insertLastInduk(list_induk &L, address_induk P);
address_induk findInduk(list_induk L, infotype x);
void insertLastAnak(list_anak &LA, address_anak PA);
address_anak alokasiAnak(infotype x);
void printInfo(list_induk L);

#endif
```

Penjelasan :

File multilist.h berfungsi sebagai pondasi utama yang mendefinisikan seluruh tipe data serta struktur yang digunakan dalam program. Di dalamnya terdapat deklarasi untuk node induk dan node anak, masing-masing dibangun sebagai doubly linked list dengan pointer next dan prev. File ini juga menetapkan struktur list untuk induk dan anak yang menyimpan penunjuk first dan last, sehingga memudahkan pengelolaan elemen. Selain itu, header ini berisi prototipe seluruh fungsi, mulai dari pembuatan list, alokasi node, hingga prosedur untuk menambah dan mencetak data. Dengan cara ini, file ini bertindak sebagai blueprint yang menyatukan seluruh komponen multilist dalam program.

### 4.2 multilist.cpp

```cpp
#include "multilist.h"
#include <iostream>
using namespace std;

void createList(list_induk &L) {
    L.first = Nil;
    L.last = Nil;
}

address_induk alokasi(infotype x) {
    address_induk P = new elemen_induk;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    P->anak.first = Nil;
    P->anak.last = Nil;
    return P;
}

void insertLastInduk(list_induk &L, address_induk P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

address_induk findInduk(list_induk L, infotype x) {
    address_induk P = L.first;
    while (P != Nil) {
        if (P->info == x) return P;
        P = P->next;
    }
    return Nil;
}
```

Penjelasan :

File multilist.cpp berisi implementasi fungsi-fungsi yang mengelola list induk. Fungsi createList menginisialisasi list induk dalam keadaan kosong, sementara alokasi membuat node induk baru dan sekaligus menyiapkan struktur list anak di dalamnya. Fungsi insertLastInduk memastikan setiap induk dapat ditambahkan ke akhir list menggunakan mekanisme doubly linked list. Ada juga fungsi findInduk, yang digunakan untuk mencari induk berdasarkan nilai tertentu. File ini secara keseluruhan menangani relasi tingkat pertama dalam multilist, yaitu hubungan antar node induk.

### 4.3 multilist_anak.cpp

```cpp
#include "multilist.h"
#include <iostream>
using namespace std;

address_anak alokasiAnak(infotype x) {
    address_anak P = new elemen_anak;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void insertLastAnak(list_anak &LA, address_anak PA) {
    if (LA.first == Nil) {
        LA.first = PA;
        LA.last = PA;
    } else {
        LA.last->next = PA;
        PA->prev = LA.last;
        LA.last = PA;
    }
}

void printInfo(list_induk L) {
    address_induk PI = L.first;
    while (PI != Nil) {
        cout << "Induk: " << PI->info << endl;
        address_anak PA = PI->anak.first;
        while (PA != Nil) {
            cout << "  Anak: " << PA->info << endl;
            PA = PA->next;
        }
        PI = PI->next;
    }
}
```

Penjelasan :

File multilist_anak.cpp mengimplementasikan fungsi yang berkaitan dengan pengelolaan list anak pada setiap induk. Di dalamnya terdapat fungsi alokasiAnak dan insertLastAnak, yang memungkinkan penambahan node anak secara berurutan. Selain itu, file ini juga menyediakan fungsi printInfo, yang tidak hanya mencetak data induk tetapi juga seluruh anak yang terhubung dengan masing-masing induk. Dengan demikian, file ini menjadi pengatur hubungan tingkat kedua dalam multilist, yakni struktur yang menangani kumpulan anak di bawah satu induk.

### 4.3 main.cpp

```cpp
#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    list_induk L;
    createList(L);

    address_induk P1 = alokasi(1);
    insertLastInduk(L, P1);

    address_anak PA1 = alokasiAnak(10);
    insertLastAnak(P1->anak, PA1);

    address_induk P2 = alokasi(2);
    insertLastInduk(L, P2);

    address_anak PA2 = alokasiAnak(20);
    insertLastAnak(P2->anak, PA2);

    printInfo(L);
    return 0;
}
```

Penjelasan :

File main.cpp berperan sebagai bagian eksekusi yang menjalankan seluruh fungsi yang telah didefinisikan sebelumnya. Dalam file ini, sebuah list induk dibuat terlebih dahulu, kemudian beberapa induk serta anak ditambahkan ke dalamnya. Setiap induk diberi daftar anak melalui pemanggilan fungsi insert, kemudian seluruh struktur dicetak menggunakan printInfo. File ini menunjukkan bagaimana setiap fungsi bekerja secara terpadu untuk membentuk struktur multilist yang mencerminkan hubungan induk-anak.

Ouput :

![](output/1.png)

## 5. Unguided
### 5.1 circularlist.h

```cpp
#ifndef CIRCULARLIST_H_INCLUDED
#define CIRCULARLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

// TIPE DATA
typedef struct {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
} infotype;

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

// FUNGSI / PROSEDUR
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);

void insertFirst(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteLast(List &L, address &P);

address findElm(List L, infotype x);
void printInfo(List L);

#endif

```

Penjelasan :

File circularlist.h menjadi dasar pembentukan struktur circular singly linked list dalam program. File ini mendefinisikan tipe data infotype yang menyimpan informasi mahasiswa, serta struktur node ElmList yang berisi data dan pointer next. Selain itu, terdapat struktur List yang menggunakan pointer first sebagai penanda awal list. Header ini juga mencantumkan prototipe seluruh operasi penting mulai dari pembuatan list, alokasi dan dealokasi node, penyisipan elemen pada tiga posisi berbeda, hingga penghapusan elemen dan fungsi pencarian. Melalui deklarasi-deklarasi tersebut, circularlist.h berperan sebagai blueprint yang mengatur bagaimana circular linked list akan dikelola dalam implementasi program.

### 5.2 circularlis.cpp

```cpp
#include "circularlist.h"

void createList(List &L){
    L.first = Nil;
}

address alokasi(infotype x){
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address P){
    delete P;
}

void insertFirst(List &L, address P){
    if(L.first == Nil){
        L.first = P;
        P->next = P;
    } else {
        address Q = L.first;
        while(Q->next != L.first){
            Q = Q->next;
        }
        Q->next = P;
        P->next = L.first;
        L.first = P;
    }
}

void insertAfter(List &L, address Prec, address P){
    if(Prec != Nil){
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P){
    if(L.first == Nil){
        insertFirst(L, P);
    } else {
        address Q = L.first;
        while(Q->next != L.first){
            Q = Q->next;
        }
        Q->next = P;
        P->next = L.first;
    }
}

void deleteFirst(List &L, address &P){
    P = L.first;

    if(P->next == P){     // 1 elemen
        L.first = Nil;
    } else {
        address Q = L.first;
        while(Q->next != L.first){
            Q = Q->next;
        }
        L.first = P->next;
        Q->next = L.first;
    }
    P->next = Nil;
}

void deleteAfter(List &L, address Prec, address &P){
    P = Prec->next;

    if(P != Nil){
        Prec->next = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P){
    if(L.first->next == L.first){   // satu elemen
        deleteFirst(L, P);
    } else {
        address Q = L.first;
        while(Q->next->next != L.first){
            Q = Q->next;
        }
        P = Q->next;
        Q->next = L.first;
        P->next = Nil;
    }
}

address findElm(List L, infotype x){
    if(L.first == Nil) return Nil;

    address P = L.first;
    do{
        if(P->info.nim == x.nim){
            return P;
        }
        P = P->next;
    } while(P != L.first);

    return Nil;
}

void printInfo(List L){
    if(L.first == Nil){
        cout << "List kosong" << endl;
        return;
    }

    address P = L.first;

    do {
        cout << "Nama : " << P->info.nama << endl;
        cout << "NIM  : " << P->info.nim << endl;
        cout << "L/P  : " << P->info.jenis_kelamin << endl;
        cout << "IPK  : " << P->info.ipk << endl;
        cout << endl;
        P = P->next;
    } while(P != L.first);
}

```

Penjelasan :

File circularlist.cpp memuat implementasi lengkap dari seluruh operasi pada circular singly linked list. Fungsi createList menyiapkan list kosong, sedangkan alokasi membangun node baru dengan data mahasiswa. Operasi penyisipan baik di awal, setelah node tertentu, maupun di akhir  dilakukan dengan tetap mempertahankan sifat sirkular list, di mana elemen terakhir selalu menunjuk kembali ke elemen pertama. Operasi penghapusan juga disesuaikan untuk menangani berbagai kondisi, termasuk ketika list hanya berisi satu elemen. Fungsi findElm memungkinkan pencarian berdasarkan NIM, sementara printInfo menampilkan seluruh elemen dengan menelusuri list hingga kembali ke node awal. Secara keseluruhan, file ini mengimplementasikan logika utama yang memastikan circular linked list dapat berjalan konsisten dan sesuai desain.

### 5.3 main.cpp

```cpp
#include <iostream>
#include "circularlist.h"
using namespace std;

address createData(string nama, string nim, char jenis_kelamin, float ipk)
{
    infotype x;
    address P;

    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;

    P = alokasi(x);
    return P;
}

int main(){
    List L;
    address P1, P2;
    infotype x;

    createList(L);

    cout << "coba insert first, last, dan after" << endl << endl;

    // dasar: tambah beberapa elemen dengan insertFirst / insertLast
    P1 = createData("Danu", "04", 'l', 4.0);
    insertFirst(L, P1);

    P1 = createData("Fahmi", "06", 'l', 3.45);
    insertLast(L, P1);

    P1 = createData("Bobi", "02", 'l', 3.71);
    insertFirst(L, P1);

    P1 = createData("Ali", "01", 'l', 3.3);
    insertFirst(L, P1);

    P1 = createData("Gita", "07", 'p', 3.75);
    insertLast(L, P1);

    // 1) masukkan Cindi (03) setelah NIM "02" (Bobi)
    x.nim = "02";
    P1 = findElm(L, x);            // cari Bobi
    P2 = createData("Cindi", "03", 'p', 3.5);
    insertAfter(L, P1, P2);

    // 2) masukkan Hilmi (08) setelah NIM "07" (Gita)  -> jadi berada di akhir sesuai gambar
    x.nim = "07";
    P1 = findElm(L, x);            // cari Gita
    P2 = createData("Hilmi", "08", 'p', 3.3);
    insertAfter(L, P1, P2);

    // 3) masukkan Eli (05) setelah NIM "04" (Danu)
    x.nim = "04";
    P1 = findElm(L, x);            // cari Danu
    P2 = createData("Eli", "05", 'p', 3.4);
    insertAfter(L, P1, P2);

    printInfo(L);
    return 0;
}

```

Penjelasan :

File main.cpp berfungsi sebagai bagian eksekusi yang mengintegrasikan seluruh fungsi dari circularlist.h. Pada file ini, list diinisialisasi dan beberapa data mahasiswa dibuat menggunakan createData sebelum dimasukkan ke dalam list. Proses penyusunan list dilakukan melalui kombinasi operasi insertFirst, insertLast, dan insertAfter, termasuk penyisipan berdasarkan elemen tertentu yang ditentukan melalui findElm. Setelah struktur list terbentuk sesuai kebutuhan, fungsi printInfo digunakan untuk menampilkan seluruh isi circular linked list. Dengan demikian, file ini menunjukkan alur penggunaan setiap operasi secara terstruktur dalam konteks aplikasi.

Output:

![](output/2.png)

## 6. Kesimpulan
 circular linked list pada program ini menunjukkan bagaimana struktur data dapat dikelola secara efisien melalui hubungan elemen yang tersusun melingkar. Pemisahan fungsi di setiap file membantu membangun alur kerja yang lebih terstruktur: _circularlist.h_ merancang tipe data serta prototipe fungsi, _circularlist.cpp_ mengisi logika manipulasi list, dan _main.cpp_ menguji seluruh operasi dalam konteks penggunaan nyata. Operasi dasar seperti penyisipan, penghapusan, pencarian, dan penelusuran dirancang untuk tetap mempertahankan karakter sirkular, sehingga elemen dapat diakses secara terus-menerus tanpa titik awal atau akhir yang tetap. Secara keseluruhan, implementasi ini menegaskan keunggulan circular linked list dalam hal fleksibilitas dan kestabilan, terutama untuk kebutuhan pengolahan data yang dinamis.
## 7. Referensi
1. https://www.geeksforgeeks.org/dsa/introduction-to-multi-linked-list/