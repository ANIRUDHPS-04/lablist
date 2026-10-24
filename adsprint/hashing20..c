/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 20
DATE: 25-09-2026

**********Implementation  of  hashing  using  separate  chaining**********

AIM: Create a program that allows Implementation  of  hashing  using  separate  chaining
*/

/* **********ALGORITHM**********

Step 1: Start.

Step 2: Initialize a hash table of size 10 with all entries set to NULL.

Step 3: Display the menu:
1. Insert
2. Search
3. Display
4. Exit
Step 4: Read the user's choice.

Step 5: If the choice is Insert:
        - Read the element.
        - Calculate the hash index using index = key % SIZE.
        - Create a new node containing the element.
        - Insert the node at the beginning of the linked list at that index.
        - Display the insertion message.
Step 6: If the choice is Search:
        - Read the element to be searched.
        - Calculate its hash index.
        - Traverse the linked list at that index.
        - If the element is found, display the index; otherwise, display "Element not found."
Step 7: If the choice is Display:
        - Traverse each index of the hash table.
        - Display all elements in the linked list at each index.
Step 8: If the choice is Exit, terminate the program.

Step 9: Otherwise, display "Invalid choice."

Step 10: Repeat Steps 3–9 until the user chooses Exit.

Step 11: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node
{
    int data;
    struct Node *next;
};

struct Node *hashTable[SIZE];

int hash(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hash(key);

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    printf("Element inserted successfully.\n");
}

void search(int key)
{
    int index = hash(key);
    struct Node *temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element found at index %d.\n", index);
            return;
        }
        temp = temp->next;
    }

    printf("Element not found.\n");
}

void display()
{
    int i;
    struct Node *temp;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d: ", i);
        temp = hashTable[i];

        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int choice, key;

    while (1)
    {
        printf("\n--- HASHING MENU ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

/* OUTPUT

--- HASHING MENU ---
1. Insert
2. Search
3. Display
4. Exit
Enter your choice: 1
Enter element: 25
Element inserted successfully.

--- HASHING MENU ---
1. Insert
2. Search
3. Display
4. Exit
Enter your choice: 1
Enter element: 15
Element inserted successfully.

--- HASHING MENU ---
1. Insert
2. Search
3. Display
4. Exit
Enter your choice: 1
Enter element: 7
Element inserted successfully.

--- HASHING MENU ---
1. Insert
2. Search
3. Display
4. Exit
Enter your choice: 3

Hash Table:
0: NULL
1: NULL
2: NULL
3: NULL
4: NULL
5: 15 -> 25 -> NULL
6: NULL
7: 7 -> NULL
8: NULL
9: NULL

*/
