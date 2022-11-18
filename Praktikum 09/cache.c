// Naura Valda Prameswari
// 18221173
// K-01
// 7-11-2022
// PRAKTIKUM 9 - 1

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main(){
	int N, i, Q, x, idx;
    infotype val;
    List l;

    /* ALGORITMA */
    CreateEmpty(&l);
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        InsVLast(&l, i);
    }
    scanf("%d", &Q);
    for (i = 1; i <= Q; i++) {
        scanf("%d", &x);
        address p = Search(l,x);
        if (p == Nil) {
            DelVLast(&l, &val);
            InsVFirst(&l, x);
            printf("miss ");
            PrintInfo(l);
            printf("\n");
        } else {
            DelP(&l, x);
            InsVFirst(&l, x);
            printf("hit ");
            PrintInfo(l);
            printf("\n");
        }
    }
    return 0;
}

