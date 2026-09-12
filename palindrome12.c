#include <stdio.h>

int main()
{
    char str[100], rev[100];
    int i = 0, len = 0, same = 1;

    printf("Enter a document: ");
    scanf("%s", str);

    // Find length manually 
    while (str[len] != '\0')
        len++;

    // Reverse manually 
    for (i = 0; i < len; i++)
        rev[i] = str[len - i - 1];

    rev[len] = '\0';

    // Compare manually 
    for (i = 0; i < len; i++)
    {
        if (str[i] != rev[i])
        {
            same = 0;
            break;
        }
    }

    printf("Reversed document: %s\n", rev);

    if (same)
        printf("The document is a palindrome.\n");
    else
        printf("The document is not a palindrome.\n");

    return 0;
}
