// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 5-9-2022
// Deskripsi : Praktikum strongnumber.c


#include <stdio.h>
int factorial(int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++){
        res *= i;}
    return res;
}
int main(){
    int x,i,sum=0, xr;
    scanf("%d",&x);
    xr=x;
    while (x>0){
        sum+=factorial(x%10);
        x=x/10;
    }
    if (xr==sum){
        printf("Y\n");
    }
    else{
        printf("N\n");
    }
    return 0;
}

