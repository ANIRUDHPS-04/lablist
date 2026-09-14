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
