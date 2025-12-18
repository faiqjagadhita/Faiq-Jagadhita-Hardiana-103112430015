# Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Fa'iq Jagadhita Hardiana
- **NIM**: 103112430015
- **Kelas**: 12-IF-05

## 2. Motivasi Belajar Struktur Data
tentunya karena harus lulus stuktur data biar lulus, dan mungkin agak semangat dikit belajar bahasa baru yaitu c++ ya walaupun susah di cerna di saya lebih tepatnya butuh waktu ibaratnya loading wakk bissmillah BISA BROKKK
## 3. Dasar Teori
Teori graf adalah cabang matematika yang mempelajari sifat-sifat dan aplikasi graf. Graf mendefinisikan kumpulan objek yang disebut simpul (atau node) yang dihubungkan oleh sisi (atau tautan). 

Tujuan utama teori graf adalah untuk memahami struktur graf-graf tersebut dan mengeksplorasi berbagai masalah yang berkaitan dengan konektivitas, pencarian jalur, dan optimasi jaringan.

Dengan menganalisis hubungan-hubungan ini, teori graf memungkinkan kita untuk memperoleh wawasan tentang berbagai masalah dunia nyata di berbagai bidang.

## 4. Guided
### 4.1 header 

```cpp
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode{
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge{
    adrNode node;
    adrEdge next;
};

struct Graph{
    adrNode first;
};

// Prototypes
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
```

Penjelasan :

File graph.h adalah kerangka utama ADT Graph. Di sini semua struktur data dan deklarasi fungsi didefinisikan. Tipe infoGraph dibuat sebagai char, jadi setiap node di graph direpresentasikan oleh satu huruf, misalnya A, B, atau C. Struct ElmNode adalah representasi node. Di dalamnya ada info sebagai isi node, visited sebagai penanda jika nanti dipakai traversal, firstEdge untuk menunjuk ke daftar edge milik node tersebut, dan next untuk menghubungkan node satu dengan node lain dalam bentuk linked list. Struct ElmEdge berfungsi sebagai edge atau penghubung antar node. Edge ini menyimpan alamat node tujuan dan pointer ke edge berikutnya. Dengan konsep ini, satu node bisa punya banyak edge. Struct Graph hanya punya satu pointer first yang berfungsi sebagai head graph, yaitu titik awal untuk mengakses seluruh node. Di bagian bawah, terdapat prototype fungsi agar bisa digunakan di file lain.

### 4.2 Graph_init

```cpp
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q -> next;
        }
        Q->next = P;
    }
}
```

Penjelasan :

File ini berisi fungsi-fungsi untuk inisialisasi graph dan node. Fungsi createGraph digunakan untuk membuat graph kosong dengan cara mengatur first menjadi NULL. Ini menandakan graph belum memiliki node sama sekali. Fungsi allocateNode bertugas membuat node baru. Saat node dibuat, nilainya diisi, status visited diset false, dan pointer firstEdge serta next diset NULL. Artinya node baru belum terhubung ke node mana pun. Fungsi insertNode digunakan untuk memasukkan node ke dalam graph. Jika graph masih kosong, node langsung menjadi node pertama. Jika sudah ada node, maka node baru ditambahkan di bagian paling akhir dari daftar node.

### 4.3 Graph_egde

```cpp
#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge; // Insert First di list edge
        pStart->firstEdge = newEdge;
    }
}
```

Penjelasan :

File ini fokus pada hubungan antar node. Fungsi findNode digunakan untuk mencari node tertentu berdasarkan hurufnya. Program akan menelusuri node dari awal sampai ketemu atau sampai habis. Fungsi connectNode berfungsi untuk menghubungkan dua node. Node awal dan node tujuan dicari terlebih dahulu. Jika keduanya ditemukan, maka dibuat edge baru yang menunjuk ke node tujuan dan dimasukkan ke daftar edge node awal. Hubungan ini bersifat satu arah, dari start ke end

### 4.4 Graph_Print

```cpp
#include "graph.h"

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
```

Penjelasan :

