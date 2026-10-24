/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 11
DATE: 25-09-2026

**********Implementation  of  quick  sort**********

AIM: Create a program that allows Implementation  of  quick  sort
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Read the number of elements n and the array elements.
Step 3: Call quicksort(a, 0, n-1).
Step 4: If low < high, set the first element as the pivot.
Step 5: Initialize i = low and j = high.
Step 6: Move i to the right until an element greater than the pivot is found.
Step 7: Move j to the left until an element less than or equal to the pivot is found.
Step 8: If i < j, swap a[i] and a[j].
Step 9: Repeat Steps 6–8 until i >= j.
Step 10: Swap the pivot element a[low] with a[j].
Step 11: Recursively apply Quick Sort to the left subarray, from low to j-1.
Step 12: Recursively apply Quick Sort to the right subarray, from j+1 to high.
Step 13: Display the sorted array.
Step 14: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>

void quicksort(int a[], int low, int high)
{
    int i, j, pivot, temp;

    if (low < high)
    {
        pivot = a[low];
        i = low;
        j = high;

        while (i < j)
        {
            while (a[i] <= pivot && i < high)
                i++;

            while (a[j] > pivot)
                j--;

            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[low];
        a[low] = a[j];
        a[j] = temp;

        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
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

    quicksort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

/*  OUTPUT

Enter the number of elements: 5
Enter the elements:
45 12 67 23 9
Sorted array:
9 12 23 45 67

*/
