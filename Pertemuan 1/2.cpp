#include <iostream>

using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka harus antara 0 sampai 100!" << endl;
    } else {
        cout << angka << " : ";

        if (angka == 0) cout << "nol";
        else if (angka == 100) cout << "seratus";
        else if (angka < 10) {
            string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima",
                               "enam", "tujuh", "delapan", "sembilan"};
            cout << satuan[angka];
        }
        else if (angka < 20) {
            string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas",
                                "empat belas", "lima belas", "enam belas",
                                "tujuh belas", "delapan belas", "sembilan belas"};
            cout << belasan[angka - 10];
        }
        else {
            string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima",
                               "enam", "tujuh", "delapan", "sembilan"};
            string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh",
                                "lima puluh", "enam puluh", "tujuh puluh",
                                "delapan puluh", "sembilan puluh"};

            int puluh = angka / 10;
            int sisa = angka % 10;

            cout << puluhan[puluh];
            if (sisa != 0) {
                cout << " " << satuan[sisa];
            }
        }
    }

    cout << endl;
    return 0;
}