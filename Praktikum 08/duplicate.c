// Naura Valda Prameswari
// 18221173
// K-01
// 31-10-2022
// PRAKTIKUM 8 - 1
/* File : duplicate.c */

#include <stdio.h>
#include "duplicate.h"
#include "set.h"
/*
    Masukkan semua elemen array arr ke suatu Set, kemudian kembalikan Set tersebut
        Contoh:
            arrToSet
                <- arr = [1, 1, 3]
                <- arrSize = 3
            -> [1, 3]
*/
Set arrToSet(int* arr, int arrSize){
    Set s;
    int i;
    CreateEmpty(&s);
    for (i=0;i<arrSize;i++){
        Insert(&s,*arr);
        arr++;
    }
    return (s);
}

/*
    Dengan memanfaatkan fungsi arrToSet, hapuslah elemen duplikat pada array arr
    kemudian kembalikan isinya secara menurun

    Penjelasan Parameter:
    Parameter 1: arr, merupakan array masukan yang perlu dihapus elemen duplikatnya
    Parameter 2: arrSize, merupakan panjang arr
    Parameter 3: arrRes, merupakan array keluaran, hasil pengapusan elemen duplikat
        dan elemen-elemennya terurut menurun
    Parameter 4: arrResSize, merupakan panjang arrRes

    Contoh: 
        removeDuplicate
            <- arr = [1, 1, 2, 3]
            <- arrSize = 4
            -> arrRes = [3, 2, 1]
            -> arrResSize = 3
        removeDuplicate
            <- arr = [3, 1, 1]
            <- arrSize = 3
            -> arrRes = [3, 1]
            -> arrResSize = 2
*/
void removeDuplicateDesc(int* arr, int arrSize, int* arrRes, int* arrResSize){
    Set Setarr;
    int i,j,temp;
    Setarr=arrToSet(arr,arrSize);
    for (i=0;i<(Setarr.Count);i++){
        for (j=1; j<(Setarr.Count-i); j++)
            if (Setarr.Elements[j-1] < Setarr.Elements[j]){
                temp = Setarr.Elements[j];
                Setarr.Elements[j]= Setarr.Elements[j - 1];
                Setarr.Elements[j - 1]=temp;
            }
    }
    *arrResSize=Setarr.Count;
    for (i=0;i<Setarr.Count;i++){
        *arrRes=Setarr.Elements[i];
        arrRes++;
    }

}

    
