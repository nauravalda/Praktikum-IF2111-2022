// Naura Valda Prameswari
// 18221173
// K-01
// 24-10-2022
// PRAKTIKUM 7 - 2
/* File : minStack.c */

#include <stdio.h>
#include "stack.h"

void convert_to_stack(char string[100], Stack *s){
	int i = 0, x;
    /*ALGORITMA*/
    while (string[i] != '\0'){
        x=string[i]-'0';
        Push(s,x);
        i++;
    }
}

// S2 <= S1
Stack minus(Stack S1, Stack S2){
    Stack min;
    int res, val1, val2, min_ten;
    CreateEmpty(&min);
    while (!IsEmpty(S2) && (!IsFull(min))){
        Pop(&S1, &val1);
        Pop(&S2, &val2);
        res = val1 - val2;
	        if (res < 0){
        	    Push(&min, res+10);
				Pop(&S1, &val1);
        	    Push(&S1, val1-1);
        	} else {
            	Push(&min,res);
        }
    }
    while (!IsEmpty(S1) && (!IsFull(min))) {
        Pop(&S1, &val1);
        if (val1<0){
            Push(&min, val1+10); 
			Pop(&S1, &val1);
        	Push(&S1, val1-1);                     
        } else{
            Push(&min, val1);
        }
    }
    return min;
}

boolean isLessThan (Stack s1, Stack s2){
    int val1, val2;
    boolean isLess=false;
    Stack a1, a2; 
    CreateEmpty(&a1); 
    CreateEmpty(&a2);
    while (!IsEmpty(s1) && !IsEmpty(s2)) {
        Pop(&s1, &val1); 
        Pop(&s2, &val2); 
        Push(&a1, val1);
        Push(&a2, val2);
    }
    if (IsEmpty(s1) && !IsEmpty(s2)){
        isLess=true;
    } else if (!IsEmpty(s1) && IsEmpty(s2)){
        isLess=false;
    } else{
        while (isLess==false && !IsEmpty(a1)){
            Pop(&a1,&val1);
            Pop(&a2,&val2);
            if (val1<val2){
                isLess=true;
            }
        }
    }
    return (isLess);
}

int main(){
	Stack S1,S2, min;
	char str1[100], str2[100];
	CreateEmpty(&S1);
	CreateEmpty(&S2);
	CreateEmpty(&min);
	scanf("%s", &str1);
    scanf("%s", &str2);
    convert_to_stack(str1, &S1); 
    convert_to_stack(str2, &S2);
    if (isLessThan(S1,S2)){
        min = minus(S2, S1);
        printf("-");
    } else{
        min = minus(S1, S2);
    }
    int val;
	while (!IsEmpty(min) && val==0){
        Pop(&min, &val);
    }
	Push(&min,val);
    while (!IsEmpty(min)){
        Pop(&min, &val);
        printf("%d", val);
    }
    printf("\n");

}
