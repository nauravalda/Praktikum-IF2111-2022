// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 3-10-2022
// Deskripsi : Praktikum hitungfrekuensi.c

#include "hitungfrekuensi.h"
#include <stdio.h>

int hitungfrekuensi(){
    boolean t_f=false;
    boolean i_f=false;
    boolean g_f=false;
    
    int count=0;
    START();
    while(!IsEOP()){
        if(currentChar=='t'||currentChar=='T'){
            t_f=true;
        }
        else if (t_f==true&&(currentChar=='i'||currentChar=='I')){
            i_f=true;
        }
        else if (t_f==true && i_f==true && (currentChar=='g'||currentChar=='G')){
            g_f=true;
        }
        else if (t_f==true&&i_f==true&&g_f==true&&(currentChar=='a'||currentChar=='A')){
            count++;
            t_f=false;
            i_f=false;
            g_f=false;
        }
        else{
            t_f=false;
            i_f=false;
            g_f=false;
        }
        ADV();
    }
    return count;
}