File graph_print.cpp berisi fungsi untuk menampilkan isi graph. Fungsi printGraph akan menelusuri setiap node satu per satu. Untuk setiap node, program mencetak node tersebut terhubung ke node mana saja. Edge dibaca dari firstEdge sampai habis, lalu nama node tujuan ditampilkan. Dengan cara ini, struktur graph bisa dilihat langsung lewat output terminal.
### 4.5 main

```cpp
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    // Menambahkan Node A, B, C, D
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // Menghubungkan Node (Sesuai contoh materi)
    connectNode(G, 'A', 'B'); // A ke B
    connectNode(G, 'A', 'C'); // A ke C
    connectNode(G, 'B', 'D'); // B ke D
    connectNode(G, 'C', 'D'); // C ke D

    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```

Penjelasan :

File main.cpp adalah pengendali utama program. Di sini graph dibuat dan diinisialisasi terlebih dahulu. Setelah itu, node A, B, C, dan D dimasukkan ke dalam graph. Selanjutnya, node-node tersebut dihubungkan sesuai contoh, yaitu A ke B, A ke C, B ke D, dan C ke D. Terakhir, isi graph ditampilkan ke layar menggunakan fungsi printGraph, lalu program selesai dijalankan.

Output :

![](output/1.png)


## 5. Unguided

### 5.1 graph_unguided.h

```cpp
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

// Prototype
void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(Graph &G, infoGraph X, infoGraph Y);
void PrintInfoGraph(Graph G);

#endif

```

Penjelasan :

File graph_unguided.h berisi definisi utama dari ADT Graph tidak berarah. Di dalamnya terdapat struktur Graph yang memiliki pointer first sebagai head graph, yaitu titik awal untuk mengakses seluruh node. Setiap node direpresentasikan oleh ElmNode yang menyimpan data berupa huruf, penanda visited, pointer ke daftar edge (firstEdge), dan pointer next untuk menghubungkan node satu dengan node lainnya. Hubungan antar node disimpan menggunakan ElmEdge yang menunjuk ke node tujuan dan edge berikutnya, sehingga satu node bisa terhubung ke banyak node. Di file ini juga dideklarasikan prototype fungsi agar bisa digunakan di file lain.

### 5.2 Graph_unguided.cpp

```cpp
#include "graph_unguided.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph X, infoGraph Y) {
    adrNode N1 = FindNode(G, X);
    adrNode N2 = FindNode(G, Y);

    if (N1 != NULL && N2 != NULL) {
        // Edge dari X ke Y
        adrEdge E1 = new ElmEdge;
        E1->node = N2;
        E1->next = N1->firstEdge;
        N1->firstEdge = E1;

        // Edge dari Y ke X (karena tidak berarah)
        adrEdge E2 = new ElmEdge;
        E2->node = N1;
        E2->next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

```

Penjelasan :

File graph_unguided.cpp berisi implementasi dari semua fungsi ADT Graph. Fungsi CreateGraph digunakan untuk menginisialisasi graph agar kosong, AllocateNode untuk membuat node baru dengan kondisi awal yang aman, dan InsertNode untuk menambahkan node ke dalam graph. Fungsi FindNode digunakan untuk mencari node tertentu, sedangkan ConnectNode berfungsi menghubungkan dua node secara dua arah karena graph bersifat tidak berarah. Selain itu, terdapat fungsi PrintInfoGraph yang digunakan untuk menampilkan seluruh isi graph beserta hubungan antar nodenya.

### 5.3 mainunguided1.cpp

```cpp
#include "graph_unguided.h"

int main() {
    Graph G;
    CreateGraph(G);

    // Insert node A sampai H
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    // Hubungan sesuai ilustrasi graph
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'G');
    ConnectNode(G, 'D', 'H');
    ConnectNode(G, 'E', 'H');
    ConnectNode(G, 'F', 'H');
    ConnectNode(G, 'G', 'H');

    cout << "Isi Graph Tidak Berarah:" << endl;
    PrintInfoGraph(G);

    return 0;
}

```

Penjelasan :

File mainunguided1.cpp merupakan bagian utama program yang digunakan untuk menguji ADT Graph. Program dimulai dengan membuat graph kosong, kemudian memasukkan node A sampai H ke dalam graph. Setelah itu, node-node tersebut dihubungkan sesuai ilustrasi graph pada soal menggunakan fungsi ConnectNode. Terakhir, fungsi PrintInfoGraph dipanggil untuk menampilkan struktur graph ke layar, sehingga dapat dilihat apakah graph sudah terbentuk dengan benar.

