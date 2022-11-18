// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 11-9-2022
// Deskripsi : Prapraktikum eq_string.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    char* a;
    char* b;
    a=(char *) malloc (300);
    b=(char *) malloc (300);
    scanf("%s", a);
    scanf("%s", b);
    bool isSame=true;
    while (isSame==true && (*a!='\0' || *b!='\0')){
        if (*a!=*b){
            isSame=false;
        } else{
            a++;
            b++;
        }
    }
    if (isSame){
        printf("Ya\n");
    } else{
        printf("Tidak\n");
    }
    return 0;
}
