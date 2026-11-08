/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 03
DATE: 25-09-2026

**********Implementation  of  circular  queue  using  arrays**********

AIM: Create a program that allows Implementation  of  circular  queue  using  arrays
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare an array queue[MAX] and initialize front = -1 and rear = -1.
Step 3: Display the menu and read the user's choice.
Step 4: Perform the selected operation:
  1. Enqueue (Insertion)
     1. Check whether the queue is full using the circular queue condition.
     2. If full, display "Queue is Full".
     3. Otherwise, read the value from the user.
     4. If the queue is empty, set front = rear = 0.
     5. Otherwise, update rear = (rear + 1) % MAX.
     6. Insert the value at queue[rear].
  2. Dequeue (Deletion)
     1. Check whether the queue is empty.
     2. If empty, display "Queue is Empty".
     3. Otherwise, delete the element at front.
     4. If front == rear, set both to -1.
     5. Otherwise, update front = (front + 1) % MAX.
  3. Display
     1. Check whether the queue is empty.
     2. Start from front.
     3. Display each element until rear is reached.
     4. Move to the next position using circular increment.
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
    int value;

    if ((rear + 1) % MAX == front)
    {
        printf("Queue is Full\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("%d inserted\n", value);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("%d deleted\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- CIRCULAR QUEUE ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
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

    return 0;
}

/*  OUTPUT

--- CIRCULAR QUEUE ---
1. Enqueue
2. Dequeue
3. Display
4. Exit

Enter your choice: 1
Enter value: 10
10 inserted

Enter your choice: 1
Enter value: 20
20 inserted

Enter your choice: 1
Enter value: 30
30 inserted

Enter your choice: 3
Queue: 10 20 30

Enter your choice: 2
10 deleted

Enter your choice: 3
Queue: 20 30

Enter your choice: 4

*/