Output:

![](output/2.png)

### 5.4 DFS & BFS

tambahin ini di graph_unguided.h

```cpp
void ResetVisited(Graph &G);
void PrintDFS(Graph &G, adrNode N);
void PrintBFS(Graph &G, adrNode N);
```

Penjelasan :

Pada file graph_unguided.h , tidak ada perubahan struktur graph, karena ADT nomor 1 sebenarnya sudah siap untuk DFS dan BFS. Atribut visited pada ElmNode sudah tersedia dan memang digunakan untuk menandai node yang sudah dikunjungi saat penelusuran. Yang ditambahkan di file ini hanyalah deklarasi prosedur baru, yaitu ResetVisited, PrintDFS, dan PrintBFS, agar fungsi-fungsi penelusuran bisa dipanggil dari main dan dikenali oleh compiler.


tambahin ini juga di graph_unguided.cpp

```cpp
void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

void PrintDFS(Graph &G, adrNode N) {
    if (N == NULL || N->visited == 1)
        return;

    cout << N->info << " ";
    N->visited = 1;

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->node);
        E = E->next;
    }
}

#include <queue>

void PrintBFS(Graph &G, adrNode N) {
    if (N == NULL)
        return;

    queue<adrNode> Q;
    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}


```

Penjelasan :

File graph_unguided.cpp ditambahkan implementasi prosedur penelusuran graph. Prosedur ResetVisited berfungsi untuk mengatur ulang status kunjungan semua node sebelum DFS atau BFS dijalankan. Prosedur PrintDFS melakukan penelusuran graph dengan cara masuk sedalam mungkin ke satu jalur terlebih dahulu menggunakan rekursif, sedangkan PrintBFS melakukan penelusuran secara melebar berdasarkan tingkat menggunakan struktur antrian. Semua prosedur ini memanfaatkan atribut visited agar node tidak dikunjungi lebih dari satu kali.


tambahin ini juga di mainnya 

```cpp
cout << "DFS dari node A: ";
ResetVisited(G);
PrintDFS(G, FindNode(G, 'A'));
cout << endl;

cout << "BFS dari node A: ";
ResetVisited(G);
PrintBFS(G, FindNode(G, 'A'));
cout << endl;

```

Penjelasan :

Pada file mainunguided1.cpp, struktur graph tetap sama seperti nomor 1 dan tidak mengalami perubahan. Yang ditambahkan hanyalah pemanggilan prosedur DFS dan BFS setelah graph selesai dibentuk. Sebelum masing-masing penelusuran dilakukan, prosedur ResetVisited dipanggil agar hasil penelusuran tidak saling memengaruhi. Hasil DFS dan BFS kemudian langsung ditampilkan ke layar sesuai node awal yang dipilih.

Output:

![](output/3.png)
## 6. Kesimpulan
Secara keseluruhan, pada nomor 1 dibuat sebuah ADT Graph tidak berarah menggunakan adjacency list yang berfungsi untuk menyimpan node dan hubungan antar node dengan rapi dan terstruktur. Graph ini menjadi dasar utama tempat data disimpan. Pada nomor 2 dan 3, graph tersebut dikembangkan agar tidak hanya bisa menyimpan dan menampilkan data, tetapi juga bisa ditelusuri menggunakan dua metode berbeda, yaitu DFS dan BFS. DFS digunakan untuk menelusuri graph dengan cara masuk sedalam mungkin ke satu jalur terlebih dahulu, sedangkan BFS menelusuri graph secara melebar berdasarkan tingkat kedekatan node. bagusnya ya, untuk menambahkan DFS dan BFS tidak perlu mengubah struktur dasar graph, cukup memanfaatkan atribut visited dan menambahkan beberapa prosedur penelusuran, sehingga desain ADT tetap sederhana, fleksibel, dan mudah dikembangkan.

## 7. Referensi
1. https://www.datacamp.com/tutorial/introduction-to-graph-theory