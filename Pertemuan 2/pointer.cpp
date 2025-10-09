#include <iostream>

using namespace std;

int main () {
    float hargaProduk = 50000.0f;
    
    float* ptrHarga;
    ptrHarga = &hargaProduk;

    cout << "Harga Awal Produk : Rp" << hargaProduk <<endl;
    cout << "alamat memori harga:" << ptrHarga <<endl;

    cout << "\n..Memberikan diskon 20% melalui POinter..."<<endl;
    *ptrHarga = *ptrHarga * 0.8;
    cout << "Harga setelah diskon : Rp" << hargaProduk << endl;
    return 0;



}