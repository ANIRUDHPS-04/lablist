/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 01
DATE: 

**********Character Analysis Tool**********

AIM: Write a program to develop a simple text analysis tool that takes an input string and categorizes each 
     character as a vowel, consonant, or other (special character, number, etc.) using a switch statement.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a character array str[100] and initialize counters for vowels, consonants, digits, and punctuation.
Step 3: Read a string from the user using fgets().
Step 4: Traverse each character of the string.
Step 5: Convert the character to lowercase using tolower().
Step 6: Check whether the character is an alphabet using isalpha().
Step 7: If it is an alphabet, check whether it is a, e, i, o, or u.
Step 8: If it is a vowel, display Vowel and increment the vowel counter.
Step 9: Otherwise, display Consonant and increment the consonant counter.
Step 10: If the character is a digit, display Digit and increment the digit counter.
Step 11: If the character is a punctuation character, display Others and increment the punctuation counter.
Step 12: Repeat the process for all characters in the string.
Step 13: Display the total number of vowels, consonants, digits, and other characters.
Step 14: Stop.

*/

/* **********SOURCE CODE********** */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int vowel = 0, consonant = 0, digit = 0, punct = 0;

    printf("Enter the String: ");
    fgets(str, 100, stdin);

    printf("\nCharacter Breakdown:\n");

    for(int i = 0; i < strlen(str); i++)
    {
        char c = tolower(str[i]);

        if(isalpha(str[i]))
        {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                printf("%c - Vowel\n", str[i]);
                vowel++;
            }
            else
            {
                printf("%c - Consonant\n", str[i]);
                consonant++;
            }
        }
        else if(isdigit(str[i]))
        {
            printf("%c - Digit\n", str[i]);
            digit++;
        }
        else if(ispunct(str[i]))
        {
            printf("%c - Others\n", str[i]);
            punct++;
        }
    }

    printf("\nSummary: %d Vowels, %d Consonants, %d Digits, %d Others\n",
           vowel, consonant, digit, punct);

    return 0;
}

//Output
/*
Enter the String: ani@1

Character Breakdown:
a - Vowel
n - Consonant
i - Vowel
@ - Others
1 - Digit

Summary: 2 Vowels, 1 Consonants, 1 Digits, 1 Others
*/
