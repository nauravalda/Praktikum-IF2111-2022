// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 2-10-2022
// Deskripsi : Prapraktikum hitungkarakter.c


#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

int hitungkarakter(char karakter){
    int i=0;
    START();
    while (!IsEOP()){
        if (GetCC()==karakter){
            i++;
        }
        ADV();
    }
    return i;
}