// Naura Valda Prameswari
// 18221173
// K-01
// 28-10-2022
// PRAPRAKTIKUM 8 - 3
/* File : hashmap.c */

#include <stdio.h>
#include "hashmap.h"

/* Definisi HashMap M kosong : M.Count = Nil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M){
    int i;
    M->Count=Nil;
    for (i=0;i<MaxEl;i++){
        M->Elements[i].Key=Undefined;
        M->Elements[i].Value=Undefined;
    }

}
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi map Undefined */

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K){
    return(K%MaxEl); 
}
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k){
    // KAMUS LOKAL
    valuetype val;
    int i=Hash(k), tmp;
    boolean found=false;
    // ALGORITMA
    tmp=i;
    do {
        if (M.Elements[i].Key==k) {
                val=M.Elements[i].Value;
                found=true;
            }
        i=(i+1)%MaxEl; // linear probing
    } while (i!=tmp && !found);
    if (!found){
        val=Undefined;
    }
    return(val);
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */


void Insert(HashMap *M, keytype k, valuetype v){
    // KAMUS LOKAL
    int i, tmp;
    // ALGORITMA
    i=Hash(k);
    tmp=i;
    do {
        if (M->Elements[i].Key==Undefined){
            M->Elements[i].Key=k;
            M->Elements[i].Value=v;
            M->Count++;
            return;
        }

        i=(i+1)%MaxEl; // linear probing
    } while (i!=tmp);
}

/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing jika index sudah terisi    */

// int main(){
//     HashMap m;
//     CreateEmpty(&m);
//     Insert(&m, 33, 99);
//     Insert(&m, 17, 80);
//     Insert(&m, 100, 0);
//     Insert(&m, 10, 78);
//     Insert(&m, 100, 900);
//     Insert(&m, 10, 65);
//     printf("%d\n", Value(m,1)); 
// }   