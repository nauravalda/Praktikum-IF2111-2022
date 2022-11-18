// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 12-11-2022
// Deskripsi : Implementasi OddEvenList.h


#include <stdio.h>
#include "OddEvenList.h"


void sort(List *L){
    boolean swapped;
    address p;
    address last = Nil;
    if (IsEmpty(*L)){
        return;
    } 
    do {
        swapped=false;
        p=First(*L);

        while (Next(p)!= last){
            if (Info(p)>Info(Next(p))){
                infotype temp = Info(p);
                Info(p)=Info(Next(p));
                Info(Next(p))=temp;
                swapped = true;
            }
            p = Next(p);
        }
        last=p;
    } while (swapped);
}

void OddEvenList(List L, List *Odd, List *Even){
    infotype val;
    address p=First(L);
    CreateEmpty(Odd);
    CreateEmpty(Even);
    while (p!=Nil){
        if (Info(p)%2==0){
            InsVFirst(Even,Info(p));
        } else {
            InsVFirst(Odd,Info(p));
        } 
        p=Next(p);
        }
    sort(Odd);
    sort(Even);
    }

    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/

// int main(){
//     List L;
//     List Odd;
//     List Even;
//     CreateEmpty(&L);
//     CreateEmpty(&Odd);
//     CreateEmpty(&Even);
//     InsVFirst(&L,10);
//     InsVFirst(&L,9);
//     InsVFirst(&L,6);
//     InsVFirst(&L,7);
//     InsVFirst(&L,-4);
//     InsVFirst(&L,3);
//     InsVFirst(&L,7);
//     InsVFirst(&L,2);
//     InsVFirst(&L,3);
//     PrintInfo(L);
//     OddEvenList(L,&Odd,&Even);
//     PrintInfo(Odd);
//     PrintInfo(Even);
// }
