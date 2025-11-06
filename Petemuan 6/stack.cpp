#include "stack.h"

using namespace std;

//fungsi membuat stack baru udengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;
}

//fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;
}

//fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}

//fungsi untuk menambahkan elemen ke stack
void push(Stack &S, infotype x) {
    if (! isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "stack penuh!" << endl;
    }
}

// fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop (Stack &S) {
    infotype X = -999;
    if (!isEmpty(S)) {
        X = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack Kosong!" << endl;
    }
    return X;
}

// fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)){
        cout << "Stack kosong" << endl;
    } else {
        cout << "[TOP]" ;
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

//fungsi untuk membalikan urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);

        while (!isEmpty(S)) {push (temp1, pop(S));}

        while (!isEmpty(temp1)) {push (temp2, pop(temp1));}

        while (!isEmpty(temp2)) {push (S, pop(temp2));}
    }
}