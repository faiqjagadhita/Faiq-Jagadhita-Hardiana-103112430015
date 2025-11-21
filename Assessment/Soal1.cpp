 //* Author: [Fa'iq Jagadhita Hardiana]
 //* NIM: [103112430015]
 

#include <iostream>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = NULL; 


void insertAkhir (string nama) {
    Node* baru = new Node;
    baru->nama = nama ;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = baru;
}

void deleteNamaCari() {
    if (head == NULL) {
        cout << "List kosong. Tidak ada yang dihapus.\n";
        return;
    }

    string namaCari;
    cout << "Masukkan nama yang akan dihapus: ";
    cin >> namaCari;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->nama != namaCari) {
        prev = temp;
        temp = temp->next;
    }

 
    if (temp == NULL) {
        cout << "Nama tidak ditemukan dalam list.\n";
        return;
    }

    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    delete temp; 
    
    
}

void viewList() {
    if (head == NULL) {
        cout << "List kosong.\n";
        return;
    }

    Node* temp = head;
    cout << "Isi list:\n";
    while (temp != NULL) {
        cout << "- " << temp->nama << endl;
        temp = temp->next;
    } 
}

void hitungGenap() {
    if (head == NULL) {
        cout << "List kosong.\n";
        return;
    }

    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        if (temp->nama.length() % 2 == 0) {
            count++;
        }
        temp = temp->next;
    }

    cout << "Jumlah nama dengan panjang genap: " << count << endl;
}


int main () {
    int pilihan, posisi;
    string nama;

    do {
        //menu 
        cout << "1. insert," << "2. delete," << "3. view," << "4. hitung genap," << "0. exit\n";
        cin >> pilihan;

        switch (pilihan){
        case 1:
            cout << "Masukkan Nama: ";
                cin >> nama;
                insertAkhir(nama);     
                break;
        case 2:
                deleteNamaCari();
                break;
        case 3:
            viewList();
            break;
        case 4:
            hitungGenap();
            break;
        case 0:
            cout << "Keluar...\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";

        }

    } while (pilihan != 0);
    return 0;
}







