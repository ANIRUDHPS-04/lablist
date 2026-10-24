
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
