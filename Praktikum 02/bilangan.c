// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 12-9-2022
// Deskripsi : Praktikum bilangan.c

#include <stdio.h>
#include <stdbool.h>

bool isThere7(int x){
    bool isthere;
    isthere=false;
    while (x>0 && isthere==false){
                    if (x%10==7){
                        isthere=true;
                    } else{
                        x=x/10;
                    }
    }
    return isthere;
}

bool isKelipatan7(int x){
    return (x%7==0);
}

int main(){
    int N,i,j,x,sum;
    scanf("%d",&N);
    for (i=1;i<=N;i++){
        scanf("%d",&x);
        sum=0;
        for (j=1;j<=x;j++){
            if (isKelipatan7(j) || isThere7(j)){
                sum+=j;
            }
        }
        printf("%d\n",sum);
        
    }
    return 0;
}
