/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 14
DATE: 

**********Recursion-Based Sentence Reversal for Voice Transcription**********

AIM: Write a program that reverses the words of a sentence, using recursion. This could be applied in a speech-
     to-text application where the order of words needs to be reversed for analysis.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a character array str[200].
Step 3: Read a sentence from the user.
Step 4: Remove the newline character from the sentence.
Step 5: Find the length of the sentence.
Step 6: Call the reverseWords() function with the starting position and ending position.
Step 7: Find the end of the current word by searching for a space.
Step 8: If the end of the string is reached, print the current word and return.
Step 9: Otherwise, recursively call the function for the remaining words.
Step 10: Print the current word after the recursive function returns.
Step 11: Repeat the process until all words are printed in reverse order.
Step 12: Stop.

*/

/* **********SOURCE CODE********** */

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
