// Naura Valda Prameswari
// 18221173
// K-01
// 7-11-2022
// PRAKTIKUM 9 - 2

#include <stdio.h>
#include <stdlib.h>

#include "listlinier.h"

int main() {
    List fibonacci;
    CreateEmpty(&fibonacci);

    infotype el;
    scanf("%d", &el);
    if (el == 0) {
        PrintInfo(fibonacci);
        return 0;
    } else if (el == 1) {
        infotype x;
        scanf("%d", &x);
        InsVFirst(&fibonacci,x);
        PrintInfo(fibonacci);
        return 0;
    } else if (el>=2){
        // Masukkan kode program disini
        infotype x1, x2;
        int i;
        infotype sumTemp=0, prev, temp;
        scanf("%d", &x1);
        scanf("%d", &x2);
        InsVLast(&fibonacci, x1);
        InsVLast(&fibonacci, x2);
        sumTemp=x1+x2;
        prev=x2;
        if (el>2){
        for (i=3;i<=el;i++){
            InsVLast(&fibonacci, sumTemp);
            temp=sumTemp;
            sumTemp+=prev;
            prev=temp;
        }
        }
        PrintInfo(fibonacci);
    }

    return 0;
}




