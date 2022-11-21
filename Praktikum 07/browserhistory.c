// Naura Valda Prameswari
// 18221173
// K-01
// 24-10-2022
// PRAKTIKUM 7 - 1
/* File : browserhistory.c */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "browserhistory.h"

void browserHistoryVisit(Stack *openedTab, Stack *history, char* url){
	Push((openedTab), url);
	browserHistoryFree(history);
}
/**
 * Menambahkan url ke openedTab
 * I.S. openedTab mungkin kosong, tabel penampung elemen stack TIDAK penuh
 * F.S. url menjadi TOP yang baru, TOP bertambah 1, history kosong
 */

char* currentUrl(Stack *openedTab){
	return(InfoTop(*openedTab));

}
/**
 * Mengembalikan url yang sedang dibuka
 * I.S. openedTab tidak mungkin kosong
 * F.S. url adalah nilai elemen TOP yang lama
 */

char* browserHistoryBack(Stack *openedTab, Stack *history, int steps){
	int i;
	char* bhb;
	bhb = (char*) malloc (300);
	for (i=0;i<=steps;i++){
		Pop((openedTab),&(bhb));
		Push((history),bhb);
	}
	return (bhb);
}
/**
 * Mengembalikan url yang sedang dibuka setelah kembali ke sebelumnya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP berkurang 1
 */

char *browserHistoryForward(Stack *openedTab, Stack *history, int steps){
	int i;
	char *bhf;
	bhf = (char*) malloc (300);
	for (i=0;i<=steps;i++){
		Pop((history),&(bhf));
		Push((openedTab), bhf);
	}
	return (bhf);
}
/**
 * Mengembalikan url yang sedang dibuka setelah maju ke depannya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP bertambah 1
 */

void browserHistoryFree(Stack *history){
	char *val;
	val = (char*) malloc (300);
	while (!IsEmpty(*history)){
		Pop((history),&(val));
	}
}
/**
 * Mengosongkan history
 * I.S. history tidak mungkin kosong
 * F.S. history kosong
 */

// int main(){
// 	Stack ot, hist;
// 	CreateEmpty(&ot);
// 	CreateEmpty(&hist);
// 	browserHistoryVisit(&ot,&hist,"twitter.com");
// 	browserHistoryVisit(&ot,&hist,"twitter.com/dsadasd");
// 	browserHistoryVisit(&ot,&hist,"twitter.com/dsadasd/blablalbla");
// 	printf("%s\n", browserHistoryBack(&ot,&hist,2));
// 	printf("%s\n", browserHistoryForward(&ot,&hist,2));
// 	printf("%s\n", currentUrl(&ot));
// 	printf("%s\n", browserHistoryBack(&ot,&hist,2));
// 	printf("%s\n", currentUrl(&ot));
// }
