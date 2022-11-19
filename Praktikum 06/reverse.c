// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 16-10-2022
// Deskripsi : Prapraktikum reverse.c


#include <stdio.h>
#include "reverse.h"

void transferReverse(Queue* q1, Queue* q2){
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik
    // KAMUS LOKAL
    ElType Val;
    int head,tail;
    // // ALGORITMA 
    while (Length(*q1)>1){
        tail=q1->TAIL;
        head=q1->HEAD;
        q1->TAIL=head;
        q1->HEAD=tail;
        Val=Pop(q1);
        Push(q2,Val);
        q1->HEAD=head;
        q1->TAIL=tail-1;
    }
    Val=Pop(q1);
    Push(q2,Val);
}

// int main(){
//     Queue Q,Q2;
//     Q=CreateQueue(4);
//     Push(&Q,14);
//     Push(&Q,13);
//     Push(&Q,12);
//     Push(&Q,11);
//     ElType X;
//     X=Pop(&Q);
//     X=Pop(&Q);
//     X=Pop(&Q);
//     Push(&Q,20);
//     Push(&Q,8);
//     Push(&Q,6);
//     Q2=CreateQueue(4);
//     transferReverse(&Q,&Q2);
//     printf("%d\n",Q2.Tab[0]);
//     printf("%d\n",Q2.Tab[1]);
//     printf("%d\n",Q2.Tab[2]);
//     printf("%d\n",Q2.Tab[3]);
    
//     return 0;

// }