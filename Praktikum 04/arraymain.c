// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 26-9-2022
// Deskripsi : Praktikum arraymain.c


#include <stdio.h>

int main(){
    int N,q,l,r;
    scanf("%d\n",&N);
    typedef struct 
    {
        int A[1000];
    } array;
    
    array T;
    int i,j,k;
    for (i=0;i<N;i++){
        if (i<N-1){
            scanf("%d ",&T.A[i]);
        }
        else{
            scanf("%d\n",&T.A[i]);
        }}
    scanf("%d\n",&q);
    for (j=1;j<=q;j++){
        scanf("%d %d", &l, &r);
        int sum=0;
        for (k=l-1;k<=r-1;k++){
            sum+=T.A[k%N];
        }
        printf("%d\n",sum);
    }
}