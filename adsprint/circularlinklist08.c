/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 08
DATE: 25-09-2026

**********Implementation  of  circular  linkedlist**********

AIM: Create a program that allows Implementation  of  circular  linkedlist
*/

/* **********ALGORITHM**********

Step 1: Start the program.
Step 2: Initialize last = NULL to indicate that the circular linked list is empty.
Step 3: Display the menu with the following options:
1. Insert
2. Delete
3. Display
4. Exit
Step 4: Read the user's choice.
Step 5: If the choice is Insert:
      - Allocate memory for a new node.
      - Read the data.
      - If the list is empty, make last point to the new node and set last->next = last.
      - Otherwise, set newnode->next = last->next and last->next = newnode.
      - Display the insertion success message.
Step 6: If the choice is Delete:
      - If the list is empty, display "List is empty."
      - Otherwise, store the first node in temp.
      - If the list contains only one node, set last = NULL.
      - Otherwise, update last->next = temp->next.
      - Display the deleted element and free the memory occupied by temp.
Step 7: If the choice is Display:
      - If the list is empty, display "List is empty."
      - Otherwise, start from the first node (last->next).
      - Display each node's data until the traversal returns to the first node.
      - Display "(back to first node)" to indicate the circular connection.
Step 8: If the choice is Exit, display "Exiting program."
Step 9: If the choice is invalid, display "Invalid choice."
Step 10: Repeat Steps 3–9 until the user chooses Exit.
Step 11: Stop the program.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *last = NULL;

void insert()
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (last == NULL)
    {
        last = newnode;
        last->next = last;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
    }

    printf("Node inserted successfully.\n");
}

void delete()
{
    struct Node *temp;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    if (temp == last)
    {
        last = NULL;
    }
    else
    {
        last->next = temp->next;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void display()
{
    struct Node *temp;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to first node)\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
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
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

/*  OUTPUT

--- Circular Linked List Menu ---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter data: 10
Node inserted successfully.

--- Circular Linked List Menu ---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter data: 20
Node inserted successfully.

--- Circular Linked List Menu ---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter data: 30
Node inserted successfully.

--- Circular Linked List Menu ---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 3
Circular Linked List: 30 -> 20 -> 10 -> (back to first node)

--- Circular Linked List Menu ---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 2
Deleted element: 30

--- Circular Linked List Menu ---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 3
Circular Linked List: 20 -> 10 -> (back to first node)

--- Circular Linked List Menu ---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 4
Exiting program.

*/
