#include <stdio.h>

void reverseSentence()
{
    char c;
    printf("Here\n");
    scanf("%c", &c);

    if (c != '\n')
    {
        reverseSentence();
        printf("%c", c);
    }
}

int main()
{
    printf("Program-3\n\n");
    printf("EX3: C Program To Reverse A Sentence Using Recursion: \n");

    printf("Enter a sentence: ");
    reverseSentence();

    printf("\n");
    return 0;
}
