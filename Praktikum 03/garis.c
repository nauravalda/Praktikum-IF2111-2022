// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 19-9-2022
// Deskripsi : Praktikum garis.c


/* Implementasi dari garis.h */
#include <stdio.h>
#include "garis.h"

/* *** Konstruktor membentuk GARIS *** */
void MakeGARIS (POINT P1, POINT P2, GARIS * L){
    /*KAMUS*/
    /*ALGORITMA*/
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS */
void BacaGARIS (GARIS * L){
    /*KAMUS*/
    POINT p1, p2;
    /*ALGORITMA*/
    do {
        BacaPOINT(&p1);
        BacaPOINT(&p2);
        if(EQ(p1, p2)){
            printf("Garis tidak valid\n");
        }
    } while (EQ(p1, p2));
    MakeGARIS(p1, p2, L);
}
void TulisGARIS (GARIS L){
    /*KAMUS*/
    /*ALGORITMA*/
    printf("("); TulisPOINT(PAwal(L)); printf(","); TulisPOINT(PAkhir(L)); printf(")");
}
/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L){
    /*KAMUS*/
    /*ALGORITMA*/
    /* Rumus yang digunakan adalah sqrt((x2 - x1)^2 + (y2 - y1)^2) */
    return (Panjang(PAwal(L), PAkhir(L)));
}
float Gradien (GARIS L){
    /*KAMUS*/
    /*ALGORITMA*/
    return ((Ordinat(PAkhir(L)) - Ordinat(PAwal(L)))) / (Absis(PAkhir(L)) - Absis(PAwal(L)));
}
boolean IsTegakLurus (GARIS L1, GARIS L2){
    /*KAMUS*/
    /*ALGORITMA*/
    return (Gradien(L1) * Gradien(L2) == -1);
}
boolean IsSejajar (GARIS L1, GARIS L2){
    /*KAMUS*/
    /*ALGORITMA*/
    return (Gradien(L1) == Gradien(L2));
}