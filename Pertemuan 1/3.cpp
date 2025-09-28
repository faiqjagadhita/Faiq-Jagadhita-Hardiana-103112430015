#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {
        // kasih spasi supaya bintang lurus ke bawah
        for (int s = 0; s < n - i; s++) {
            cout << "  ";  // dua spasi
        }

        // angka kiri
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // bintang
        cout << "* ";

        // angka kanan
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    // baris terakhir: bintang doang
    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}
