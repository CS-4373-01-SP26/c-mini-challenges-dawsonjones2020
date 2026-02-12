#include <stdio.h>

//Print “Hello, <NAME>” where NAME is input from the keyboard.
int main(int argc, char *argv[]){
    if (argc < 2) return 1;
    printf("Hello, %s\n", argv[1]);
    return 0;
}