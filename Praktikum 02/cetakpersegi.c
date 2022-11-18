// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 11-9-2022
// Deskripsi : Prapraktikum cetakpersegi.c

#include <stdio.h>

int main(){
    int n,i,j;
    scanf("%d",&n);
    i=0;
    j=0;
    for(i=0;i<(2*n-1);i++){
        for(j=0;j<(2*n-1);j++){
            if (i%2==0){
                if (j%2==1){
                    printf("X");
                }
                else {
                    printf("O");
                }
            }
            else {
                if (j%2==1){
                    printf("O");
                }
                else {
                    printf("X");
                }
            }
        }
        printf("\n");
    }
    return 0;
}