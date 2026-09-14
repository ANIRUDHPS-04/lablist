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

//Output
/*
Enter a string: ABC
All permutations:
ABC
ACB
BAC
BCA
CBA
CAB
*/
