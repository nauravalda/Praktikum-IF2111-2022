// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 17-10-2022
// Deskripsi : Praktikum restoran.c

#include <stdio.h>
#include "queue.h"

int main(){
	Queue q;
	CreateQueue(&q);
	int x, count=0, max=0, min=0;
	ElType Val, del;
	do {
		scanf("%d",&x);
		if (x==1){
			scanf("%d\n",&Val);
			if (Val>0){
				enqueue(&q,Val);
			}
		}
		else if(x==2 && !isEmpty(q)){
			dequeue(&q,&del);
			if (min==0 || max==0){
				min=del;
				max=del;}
			if (del<min){
					min=del;
					if (del>max){
						max=del;
					}
				}
			else if (del>max) {
					max=del;
					if (del<min){
						min=del;
					}
				}
			count++;
			}
		} while (x!=0);
	
	printf("%d\n%d\n%d\n", count, min, max);
	
}