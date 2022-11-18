// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 12-9-2022
// Deskripsi : Praktikum reverse.c

#include <stdio.h>

int main(){
    int x;
    scanf("%d",&x);
    while (x>0){
        printf("%d",x%10);
        x=x/10;
    }
    printf("\n");
    return 0;
}
