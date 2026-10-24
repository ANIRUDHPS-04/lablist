
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
