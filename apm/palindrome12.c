/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 12
DATE: 28-09-2026

**********Text Reversal Tool for Document Review**********

AIM: Write a program that checks if a document (string) is a palindrome by reversing it manually without using 
     built-in functions. This tool could be used for reviewing documents that need to maintain symmetry.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare character arrays str and rev, and variables i, len, and same.
Step 3: Read the document/string from the user.
Step 4: Find the length of the string manually using a while loop.
Step 5: Reverse the string manually and store it in rev.
Step 6: Add the null character '\0' at the end of the reversed string.
Step 7: Compare the original string with the reversed string character by character.
Step 8: If any character is different, set same = 0.
Step 9: Display the reversed document.
Step 10: If same = 1, display that the document is a palindrome.
Step 11: Otherwise, display that the document is not a palindrome.
Step 12: Stop.

*/

/* **********SOURCE CODE********** */
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

/* **********OUTPUT**********

Enter a document: madam
Reversed document: madam
The document is a palindrome.

*/
