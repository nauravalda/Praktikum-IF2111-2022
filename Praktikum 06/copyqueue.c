// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 17-10-2022
// Deskripsi : Praktikum copyqueue.c

#include <stdio.h>
#include "copyqueue.h"

// Menyalin queue.
void copyQueue(Queue *queueInput, Queue *queueOutput){
/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S. queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S. queueOutput memiliki isi queue yang sama */
	int i;
	i=length(*queueInput);
	ElType Val;
	while (i>0){
		dequeue(queueInput,&Val);
		enqueue(queueOutput, Val);
		enqueue(queueInput, Val);
		i-=1;
	}
}