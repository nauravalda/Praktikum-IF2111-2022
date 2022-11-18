// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 12-11-2022
// Deskripsi : Implementasi list linear dengan infotype merepresentasikan nilai

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main(){
    int x;
    List nilai;
    CreateEmpty(&nilai);
    do {
    scanf("%d",&x);
    if (x>=0 && x<=100){
        InsVFirst(&nilai,x);
        // scanf("%d",x);
        }
    } while (x>=0 && x<=100);
    if (!IsEmpty(nilai)){
        printf("%d\n",NbElmt(nilai));
        printf("%d\n",Max(nilai));        
        printf("%d\n",Min(nilai));
        printf("%.2f\n",Average(nilai));
        InversList(&nilai);
        PrintInfo(nilai);
        printf("\n");
        InversList(&nilai);
        PrintInfo(nilai);
        printf("\n");
    } else {
        printf ("Daftar nilai kosong\n");
    } 
    return 0;
}
    
