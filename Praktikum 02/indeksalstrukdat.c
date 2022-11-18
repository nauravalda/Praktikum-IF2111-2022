// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 12-9-2022
// Deskripsi : Praktikum indeksalstrukdat.c

#include <stdio.h>

int main(){
    int x,counta, countb, countc, countd, counte;
    float sum,rata;
    sum=0;
    counta=0;
    countb=0;
    countc=0;
    countd=0;
    counte=0;
    do {
        scanf("%d", &x);
        if (x==4){
            sum+=4.00;
            counta++;
        } else if ((x>=3) && (x<4)){
            sum+=3.00;
            countb++;
        } else if ((x>=2) && (x<3)){
            sum+=2.00;
            countc++;
        } else if ((x>=1) && (x<2)){
            sum+=1.00;
            countd++;
        } else if ((x>=0) && (x<1)){
            sum+=0.00;
            counte++;
        } 
    } while (x!=-999);
    if ((counta+countb+countc+countd+counte)!=0){
        rata=sum/(counta+countb+countc+countd+counte);
        printf("Jumlah mahasiswa yang lulus = %d\n",(counta + countb));
        printf("Nilai rata-rata = %.2f\n",rata);
        if (rata==4){
            printf("Indeks akhir kelas = A\n");
        } else if ((rata>=3) && (rata<4)){
            printf("Indeks akhir kelas = B\n");
        } else if ((rata>=2) && (rata<3)){
            printf("Indeks akhir kelas = C\n");
        } else if ((rata>=1) && (rata<2)){
            printf("Indeks akhir kelas = D\n");
        } else if ((rata>=0) && (rata<1)){
            printf("Indeks akhir kelas = E\n");
        } 
    } else{
        printf("Tidak ada data\n");
    }
    return 0;
}