// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 11/18/2022
// Deskripsi : Implementasi linkdummy.h

#include <stdio.h>
#include "linkdummy.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L){
    return (First(L) == Last(L));
}
/* Mengirim true jika list kosong: First(L) = dummy@
dan Last(L) = dummy@ */

/****************** PEMBUATAN LIST KOSONG ******************/
void MakeEmpty(List *L){
    // Kamus Lokal
    address pD;
    // Algoritma
    pD = Alokasi(0);
    if (pD != Nil) {
        First(*L) = pD;
        Last(*L) = pD;
    } else {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong, dengan satu elemen dummy */
/* Jika gagal maka First = Last = Nil dan list gagal terbentuk */

/****************** MANAJEMEN MEMORI ******************/
address Alokasi (ElType X){
    // Kamus lokal
    address P;
    P = (address) malloc (sizeof (Node));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
	}
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */

void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** SEARCHING ******************/
address Search(List L, ElType X){
    address P;
    P=First(L);
    boolean found=false;
    while (P!=Nil && !found){
        if (Info(P)==X){
            found=true;
        }
        else{
            P=Next(P);
        }
    }
    if (found){
        return (P);
    } else{
        return (Nil);
    }

}
/* Mencari apakah ada node list dengan info(P) = X */
/* Jika ada, mengirimkan address node tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst(List *L, ElType X){
    // Kamus Lokal
    address P;
    // Algoritma
    P = Alokasi(X);
    if (P != Nil) {
    Next(P) = First(*L);
    First(*L) = P;
    }  
}
/* I.S. List L terdefinisi */
/* F.S. Menambahkan elemen X sebagai elemen pertama List L */

void InsertLast(List *L, ElType X){
    // Kamus Lokal
    address P, last;
    // Algoritma
    if (IsEmpty(*L)) {
        InsertFirst(L,X);
    } else {
        P = Alokasi(X);
        if (P != Nil) {
            last = First(*L);
            while (Next(last) != Last(*L)) {
                last = Next(last);
            }
            Next(last) = P;
            Next(P) = Last(*L);
        }
    } 
}
/* I.S. List L terdefinisi */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru, */
/* yaitu menjadi elemen sebelum elemen dummy */
/* Alamat elemen dummy tidak berubah */

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst(List *L, ElType *X){
    // Kamus Lokal
    address P;
    // Algoritma
    P = First(*L);
    *X = Info(P);
    First(*L) = Next(First(*L));    
    free(P);   
}
/* I.S. List tidak kosong */
/* F.S. X adalah elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DeleteLast(List *L, ElType *X){
    // Kamus Lokal
    address last, prec;
    // Algoritma
    last = First(*L); prec = Nil;
    while (Next(last) != Last(*L)) {
        prec = last; last = Next(last);
    }
    *X = Info(last);
    if (prec == Nil) { /* kasus satu elemen */
        First(*L) = Last(*L);
    } else {
        Next(prec) = Last(*L);
    }
    free(last);
}
/* I.S. List tidak kosong */
/* F.S. X adalah terakhir sebelum dummy pada list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
