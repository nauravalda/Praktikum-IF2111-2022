// Naura Valda Prameswari
// 18221173
// K-01
// 21-10-2022
// PRAPRAKTIKUM 7 - 2
/* File : palindrom.c */

#include <stdio.h>
#include "stack.h"

Stack reverseStack(Stack S){
    // fungsi mereturn reverse stack S
    // KAMUS LOKAL
    Stack new;
    // ALGORITMA
    CreateEmpty(&new);
    infotype temp;
    while (!IsEmpty(S)){
        Pop(&S,&temp);
        Push(&new,temp);
    }
    return(new);
}

int main(){
    // KAMUS
    int x, temp1, temp2;
    Stack S1,S2;
    boolean palindrom=true;
    // ALGORITMA
    CreateEmpty(&S1);
    scanf("%d",&x);
    while (x!=0){
        Push(&S1,x);
        scanf("%d",&x);
    }
    if(IsEmpty(S1)){
        printf("Stack kosong\n");
    }
    else{
        S2=reverseStack(S1);
        while (!IsEmpty(S1) && palindrom){
            Pop(&S1, &temp1);
            Pop(&S2, &temp2);
            if (temp1!=temp2){
                palindrom = false;
            }
        }
        if (palindrom){
            printf("Palindrom\n");
        } else{
            printf("Bukan Palindrom\n");
        }
    }   
}