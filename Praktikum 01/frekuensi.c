// Nama      : Naura Valda Prameswari
// NIM       : 18221173
// Tanggal   : 5-9-2022
// Deskripsi : Praktikum frekuensi.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    // KAMUS
    int frek[10], i;
    char *str;
    // ALGORITMA
    for (i = 0; i < 10; i++) {
        frek[i] = 0;
    }

    str = (char *) malloc (10 * sizeof (char));
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            frek[str[i]-48] += 1;
        }
    }
    for (i = 0; i < 10; i++) {
        printf("%d", frek[i]);
    }
    printf("\n");
    return 0;
}