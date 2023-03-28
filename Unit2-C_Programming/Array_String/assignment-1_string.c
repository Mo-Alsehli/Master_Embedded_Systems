#include <stdio.h>
#include <string.h>


int main() {

     printf("--------- String Exercises --------- \n\n");
    printf("Program-1: \n");
    printf("C Program To Find The Frequency Of Characters In A String? \n\n");

    char str[100], ch;
    int freq = 0, i, j;

    printf("Enter A String: ");
    scanf("%[^\n]%*c", str);

    printf("Enter A Character To Find Frequency: ");
    scanf(" %c", &ch);

    for(i = 0; i < strlen(str); i++){
        if(str[i] == ch){
            freq++;
        }
    }

    printf("Frequency Of %c = %d", ch, freq);

    printf("\n\n"); 
    
// ###########################################################################################

     printf("Program-2: \n");
    printf("C Program To Find The Length Of A String? \n\n");

    char str1[100];
    int length = 0;

    printf("Enter A String: ");
    scanf("%s", str1);

    while(str1[length] != '\0'){
        length++;
    }

    printf("Length Of String: %d", length);

    printf("\n \n"); 
        
// ###########################################################################################

    printf("Program-3: \n");
    printf("C Program To Reverse String Without Using Liberary Function? \n\n");

    char originalStr[100], reversed[100];

    printf("Enter A String: ");
    scanf(" %s", originalStr);

    for(i = strlen(originalStr) - 1, j = 0; i >= 0; i--, j++){
        reversed[j] = originalStr[i];
    } 

    printf("Reversed String Is: %s", reversed);
    
    printf("\n");



    return 0;
}