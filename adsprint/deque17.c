/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 17
DATE: 25-09-2026

**********Implementation  of  Deque (double ended  queue)**********

AIM: Create a program that allows Implementation  of  Deque (double ended  queue)
*/

/* **********ALGORITHM**********

Step 1: Start.

Step 2: Initialize front = -1 and rear = -1.

Step 3: Display the menu:
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Display
6. Exit
Step 4: Read the user's choice.

Step 5: Perform the selected operation:

      - Insert at Front:
      - Check whether the deque is full.
      - If empty, set front = rear = 0.
      - Otherwise, update front circularly.
      - Insert the element at the front.
      - Insert at Rear:
      - Check whether the deque is full.
      - If empty, set front = rear = 0.
      - Otherwise, update rear circularly.
      - Insert the element at the rear.
      - Delete from Front:
      - Check whether the deque is empty.
      - If empty, display an underflow message.
      - Otherwise, delete the front element and update front.
      - If it was the last element, set front = rear = -1.
      - Delete from Rear:
      - Check whether the deque is empty.
      - If empty, display an underflow message.
      - Otherwise, delete the rear element and update rear.
      - If it was the last element, set front = rear = -1.
      - Display:
      - If the deque is empty, display an appropriate message.
      - Otherwise, display all elements from front to rear, considering circular positions.
      - Exit:
      - Terminate the program.
Step 6: Repeat Steps 3–5 until the user selects Exit.

Step 7: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront()
{
    int x;

    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Deque is Full\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &x);

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }

    deque[front] = x;
    printf("Inserted at front\n");
}

void insertRear()
{
    int x;

    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Deque is Full\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &x);

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = x;
    printf("Inserted at rear\n");
}

void deleteFront()
{
    if (front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted element: %d\n", deque[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if (front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted element: %d\n", deque[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque elements: ");
    i = front;

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}

/*  OUTPUT

--- DEQUE MENU ---
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Display
6. Exit
Enter your choice: 2
Enter value: 10
Inserted at rear

Enter your choice: 2
Enter value: 20
Inserted at rear

Enter your choice: 1
Enter value: 5
Inserted at front

Enter your choice: 5
Deque elements: 5 10 20

Enter your choice: 3
Deleted element: 5

Enter your choice: 5
Deque elements: 10 20

Enter your choice: 6
Exiting...

*/
