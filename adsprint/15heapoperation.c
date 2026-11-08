/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 15
DATE: 25-09-2026

**********Implementation  of  heap  tree  and  operations**********

AIM: Create a program that allows Implementation  of  heap  tree  and  operations
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Initialize an empty heap with n = 0 and MAX = 100.
Step 3: Display the menu and read the user's choice.
Step 4: Perform the operation based on the choice:
  1. Insert
     1. Check whether the heap is full.
     2. Read the value from the user.
     3. Insert the value at the end of the heap.
     4. Compare it with its parent node.
     5. Swap if the child is greater than the parent.
     6. Repeat until the Max Heap property is satisfied.
  2. Delete Maximum
     1. Check whether the heap is empty.
     2. Delete the root element (maximum value).
     3. Replace the root with the last element.
     4. Reduce the heap size by one.
     5. Compare the root with its children.
     6. Swap with the largest child until the Max Heap property is restored.
  3. Display
     1. Check whether the heap is empty.
     2. Display all heap elements.
  4. Exit
Terminate the program.
Step 5: Repeat the menu until the user selects Exit.
Step 6: Stop.
*/

/* **********SOURCE CODE********** */

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

/* OUTPUT

--- MAX HEAP MENU ---
1. Insert
2. Delete Maximum
3. Display
4. Exit

Enter your choice: 1
Enter value: 50
Element inserted successfully.

Enter your choice: 1
Enter value: 30
Element inserted successfully.

Enter your choice: 1
Enter value: 70
Element inserted successfully.

Enter your choice: 1
Enter value: 20
Element inserted successfully.

Enter your choice: 3
Heap elements: 70 30 50 20

Enter your choice: 2
Deleted element: 70

Enter your choice: 3
Heap elements: 50 30 20

Enter your choice: 4

*/
