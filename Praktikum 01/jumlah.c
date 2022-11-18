// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 4-9-2022
// Deskripsi : Prapraktikum jumlah.c


#include <stdio.h>

long int jml2Bil (long int x, long int y){
    return x + y;
}

int main(){
    long int x, y;
    scanf("%ld %ld", &x, &y);
    long int jml = jml2Bil(x,y);
    printf("%ld\n", jml);

    return 0;
}