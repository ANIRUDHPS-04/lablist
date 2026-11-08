/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 07
DATE: 16-07-2026

**********Implementation  of  doubly  linkedlist**********

AIM: Create a program that allows Implementation  of  doubly  linkedlist
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Initialize head = NULL.
Step 3: Display the menu and read the user's choice.
Step 4: Perform the selected operation:
      1. Insert at Beginning: Create a new node and insert it before the first node.
      2. Insert at End: Create a new node and insert it after the last node.
      3. Delete at Beginning: Remove the first node and update head.
      4. Delete at End: Remove the last node.
      5. Display Forward: Traverse and display nodes from first to last.
      6. Display Backward: Traverse and display nodes from last to first.
      7. Exit: Terminate the program.
Step 5: Repeat the menu until the user selects Exit.
Step 6: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void insert_begin()
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
}

void insert_end()
{
    struct Node *newnode, *temp;
    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

void delete_begin()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

void delete_end()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if (temp->next == NULL)
    {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

void display_forward()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Forward: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void display_backward()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Delete at Beginning");
        printf("\n4. Delete at End");
        printf("\n5. Display Forward");
        printf("\n6. Display Backward");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert_begin();
                break;

            case 2:
                insert_end();
                break;

            case 3:
                delete_begin();
                break;

            case 4:
                delete_end();
                break;

            case 5:
                display_forward();
                break;

            case 6:
                display_backward();
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);

    return 0;
}

/*  OUTPUT 

1. Insert at Beginning
2. Insert at End
3. Delete at Beginning
4. Delete at End
5. Display Forward
6. Display Backward
7. Exit
Enter your choice: 1
Enter data: 10

Enter your choice: 2
Enter data: 20

Enter your choice: 2
Enter data: 30

Enter your choice: 5
Forward: 10 20 30

Enter your choice: 6
Backward: 30 20 10

Enter your choice: 7
Exiting...

*/
