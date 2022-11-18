// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 19-9-2022
// Deskripsi : Praktikum jumlahkonsonanvokal.c

#include <stdio.h>
#include "jumlahkonsonanvokal.h"
#include <stdbool.h>

bool isvokal(char ch){
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
}

bool isAlphabet(char ch){
    return ((ch>='a' && ch<='z') || (ch>='A' && ch<= 'Z'));
}


// Parameter pertama merupakan kalimat
// Parameter kedua merupakan jumlah huruf konsonan
// Parameter ketiga merupakan jumlah huruf vokal
void jumlahKonsonanVokal(char*str, int*k, int*v){
    while (*str !='\0'){
        if (isAlphabet(*str)){
            if (isvokal(*str)){
                (*v)++;
            } else{
                (*k)++;
            }
        }
        str++;
    }
}







