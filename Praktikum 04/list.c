// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 25-9-2022
// Deskripsi : Prapraktikum list.c

#include <stdio.h>
#include "list.h"

List MakeList(){
    List L;
    int i;
    /* ALGORITMA */
    for (i = 0; i <= MaxEl - 1; i++){
        L.A[i] = Mark;
    }
    return L;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L){
	return (L.A[0] == Mark);
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i){
    return (L.A[i]);
}
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v){
    (*L).A[i]=v;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L){
    int i;
    /* ALGORITMA */
    i = 0;
    while ((L.A[i]) != Mark && i < MaxEl) {
        i += 1;
    }
    return i;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L){
    return 0;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdx(List L){
    return (Length(L)-FirstIdx(L)-1);
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i){
    return (i > InvalidIdx && i < MaxEl);
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEff (List L, IdxType i){
    return ((i >= FirstIdx(L) ) && (i <= LastIdx(L)));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X){
    IdxType i=LastIdx(L);
    boolean Found=false;
    L.A[0]=X;
    if (!IsEmpty(L)){
        while (L.A[i]!=X){
            i--;
        }
        if (i>0){
            Found=true;
        }
    }
    return Found;

}
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirst(List *L, ElType X){
    IdxType first=FirstIdx(*L);
    InsertAt(L, X, first);
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAt(List *L, ElType X, IdxType i){
    int it;
    if (Length(*L)<MaxEl){
        for (it=(Length(*L)); it>=i; it--){
            (*L).A[it]=(*L).A[it-1];
        }
    }        
    (*L).A[i]=X;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
void InsertLast(List *L, ElType X){
    IdxType last=LastIdx(*L);
    InsertAt(L, X, last+1);
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirst(List *L){
    IdxType first=FirstIdx(*L);
    DeleteAt(L,first);
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAt(List *L, IdxType i){
    int it;
    for (it=i; it<((Length(*L))-1); it++){
        (*L).A[it]=(*L).A[it+1];
        }
    (*L).A[Length(*L)-1]=Mark;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLast(List *L){
    IdxType last=LastIdx(*L);
    DeleteAt(L,last);
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

List Concat(List L1, List L2){
    List L;
    IdxType i;
	// ALGORITMA
	L = MakeList();
	for (i = 0; i < Length(L1); i++) {
		L.A[i] = L1.A[i];
	}
	for (i = 0; i < Length(L2); i++) {
		L.A[i+Length(L1)] = L2.A[i];
	}
	return L;
}
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */

// int main(){
//     List L=MakeList();
//     InsertFirst(&L,1);
//     InsertAt(&L,8,0);
//     printf("%d\n",Get(L,1));
//     InsertLast(&L,9);
//     DeleteFirst(&L);
//     if (Search(L,90)){
//         printf("adaaa\n");
//     }
//     DeleteLast(&L);
//     if (IsIdxValid(L,10)){
//         printf("y valid\n");
//     }
//     if (IsIdxEff(L,2)){
//         printf("Y\n");
//     }
//     printf("%d\n",Length(L));
//     List L2=MakeList();
//     InsertFirst(&L2,70);
//     InsertLast(&L2,100);
//     List L3=Concat(L,L2);
//     printf("%d\n",Get(L3,0));
//     printf("%d\n",Length(L3));
// }