// Naura Valda Prameswari
// 18221173
// K-01
// 7-11-2022
// PRAKTIKUM 9 - 3


#include <stdio.h>
#include <stdlib.h>
#include "removeDuplicate.h"

List removeDuplicate(List l){
	/*
    Diberikan sebuah list linier yang sudah terurut membesar,
    kembalikan list baru yang elementnya unik
    Contoh input/output:
    input:  [1,1,2,2,3,4,5,6,6,7]
    output: [1,2,3,4,5,6,7]

    input:  [1,1,1,1,1,1]
    output: [1]
*/
	List rd;
	CreateEmpty(&rd);
	address sch;
	int i;
	for (i=Min(l);i<=Max(l);i++){
		sch=Search(l,i);
		if (sch!=Nil){
			InsVLast(&rd,i);
		}
	}
	return (rd);
}

// int main(){
// 	List l1;
// 	List l2;
// 	CreateEmpty(&l1);
// 	CreateEmpty(&l2);
// 	InsVLast(&l1,1);
// 	InsVLast(&l1,1);
// 	InsVLast(&l1,2);
// 	InsVLast(&l1,2);
// 	InsVLast(&l1,2);
// 	InsVLast(&l1,4);
// 	InsVLast(&l1,4);
// 	InsVLast(&l1,4);
// 	InsVLast(&l1,5);
// 	InsVLast(&l1,6);
// 	InsVLast(&l1,7);
// 	l2=removeDuplicate(l1);
// 	PrintInfo(l2);
// }