/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 02
DATE: 05-07-2026

**********Implementation  of  queues  using  arrays**********

AIM: Create a program that allows Implementation  of  queues  using  arrays
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare an array queue[MAX] and initialize front = -1 and rear = -1.
Step 3: Display the menu and read the user's choice.
Step 4: Perform the selected operation:
  1. Enqueue (Insertion)
     1. Check whether rear == MAX - 1.
     2. If true, display "Queue Overflow".
     3. Otherwise, read an element from the user.
     4. If the queue is empty, set front = 0.
     5. Insert the element at queue[++rear].
  2. Dequeue (Deletion)
     1. Check whether the queue is empty.
     2. If empty, display "Queue Underflow".
     3. Otherwise, delete the element at the front.
     4. Increment front by one.
     5. If all elements are deleted, set front = rear = -1.
  3. Display
     1. Check whether the queue is empty.
     2. If empty, display "Queue is empty".
     3. Otherwise, traverse from front to rear.
     4. Display all queue elements.
  4. Exit
Terminate the program.
Step 5: Repeat the menu until the user selects Exit.
Step 6: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int item;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &item);

    if (front == -1)
        front = 0;

    queue[++rear] = item;
    printf("Element inserted successfully\n");
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front++]);

    if (front > rear)
        front = rear = -1;
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break; 

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

/*  OUTPUT

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter element: 10
Element inserted successfully

Enter your choice: 1
Enter element: 20
Element inserted successfully

Enter your choice: 3
Queue elements: 10 20

Enter your choice: 2
Deleted element: 10

Enter your choice: 3
Queue elements: 20
*/
