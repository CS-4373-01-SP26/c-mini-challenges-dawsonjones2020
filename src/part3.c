#include <stdio.h>
#include <time.h>

// Implement matrix – vector multiplication. Read in the following text file (mv.txt) 
// which contains the matrix and vector to be multiplied. Print your answer to the screen
// and time the computation. The format of mv.txt is: line 1 contains numrows, numcols. 
// The next numrows contains the rows of the matrix, each with numcols integer values. 
// The next line contains the length of the vector. The next line contains the vector of that length.
int main(){
    FILE *file = fopen("mv.txt", "r");

    // scan first line for row num and col num
    int numrows;
    int numcols;
    fscanf(file, "%d %d", &numrows, &numcols);

    // declare matrix and fill it w numbers based on given size
    int matrix[numrows][numcols];
    for (int row = 0; row < numrows; row++){
        for (int col = 0; col < numcols; col++){
            fscanf(file, "%d", &matrix[row][col]);
        }
    }

    // scan for vector len
    int vectorlen;
    fscanf(file, "%d", &vectorlen);

    // filll vector
    int vector[vectorlen];
    for (int i = 0; i < vectorlen; i++){
        fscanf(file, "%d", &vector[i]);
    }

    int retvector[vectorlen]; // will always be a vector of same size

    // start clock before computation - got timing code from GPT
    struct timespec start, end; // 
    clock_gettime(CLOCK_MONOTONIC, &start); 

    for (int row = 0; row < numrows; row++){
        int rowsum = 0; // keep track of sum of each multiplication
        for (int col = 0; col < numcols; col++){
            rowsum += matrix[row][col] * vector[col]; // multiply each col by each vector row
        }
        retvector[row] = rowsum;
    }
    clock_gettime(CLOCK_MONOTONIC, &end); // end clock after computation
    long elapsed_nanoseconds = end.tv_nsec  - start.tv_nsec;

    printf("The resulting vector of the multiplication:\n");
    for (int i = 0; i < vectorlen; i++){
        printf("%d\n", retvector[i]);
    }
    printf("Took %ld nanoseconds\n", elapsed_nanoseconds);

    fclose(file);
    return 0;
}