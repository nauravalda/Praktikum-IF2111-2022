// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 4-9-2022
// Deskripsi : Prapraktikum jumlah.c

#include <stdio.h>

int main(){
    int sec, sisa, h,m,s;
    scanf("%d",&sec);
    h = sec / 3600;
    sisa= sec%3600;
    m = sisa / 60;
    s = sisa % 60;
    printf("%d detik = %d jam %d menit %d detik\n", sec, h, m,s);
    return 0;
}