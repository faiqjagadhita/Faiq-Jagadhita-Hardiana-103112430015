#include <iostream>

using namespace std;

int main() {
    int bukuPerHari[7]= {2,1,3,1,4,5,1};
    int totalBuku = 0;  

    cout << "Laporan Baca Buku Mingguan" << endl;

    for (int i = 0;i < 7; i++) {
        cout << "Hari ke-" << i + 1 <<":"<<bukuPerHari[i]
        <<"buku."<< endl;
        totalBuku += bukuPerHari[i];
    }
    cout << "totak buku yang dibaca minggu ini:" << totalBuku
    << "buku" << endl;
}