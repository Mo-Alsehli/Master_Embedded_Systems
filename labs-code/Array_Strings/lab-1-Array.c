#include <stdio.h>

// Scanning Students Degrees And Storing Them Inside Array.

int main() {
    printf("ARRAY - STRING - LAB-3 \n");
    printf("Problem: \n Scan Students Degrees And Store Them: \n\n");
    float degrees[10];
    int i;

    for(i = 0; i < 10; i++){
        printf("Please Enter Student %d/10 degree: ", i + 1);
        scanf("%f", &degrees[i]);
    };
    printf("\n \n");
    for(i = 0; i < 10; i++){
        printf("Student %d Degree Is: %.2f \n", i + 1, degrees[i]);
    }

    return 0;

}