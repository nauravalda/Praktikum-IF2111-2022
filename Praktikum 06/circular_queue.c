// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 16-10-2022
// Deskripsi : Prapraktikum circular_queue.c

/* MODUL CIRCULAR QUEUE */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Implementasi Queue menggunakan circular buffer (Alternatif III) */

#include <stdio.h>
#include "circular_queue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
    // KAMUS LOKAL
    // ALGORITMA
        return(Q.HEAD==NIL && Q.TAIL==NIL);
}
boolean IsFull (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    // KAMUS LOKAL
    // ALGORITMA
        return(Length(Q)==Q.MaxEl);
}



int Length (Queue Q){
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
    // KAMUS LOKAL
    // ALGORITMA
        if (IsEmpty(Q)) {
            return 0;
        } else {
            return (Q.TAIL - Q.HEAD + Q.MaxEl) % Q.MaxEl + 1;
        }
}

int MaxLength (Queue Q){
/* Mengirimkan kapasitas jumlah elemen Q */
    // KAMUS LOKAL
    // ALGORITMA
    return(Q.MaxEl);
}


/* *** Kreator *** */
Queue CreateQueue (int Max){
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */
    Queue Q;
    Q.Tab=(ElType *) malloc ((Max) * sizeof(ElType));
    if (Q.Tab != NULL){
        Q.HEAD=NIL;
        Q.TAIL=NIL;
        Q.MaxEl=Max;
    } else{
        Q.MaxEl=0;
    }
    return(Q);
    }


/* *** Destruktor *** */
void DeleteQueue (Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */
    (*Q).MaxEl=0;
    free((*Q).Tab);
}


/* *** Primitif Add/Delete *** */
void Push (Queue * Q, ElType X){
    /* Proses: Menambahkan X pada Q dengan aturan FIFO */
    /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
    /* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
    if (IsEmpty(*Q)){
        Q->HEAD=0;
        Q->TAIL=0;
    } else {
        Q->TAIL=(Q->TAIL+1)%Q->MaxEl;
    }
    Q->Tab[Q->TAIL]=X;
}

ElType Pop (Queue * Q){
    /* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
    /* I.S. Q tidak mungkin kosong */
    /* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
    ElType X;
    X=Q->Tab[Q->HEAD];
    if (Length(*Q)==1){
        Q->HEAD=NIL;
        Q->TAIL=NIL;
    } else {
        Q->HEAD=(Q->HEAD+1)%Q->MaxEl;
    }
    return(X);
}

ElType Front (Queue Q){
    return(Q.Tab[Q.HEAD]);
}
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */

// int main() {
    
//     Queue Q;
//     Q=CreateQueue(4);
//     Push(&Q,13);
//     Push(&Q,12);
//     Push(&Q,11);
//     Push(&Q,10);
//     ElType X;
//     X=Pop(&Q);
//     X=Pop(&Q);
//     X=Pop(&Q);
//     Push(&Q,90);
//     Push(&Q,20);
//     Push(&Q,8);
//     Push(&Q,6);
//     X=Pop(&Q);
//     X=Pop(&Q);
//     X=Pop(&Q);
//     X=Pop(&Q);
//     printf("%d\n",Length(Q));
//     printf("%d\n",Q.HEAD);
//     printf("%d\n",Q.TAIL);
//     Queue q2;
//     q2=CreateQueue(10);
//     if (IsFull(Q)){
//         printf("FULLLLLLLLLLLLLLLLLLLLLLLLLL");
//     }
// }