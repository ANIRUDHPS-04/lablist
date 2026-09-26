#include <stdio.h>
#include <string.h>

void reverseWords(char str[], int start, int end)
{
    int i;

    // Find the end of the current word
    for (i = start; i < end && str[i] != ' '; i++);

    if (i == end)
    {
        printf("%.*s", end - start, str + start);
        return;
    }

    // Recursively process the remaining words
    reverseWords(str, i + 1, end);

    printf(" %.*s", i - start, str + start);
}

int main()
{
    char str[200];

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Reversed sentence: ");
    reverseWords(str, 0, strlen(str));

    return 0;
}

//Output
/*

Enter a sentence: I love computer science
Reversed sentence: science computer love I

*/
