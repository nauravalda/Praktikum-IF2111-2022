// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 11-9-2022
// Deskripsi : Prapraktikum jumlah.c

#include <stdio.h>

int main(){
    int x; 
    int sum;
    sum=0;
    scanf("%d",&x);
    while (x>0) {
        sum=sum+(x%10);
        x=x/10;
    }
    printf("%d\n",(sum));
    return 0;
}