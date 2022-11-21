// Naura Valda Prameswari
// 18221173
// K-01
// 24-10-2022
// PRAKTIKUM 7 - 3
/* File : valid.c */

#include <stdio.h>
#include "stack.h"
#include "valid.h"

Stack validParantheses(char* input, int length){
	Stack new;
	char val;
	int i;
	CreateEmpty(&new);
	i=0;
	while (i<length && !IsFull(new)){
		if (*input=='('){
			input++;
			i++;
			if (*input==')'){
				val='(';
				Push(&new,val);
				val=')';
				Push(&new,val);
				input++;
				i++;
			} else {
				input++;
				i++;
			}
		}
		else if (*input=='['){
			input++;
			i++;
			if (*input==']'){
				val='[';
				Push(&new,val);
				val=']';
				Push(&new,val);
				input++;
				i++;
			} else {
				input++;
				i++;
			}
		}
		else if (*input=='{'){
			input++;
			i++;
			if (*input=='}'){
				val='{';
				Push(&new,val);
				val='}';
				Push(&new,val);
				input++;
				i++;
			} else {
				input++;
				i++;
			}
		}
		else{
			input++;
			i++;

		}
	}
	return (new);
}

/* Proses: Memasukkan parantheses (dari input) yang valid secara berurutan ke dalam Stack */
/* I.S. input adalah string, yang berisi parantheses baik secara acak maupun teratur, dan panjang dari string */
/* Contoh input dan hasil parantheses yang valid:
    1. () 2 -> ()
    2. []) 3 -> []
    3. {[} 3 -> --kosong--
    4. ()[]{} 6 -> ()[]{}
*/

// int main(){
// 	// Stack a=validParantheses("[]{}{{{}}}]][]()[]",18);
// 	Stack a=validParantheses("}}}[]{}}{}",10);
// 	char val;
// 	if (!IsEmpty(a)){
// 		while (!IsEmpty(a)){
// 			Pop(&a,&val);
// 			printf("%c", val);
// 		}
// 	}
// }
