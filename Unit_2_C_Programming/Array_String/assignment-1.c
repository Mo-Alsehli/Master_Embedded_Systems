#include <stdio.h>
#include <string.h>



int main() {

    printf("Program-1: \n");
    printf("Write a C program to find the sum of two matrices of order 2 * 2 using multi-dimensional arrays? \n\n");

    float matrix1[2][2], matrix2[2][2];

    printf("Enter Elements Of First Matrix: \n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("Enter a%d%d: ", i + 1, j + 1);
            scanf("%f", &matrix1[i][j]);
        }
    }

    printf("Enter Elements Of Second Matrix: \n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("Enter b%d%d: ", i + 1, j + 1);
            scanf("%f", &matrix2[i][j]);
        }
    }

    printf("Sum Of Matrix: \n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%.2f      ", matrix1[i][j] + matrix2[i][j]);
        }
        printf("\n");
    }
    printf("\n \n"); 

// ###########################################################################################

     printf("Program-2: \n");
    printf("C To Calculate Average Using Arrays? \n\n");

    float avgArr[100], sum = 0, avg;
    int n, i;

    printf("Enter The Number Of Data: ");
    scanf("%d", &n);

    while(n >= 100 || n <= 0){
        printf("Number of data should be less than 100 and more than 0 \n");
        printf("Enter Number Of Data: ");
        scanf("%d", &n);
    }

    for(i = 0; i < n; i++){
        printf("%d. Enter Number: ", i+1);
        scanf("%f", &avgArr[i]);
        sum += avgArr[i];
    }

    avg = sum / n;

    printf("Average = %.2f\n", avg);

    printf("\n\n"); 
    
// ###########################################################################################


    printf("Program-3: \n");
    printf("C Program To Get The Transpose Of Matrix? \n");

    int matrix3[100][100], row, column, j;

    printf("Enter The Number Of Rows And Columns: ");
    scanf("%d %d",&row, &column);

    printf("Enter Elements Of Matrix: \n");
    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            printf("Enter Element a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrix3[i][j]);
        }
    }

    printf("Entered Matrix: \n");
    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            printf("%d      ", matrix3[i][j]);
        }
        printf("\n");
    }


    printf("Transpose Of Matrix: \n");
    for(i = 0; i < column; i++){
        for(j = 0; j < row; j++){
            printf("%d      ", matrix3[j][i]);
        }
        printf("\n\n");
    } 

    
// ###########################################################################################

     printf("Program-4 \n");
    printf("C Program To Insert An Element In An Array? \n\n");

    int arr[100], ele, location;
    n = 0;

    printf("Enter Number Of Elements: ");
    scanf("%d", &n);
    
    printf("Enter Basic Array Elements: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter Element To Be Inserted: ");
    scanf("%d", &ele);
    printf("Enter The Location: ");
    scanf("%d", &location);

    arr[n + 1] = ele;

    i = n + 1;
    while(i != location - 1){
        int prev = arr[i - 1];
        arr[i - 1] = ele;
        arr[i] = prev;
        i--;
    };

    for(i = 0; i < n + 1; i++){
        printf("%d  ", arr[i]);
    }

    printf("\n\n"); 
    
// ###########################################################################################


     printf("Program-5: \n");
    printf("C Program To Search An Element In An Array? \n\n");

    int nums[100], searchNum, flag = 0;

    printf("Enter Number Of Elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        nums[i] = 11 * (i + 1);
        printf("%d  ", nums[i]);
    }
    printf("\n");

    printf("Enter Elements To Be Searched: ");
    scanf("%d", &searchNum);

    for(i = 0; i < n; i++){
        if(nums[i] == searchNum){
            printf("Number Found At The Location = %d", i + 1);
            flag = 1;
            break;
        }
    }

    if(!flag){
        printf("Number Not Found In The List !!");
    }

    printf("\n\n"); 
    
// ###########################################################################################

    return 0;
}