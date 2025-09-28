#include <iostream>
using namespace std;

int main() {
    double a, b;
    double tambah, kurang, kali, bagi;

    cout << "Masukkan dua angka (dipisah spasi): ";
    cin >> a >> b;

    tambah = a + b;
    kurang = a - b;
    kali   = a * b;
    bagi   = a / b;  

    cout << "Hasil penjumlahan: " << tambah << endl;
    cout << "Hasil pengurangan: " << kurang << endl;
    cout << "Hasil perkalian  : " << kali << endl;
    cout << "Hasil pembagian  : " << bagi << endl;

    return 0;
}
