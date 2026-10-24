/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 12
DATE: 25-09-2026

**********Implementation  of  heap  sort**********

AIM: Create a program that allows Implementation  of  heap  sort
*/

/* **********ALGORITHM**********

Step 1: Start.

Step 2: Read the number of elements n.

Step 3: Read the n elements into array a.

Step 4: Build a max heap by calling heapify() from index n/2 - 1 down to 0.

Step 5: Repeat for i = n - 1 down to 1:
- Swap the first element a[0] with a[i].
- Reduce the heap size to i.
- Call heapify(a, i, 0) to maintain the max heap.
Step 6: Display the sorted array in ascending order.

Step 7: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    heapSort(a, n);

    printf("Sorted elements:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

/*  OUTPUT

Enter the number of elements: 5
Enter the elements:
40 10 30 50 20
Sorted elements:
10 20 30 40 50

*/
