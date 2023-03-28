#include <stdio.h>


// Getting The Transpose Of A Matrix:

int main() {

    printf("ARRAY - STRING LAB-3: \n");
    printf("Problem: \n Find The Transpose of Entered Matrix: \n\n");

    float matrix[3][3];
    float trans[3][3];
    int r, c;

    // Getting the values of the matrix.
    for(r = 0; r < 3; r++){
        for(c = 0; c < 3; c++){
            printf("Please Enter Item (%d, %d): ", r, c);
            scanf("%f", &matrix[r][c]);
        }
    }

    // Printing the values of the Matrix.
    printf("The Values Of The Matrix: \n");
    for(r = 0; r < 3; r++){
        for(c = 0; c < 3; c++){
            printf("%.2f      ", matrix[r][c]);
        }
        printf("\n");
    }

    // Getting The Transpose Of The Matrix.
    for(r = 0; r < 3; r++){
        for(c = 0; c < 3; c++){
            trans[r][c] = matrix[c][r];
        }
    }

    // printing the values of transpose.
    printf("The Values Of The Transpose: \n");
    for(r = 0; r < 3; r++){
        for(c = 0; c < 3; c++){
            printf("%.2f      ", trans[r][c]);
        }
        printf("\n");
    }
    printf("\n\n");



    return 0;
}