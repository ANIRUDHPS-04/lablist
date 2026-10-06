#include <stdio.h>

int main()
{
    int tree[100];
    int n, i, level, start, end, j;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &tree[i]);
    }

    printf("\nBinary Tree:\n\n");

    level = 0;
    start = 0;

    while(start < n)
    {
        end = (2 * start + 1);

        if(end > n)
            end = n;

        /* Spaces before each level */
        for(i = 0; i < (4 - level) * 2; i++)
            printf(" ");

        for(j = start; j < end; j++)
        {
            printf("%d", tree[j]);

            if(j < end - 1)
                printf("      ");
        }

        printf("\n\n");

        start = end;
        level++;
    }

    return 0;
}
