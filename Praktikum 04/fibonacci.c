// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 25-9-2022
// Deskripsi : Prapraktikum fibonacci.c

#include <stdio.h>
#include "fibonacci.h"

// Deret bilangan fibonacci adalah deret angka yang susunan angkanya
// merupakan penjumlahan dari dua angka sebelumnya.
// Contoh:
// Fib 0: 1
// Fib 1: 1
// Fib 2: 1 + 1 = 2
// Fib 3: 2 + 1 = 3
// Fib 4: 3 + 2 = 5
// Fib 5: 5 + 3 = 8

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci ke argumen result
// Contoh:
// n = 5
// Nilai argumen result = 8
void fibonacci1(int n, int *result){
    int i=1,c,a=0,b=1;
    if (n<=1){
        *result= 1;
    }
    else{
        for (i=1;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        *result=b;
    }
}

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci
int fibonacci2(int n){
    int i=1,c,a=0,b=1;
    if (n<=1){
        return 1;
    }
    else{
        for (i=1;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
}

// Menerima argument sebuah integer n
// Output adalah argumen result yang bertipe pointer int digunakan sebagai array
// Tuliskan semua nilai deret fibonacci dari 0 - n ke argumen result
// n = 5
// result = [1, 1, 2, 3, 5, 8]
void fibonacci3(int n, int *result){
    int i=0;
    while (i<=n){
        *result = fibonacci2(i);
        i++;
        result++;
    }

}


