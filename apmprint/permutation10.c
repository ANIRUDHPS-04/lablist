/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 10
DATE: 29-08-2026 

**********Permutation Generator for Password Cracking Simulation**********

AIM: Write a program that generates all possible permutations of a given string, which could simulate a 
     password-cracking tool for security testing.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a character array str to store the input string.
Step 3: Read the string from the user.
Step 4: Find the length of the string.
Step 5: Call the permute() function with start = 0 and end = length - 1.
Step 6: In the permute() function, check whether start == end.
Step 7: If start == end, print the current permutation and return.
Step 8: Otherwise, select each character from start to end one by one.
Step 9: Swap the selected character with the character at the start position.
Step 10: Recursively call permute() for the next position.
Step 11: Swap the characters back to their original positions using backtracking.
Step 12: Repeat the process until all possible permutations are generated.
Step 13: Stop.

*/

/* **********SOURCE CODE********** */
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char str[], int start, int end)
{
    int i;

    if (start == end)
    {
        printf("%s\n", str);
        return;
    }

    for (i = start; i <= end; i++)
    {
        swap(&str[start], &str[i]);
        permute(str, start + 1, end);
        swap(&str[start], &str[i]);  // backtracking
    }
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%99s", str);

    printf("All permutations:\n");
    permute(str, 0, strlen(str) - 1);

    return 0;
}

/* **********OUTPUT**********

Enter a string: ABC
All permutations:
ABC
ACB
BAC
BCA
CBA
CAB

*/
