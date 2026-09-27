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
