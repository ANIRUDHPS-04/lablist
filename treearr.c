#include <stdio.h>

#define SIZE 100

int tree[SIZE];

void insert(int value)
{
    int i = 0;

    while (i < SIZE)
    {
        if (tree[i] == -1)
        {
            tree[i] = value;
            return;
        }

        if (value < tree[i])
            i = 2 * i + 1;
        else
            i = 2 * i + 2;
    }
}

void display(int index, int space)
{
    int i;

    if (index >= SIZE || tree[index] == -1)
        return;

    // Display right subtree first
    display(2 * index + 2, space + 5);

    // Print spaces
    for (i = 0; i < space; i++)
        printf(" ");

    printf("%d\n", tree[index]);

    // Display left subtree
    display(2 * index + 1, space + 5);
}

int main()
{
    int n, value, i;

    // Initialize array
    for (i = 0; i < SIZE; i++)
        tree[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert(value);
    }

    printf("\nBST:\n\n");

    display(0, 0);

    return 0;
}