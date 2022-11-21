// Naura Valda Prameswari
// 18221173
// K-01
// 21-10-2022
// PRAPRAKTIKUM 7 - 3
/* File : aritmatika.c */

#include <stdio.h>
#include "aritmatika.h"

boolean isOperator(char input){
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari + - * /
*/
    // KAMUS LOKAL
    // ALGORITMA
    return(input=='+' || input=='-' || input=='*' || input=='/');
}

int hitung(int angka1, int angka2, char op){
/* Proses: Menghitung ekspresi */
// KAMUS LOKAL
// ALGORITMA
    if (op=='+'){
        return(angka1+angka2);
    }
    else if (op=='-'){
        return(angka1-angka2);
    }
    else if (op=='*'){
        return(angka1*angka2);
    }
    else if (op=='/'){
        return(angka1/angka2);
    }
}

int eval(char *input, int length){
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
    // KAMUS LOKAL
    Stack S;
    int angka,x1,x2,hasil, i=0;
    // ALGORITMA
    CreateEmpty(&S);
    while (i<length) {
        if (!isOperator(*input)){
            angka=*input - '0';
            Push(&S,angka);
        }
        else{
            Pop(&S,&x2);
            Pop(&S,&x1);
            hasil=hitung(x1,x2,*input);
            Push(&S,hasil);
        }
        input++;
        i++;
    }
    Pop(&S,&hasil);
    return(hasil);
}

// int main(){
//     printf("%d",eval("9423+*5/-",9));
// }