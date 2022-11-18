// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 18-9-2022
// Deskripsi : Prapraktikum panjangstring.c

#include <stdio.h>
#include "panjangstring.h"

int panjangString(char*p){
    int length = 0;
    while (*p != '\0') {
        length++; p++;
    }
    return length;   
}

