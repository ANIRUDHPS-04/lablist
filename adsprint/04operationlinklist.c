/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 04
DATE: 13-07-2026

**********Implementation  of  linkedlists  and  operations  on  linkedlists**********

AIM: Create a program that allows Implementation  of  linkedlists  and  operations  on  linkedlists
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Define a node structure containing data and a pointer next.
Step 3: Initialize head = NULL.
Step 4: Display the menu and read the user's choice.
Step 5: Perform the selected operation:
  1. Insert at Beginning
     1. Create a new node using malloc().
     2. Read data from the user.
     3. Set newNode->next = head.
     4. Update head = newNode.
  2. Insert at End
     1. Create a new node and read data.
     2. Set newNode->next = NULL.
     3. If the list is empty, make the new node the head.
     4. Otherwise, traverse to the last node.
     5. Link the last node to the new node.
  3. Delete from Beginning
     1. Check whether the list is empty.
     2. Store the first node in a temporary pointer.
     3. Move head to the next node.
     4. Free the deleted node.
  4. Delete from End
     1. Check whether the list is empty.
     2. If only one node exists, delete it and set head = NULL.
     3. Otherwise, traverse to the last node.
     4. Set the previous node's next = NULL.
     5. Free the last node.
  5. Display
     1. Check whether the list is empty.
     2. Start traversal from head.
     3. Display each node's data.
     4. Move to the next node until NULL is reached.
  6. Exit
Terminate the program.
Step 6: Repeat the menu until the user selects Exit.
Step 7: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert at beginning */
void insertBeginning()
{
    struct Node *newNode;
    
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;
}

/* Insert at end */
void insertEnd()
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

/* Delete from beginning */
void deleteBeginning()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);
}

/* Delete from end */
void deleteEnd()
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

/* Display */
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- LINKED LIST OPERATIONS ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

/* OUTPUT
 
--- LINKED LIST OPERATIONS ---
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display
6. Exit
Enter your choice: 2
Enter data: 10

--- LINKED LIST OPERATIONS ---
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display
6. Exit
Enter your choice: 2
Enter data: 20

--- LINKED LIST OPERATIONS ---
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display
6. Exit
Enter your choice: 1
Enter data: 5

--- LINKED LIST OPERATIONS ---
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display
6. Exit
Enter your choice: 5
Linked List: 5 -> 10 -> 20 -> NULL

--- LINKED LIST OPERATIONS ---
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display
6. Exit
Enter your choice: 3

--- LINKED LIST OPERATIONS ---
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display
6. Exit
Enter your choice: 5
Linked List: 10 -> 20 -> NULL

--- LINKED LIST OPERATIONS ---
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display
6. Exit
Enter your choice: 4

--- LINKED LIST OPERATIONS ---
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display
6. Exit
Enter your choice: 5
Linked List: 10 -> NULL

--- LINKED LIST OPERATIONS ---
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display
6. Exit
Enter your choice: 6
*/
