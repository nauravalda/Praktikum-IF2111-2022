// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 26-9-2022
// Deskripsi : Praktikum MinMax.c


#include <stdio.h>
#include "MinMax.h"


List MinMax(List L){
    IdxType i=0,j=0,imax=0,imin=0;
    ElType Max=L.A[0];
    ElType Min=L.A[0];
    for (i=0;i<=LastIdx(L);i++){
            if (L.A[i]<Min){
                Min=L.A[i];
                imin=i;
                }
    }
    DeleteAt(&L,imin);
    InsertLast(&L,Min);

    for (j=0;j<=LastIdx(L);j++){
            if (L.A[j]>Max){
                Max=L.A[j];
                imax=j;
            }
    }        
    DeleteAt(&L,imax);
    InsertLast(&L,Max);
    return L;
}

    