/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 05
DATE: 13-07-2026

**********Implementation  of  stacks  using  linkedlist**********

AIM: Create a program that allows Implementation  of  stacks  using  linkedlist
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Define a node structure containing data and a pointer next.
Step 3: Initialize the top pointer as top = NULL.
Step 4: Display the menu with the following operations:
- Push
- Pop
- Peek
- Display
- Exit
Step 5: Read the user's choice.
Step 6: Perform the selected operation:
  1. Push Operation
    1. Create a new node using malloc().
    2. Read the value from the user.
    3. Store the value in the new node.
    4. Set newNode->next = top.
    5. Update top = newNode.
  2. Pop Operation
    1. Check whether top == NULL.
    2. If empty, display "Stack Underflow".
    3. Otherwise, store the top node in a temporary pointer.
    4. Move top to the next node.
    5. Free the deleted node using free().
  3. Peek Operation
    1. Check whether the stack is empty.
    2. If empty, display "Stack is empty".
    3. Otherwise, display the top element.
  4. Display Operation
    1. Check whether the stack is empty.
    2. Start traversal from top.
    3. Display each node's data.
    4. Move to the next node until NULL is reached.
  5. Exit Operation
Terminate the program.
Step 7: Repeat the menu until the user selects Exit.
Step 8: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push operation
void push(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack.\n", value);
}

// Pop operation
void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }

    temp = top;
    printf("%d popped from stack.\n", top->data);
    top = top->next;
    free(temp);
}

// Peek operation
void peek() {
    if (top == NULL)
        printf("Stack is empty.\n");
    else
        printf("Top Element = %d\n", top->data);
}

// Display operation
void display() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

/*  OUTPUT

1. Push
2. Pop
3. Peek
4. Display
5. Exit

Enter choice: 1
Enter value: 10
10 pushed into stack.

Enter choice: 1
Enter value: 20
20 pushed into stack.

Enter choice: 1
Enter value: 30
30 pushed into stack.

Enter choice: 4
Stack: 30 20 10

Enter choice: 3
Top Element = 30

Enter choice: 2
30 popped from stack.

Enter choice: 4
Stack: 20 10

Enter choice: 5

*/
