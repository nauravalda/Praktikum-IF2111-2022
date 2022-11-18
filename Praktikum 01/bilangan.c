// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 5-9-2022
// Deskripsi : Praktikum bilangan.c


#include <stdio.h>

int main(){
    int x;
    scanf("%d",&x);
    if (x%2!=0){
        printf("Tidak\n");
    }
    else {
        if (((x/2)%2)==0){
            printf("Ya\n");
        }
        else {
            printf("Tidak\n");
        }
    }
}