
#include <stdio.h>

#define MAX 100

int heap[MAX];
int n = 0;

void insert()
{
    int value, i, temp;

    if (n == MAX)
    {
        printf("Heap is full!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    i = n;
    heap[n] = value;
    n++;

    while (i > 0 && heap[(i - 1) / 2] < heap[i])
    {
        temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }

    printf("Element inserted successfully.\n");
}

void deleteMax()
{
    int i = 0, left, right, largest, temp;

    if (n == 0)
    {
        printf("Heap is empty!\n");
        return;
    }

    printf("Deleted element: %d\n", heap[0]);

    heap[0] = heap[n - 1];
    n--;

    while (1)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;

        if (left < n && heap[left] > heap[largest])
            largest = left;

        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        i = largest;
    }
}

void display()
{
    int i;

    if (n == 0)
    {
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- MAX HEAP MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete Maximum\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                deleteMax();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
