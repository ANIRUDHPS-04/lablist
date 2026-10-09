/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 05
DATE: 23-07-2026 

**********Data Cleaning Utility: Remove Duplicates**********

AIM: Create a program that takes a list of customer email addresses (stored in an array) and removes any 
     duplicates, ensuring that each email address is only represented once.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Define a function validEmail() to check whether an email address is valid.
Step 3: Read the number of customers n.
Step 4: Declare a 2D character array email[n][100] to store the email addresses.
Step 5: Read each customer's email address.
Step 6: Check whether the email contains exactly one @ symbol.
Step 7: Check that @ is not the first character and that there is text after @.
Step 8: Check whether a . is present after the @ symbol.
Step 9: If the email is invalid, display "Invalid Email! Enter again." and ask the user to enter it again.
Step 10: Compare each email address with the remaining email addresses character by character.
Step 11: If two email addresses are identical, remove the duplicate by shifting the remaining addresses one position to the left.
Step 12: Decrease the value of n after removing a duplicate.
Step 13: Repeat the comparison until all duplicate email addresses are removed.
Step 14: Display the email addresses after removing duplicates.
Step 15: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>

int validEmail(char email[])
{
    int i = 0;
    int at = 0;
    int dot = 0;
    int atPos = -1;

    while(email[i] != '\0')
    {
        /* Check @ */
        if(email[i] == '@')
        {
            at++;
            atPos = i;
        }

        i++;
    }

    /* Exactly one @ is required */
    if(at != 1)
        return 0;

    /* @ cannot be first */
    if(atPos == 0)
        return 0;

    /* Check characters after @ */
    i = atPos + 1;

    if(email[i] == '\0')
        return 0;

    while(email[i] != '\0')
    {
        if(email[i] == '.')
        {
            dot = 1;
        }

        i++;
    }

    /* Dot must be present after @ */
    if(dot == 0)
        return 0;

    return 1;
}

int main()
{
    int n, i, j, k;
    int same;

    printf("Enter the Number of Customers: ");
    scanf("%d", &n);

    char email[n][100];

    printf("Enter Customers Addresses:\n");

    for(i = 0; i < n; i++)
    {
        do
        {
            printf("Customer %d: ", i + 1);
            scanf("%99s", email[i]);

            if(!validEmail(email[i]))
            {
                printf("Invalid Email! Enter again.\n");
            }

        } while(!validEmail(email[i]));
    }

    /* Remove Duplicates */

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            same = 1;
            k = 0;

            /* Compare character by character */
            while(email[i][k] != '\0' || email[j][k] != '\0')
            {
                if(email[i][k] != email[j][k])
                {
                    same = 0;
                    break;
                }

                k++;
            }

            if(same == 1)
            {
                /* Shift elements to the left */
                for(k = j; k < n - 1; k++)
                {
                    int x = 0;

                    while(email[k + 1][x] != '\0')
                    {
                        email[k][x] = email[k + 1][x];
                        x++;
                    }

                    email[k][x] = '\0';
                }

                n--;
                j--;
            }
        }
    }

    printf("\nEmail Addresses after Removing Duplicates:\n");

    for(i = 0; i < n; i++)
    {
        printf("%s\n", email[i]);
    }

    return 0;
}

/* **********OUTPUT**********

Enter the Number of Customers: 5

Enter Customers Addresses:
Customer 1: anirudh@gmail.com
Customer 2: test@gmail.com
Customer 3: hello
Invalid Email! Enter again.
Customer 3: hello@yahoo.com
Customer 4: anirudh@gmail.com
Customer 5: student@college.in

Email Addresses after Removing Duplicates:
anirudh@gmail.com
test@gmail.com
hello@yahoo.com
student@college.in

*/    
