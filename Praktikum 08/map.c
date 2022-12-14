// Naura Valda Prameswari
// 18221173
// K-01
// 28-10-2022
// PRAPRAKTIKUM 8 - 2
/* File : map.c */

#include <stdio.h>
#include "map.h"

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M){
    M->Count=Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M){
    return(M.Count==Nil);
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFull(Map M){
    return(M.Count==MaxEl);
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k){
    // KAMUS LOKAL
    valuetype val;
    int i=0;
    boolean found=false;
    // ALGORITMA
    if (IsMember(M,k)){
        while (i<M.Count && !found){
            if (M.Elements[i].Key==k){
                val=M.Elements[i].Value;
                found=true;
            } else{
                i++;
            }
        }
    } else{
        val=Undefined;
    }
    return(val);
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(Map *M, keytype k, valuetype v){
    //KAMUS LOKAL
    //ALGORITMA
    if (!IsMember(*M,k)){
        M->Count++;
        (*M).Elements[(*M).Count-1].Key=k;
        (*M).Elements[(*M).Count-1].Value=v;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k){
    // KAMUS LOKAL
    int i=0,x;
    boolean found=false;
    // ALGORITMA
    if (IsMember(*M,k)){
        while (i<M->Count && !found){
            if (M->Elements[i].Key==k){
                found=true;
            } else{
                i++;   
            }   
        }
        for (x=i; x<M->Count-1; x++){
            M->Elements[x].Key=M->Elements[x+1].Key;
            M->Elements[x].Value=M->Elements[x+1].Value;
        }
        M->Count--;
    }
}

/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMember(Map M, keytype k){
    // KAMUS LOKAL
    int i=0;
    boolean found=false;
    // ALGORITMA
    while (i<M.Count && !found){
            if (M.Elements[i].Key==k){
                found=true;
            } else{
                i++;   
            }   
        }
    return(found);
    }
/* Mengembalikan true jika k adalah member dari M */

