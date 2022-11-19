// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 3-10-2022
// Deskripsi : Praktikum cipher.c

#include <stdio.h>
#include "mesinkata.h"

int main(){
    // KAMUS
    int i, geser, hasil;
    // ALGORITMA
    STARTWORD();
    if (!isEndWord()) {
        geser = currentWord.Length;
    }
    while (!isEndWord()) {
        for (i = 0; i < currentWord.Length; i++){
            hasil = (int) currentWord.TabWord[i] + geser;
            hasil = (hasil - 65) % 26 + 65;
            printf("%c", hasil);
        }
        if (currentChar != MARK) {
            printf(" ");
        }
        ADVWORD();
    }
    printf(".\n");
}