// Naura Valda Prameswari
// 18221173
// K-01
// 12-11-2022
// PRAPRAKTIKUM 10 - 3
/* File : elemenken.c */

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
    address P=First(L);
    while (r!=0){
        P=Next(P);
        r--;
    }
    return(Info(P));
  /* Tuliskan implementasi di sini */
}

int main () {
    List L;
    int x;
    int r;
  /* Tuliskan implementasi di sini */
    CreateEmpty(&L);
    do {
    scanf("%d",&x);
    if (x!=0){
        InsVLast(&L,x);
        }
    } while (x!=0);
    scanf("%d",&r);
    // PrintInfo(L);
    // printf("\n");
    if (!IsEmpty(L)){
        printf("%d\n", ElemenKeN(L, r));
    } else{
        printf("List Kosong\n");
    }
    return 0;
}