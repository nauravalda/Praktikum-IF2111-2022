// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 17-10-2022
// Deskripsi : Praktikum tanpaBomb.c

#include <stdio.h>
#include "tanpaBomb.h"

Queue tanpaBomb(Queue queue, ElType bomb){
	Queue new;
	ElType val;
	while (!isEmpty(queue)){
		if (HEAD(queue)!=bomb){
			dequeue(&queue, &val);
			enqueue(&new, val);
		}
		else{
			ElType Temp;
			dequeue(&queue,&Temp);
		}
	}
	return new;
}