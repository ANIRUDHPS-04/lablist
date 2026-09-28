/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 13
DATE: 

**********Text Editor: Substring Insertion**********

AIM: Create a text editor program that allows a user to insert a given substring at a specified position within an 
     existing string of text. This tool can help in editing and updating documents or code.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare character arrays str and sub to store the original string and substring.
Step 3: Read the original string from the user.
Step 4: Read the substring to be inserted.
Step 5: Read the position where the substring should be inserted.
Step 6: Find the length of the original string.
Step 7: Remove the newline character from the original string and substring.
Step 8: Shift the characters of the original string to the right to create space for the substring.
Step 9: Insert the substring at the specified position.
Step 10: Display the updated string.
Step 11: Stop.

*/

/* **********SOURCE CODE********** */
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], sub[50];
    int pos, i, len;

    printf("Enter the original string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the substring to insert: ");
    fgets(sub, sizeof(sub), stdin);

    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    len = strlen(str);

    // Remove newline from strings
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';

    len = strlen(sub);
    if (sub[len - 1] == '\n')
        sub[len - 1] = '\0';

    // Shift original string to the right
    for (i = strlen(str); i >= pos; i--)
        str[i + strlen(sub)] = str[i];

    // Insert substring
    for (i = 0; sub[i] != '\0'; i++)
        str[pos + i] = sub[i];

    printf("Updated text: %s\n", str);

    return 0;
}

/* **********OUTPUT**********

Enter the original string: Hello World
Enter the substring to insert: Beautiful 
Enter the position to insert: 6

Updated text: Hello Beautiful World

*/
