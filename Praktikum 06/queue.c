// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 16-10-2022
// Deskripsi : Prapraktikum queue.c


#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (length(q)==CAPACITY);
}

int length(Queue q){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (isEmpty(q)) {
        return 0;
    } else {
        return (IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY) % CAPACITY + 1;
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val){
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *val = HEAD(*q);
    if (length(*q) == 1) {
        IDX_HEAD(*q)=IDX_UNDEF;
        IDX_TAIL(*q)=IDX_UNDEF;
    } else {
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q){
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    printf("[");
    if (!isEmpty(q)) {
        int i = IDX_HEAD(q);
        do {
            printf("%d,", q.buffer[i]);
            i = (i + 1) % CAPACITY;
        } while (i != IDX_TAIL(q));
        printf("%d", q.buffer[i]);
    }
    printf("]\n");


}
