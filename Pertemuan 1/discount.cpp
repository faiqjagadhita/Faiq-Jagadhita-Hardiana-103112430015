#include <iostream>

using namespace std;

int main () {
    double total_Pembelian, diskon;
    cout << "Berapa kamu belanja: Rp.";
    cin >> total_Pembelian;
    if (total_Pembelian >= 30000) {
        diskon = 0.1 * total_Pembelian;
        cout << "kamu dapat diskon sebesar " << diskon << "orang kaya koe sih ";
    } else {
        cout << "Koe be langka modal ko njauk diskon ";
    }
    return 0;
}