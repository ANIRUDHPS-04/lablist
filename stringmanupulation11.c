#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str1[100], str2[100], result[200];
    int i;

    printf("Enter first string: ");
    fgets(str1, 100, stdin);

    printf("Enter second string: ");
    fgets(str2, 100, stdin);

    // Remove newline character
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Concatenation
    strcpy(result, str1);
    strcat(result, str2);

    printf("\n--- String Operations ---\n");
    printf("Concatenation: %s\n", result);

    // Comparison
    if (strcmp(str1, str2) == 0)
        printf("Comparison: Strings are equal\n");
    else
        printf("Comparison: Strings are not equal\n");

    // Convert first string to lowercase
    for (i = 0; str1[i] != '\0'; i++)
        str1[i] = tolower(str1[i]);

    printf("First string in lowercase: %s\n", str1);

    // Convert second string to uppercase
    for (i = 0; str2[i] != '\0'; i++)
        str2[i] = toupper(str2[i]);

    printf("Second string in uppercase: %s\n", str2);

    return 0;
}

//Output
/*
Enter first string: HELLO
Enter second string: world

--- String Operations ---
Concatenation: HELLOworld
Comparison: Strings are not equal
First string in lowercase: hello
Second string in uppercase: WORLD
*/
