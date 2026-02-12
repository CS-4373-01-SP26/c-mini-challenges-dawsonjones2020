#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write a program that accepts a string input from stdio and sends it 
// to a function that transforms it according a transposition function 
// passed in to it as an argument.  The function will print out the string, 
// transform it, and then print out the result. The transposition function, 
// you can assume, simply shuffles the existing characters in the string.  Build a 
// transposition function that reverses the string and apply it.  Where appropriate 
// and possible, use dynamic allocation and pointer arithmetic to get the job done.

char* reverse(char* str){
    int len = strlen(str); // get len of str
    char* reversed = malloc(len); // allocate char* as long as str
    for (int i = 0; i < len; i++){ // loop through each letter of str
        *(reversed+i) = *(str+len-i-1); // remove 1 to handle null terminator
    }
    return reversed;
}

// swaps pairs of letters. 0<->1, 2<->3, etc
char* swapPairs(char* str){
    int len = strlen(str); // get len of str
    char* swapped = malloc(len+1); // allocate char* as long as str
    for (int i = 0; i < len; i+=2){
        *(swapped+i) = *(str+i+1); // puts 1 into 0
        *(swapped+i+1) = *(str+i); // puts 0 into 1
    }
    if (len%2 != 0){ // handles odd length, just leaves extra at end
        *(swapped+len-1) = *(str+len-1);
    }
    *(swapped+len) = '\0'; // ensure null terminator at end
    return swapped;
}

void transpose(char* str, char*(*inFunc)(char*)){
    printf("Original: %s\n", str);
    char* transposed;
    transposed = inFunc(str);
    printf("Transposed: %s\n", transposed);
    return;
}

int main(){
    // get input str
    printf("Enter a string:\n");
    char buffer[256];
    scanf("%s", buffer);

    // get choice of transpose function
    printf("\n");
    printf("Pick a transposition function:\n");
    printf("0: reverse string\n");
    printf("1: swap letter pairs\n");
    char choice;
    scanf(" %c", &choice);

    // use choice to call correect tranpose function
    printf("\n");
    if (choice == '0'){
        transpose(buffer, reverse);
    } else {
        transpose(buffer, swapPairs);
    }
    return 0;
}