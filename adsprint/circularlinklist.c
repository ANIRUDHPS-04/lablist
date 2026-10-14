
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

