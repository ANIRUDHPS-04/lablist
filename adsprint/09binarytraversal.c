/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 09
DATE: 25-09-2026

**********Implementation  of  binary  tree  and  traversals**********

AIM: Create a program that allows Implementation  of  binary  tree  and  traversals
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Create an empty binary search tree by initializing root = NULL.
Step 3: Display the menu with the following options:
- Insert a node
- Inorder traversal
- Preorder traversal
- Postorder traversal
- Exit
Step 4: Read the user's choice.
Step 5: If the choice is Insert:
       1. Read the data.
       2. Create a new node.
       3. If the tree is empty, make the new node the root.
       4. If the data is smaller than the current node, insert it into the left subtree.
       5. If the data is larger than the current node, insert it into the right subtree.
Step 6: If the choice is Inorder Traversal:
       1. Traverse the left subtree.
       2. Visit the root node.
       3. Traverse the right subtree.
Step 7: If the choice is Preorder Traversal:
       1. Visit the root node.
       2. Traverse the left subtree.
       3. Traverse the right subtree.
Step 8: If the choice is Postorder Traversal:
       1. Traverse the left subtree.
       2. Traverse the right subtree.
       3. Visit the root node.
Step 9: If the choice is Exit, terminate the program.
Step 10: Repeat Steps 3–9 until the user selects Exit.
Step 11: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, data;

    do
    {
        printf("\n\n1. Insert");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Inorder: ");
                inorder(root);
                break;

            case 3:
                printf("Preorder: ");
                preorder(root);
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                break;

            case 5:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice!");
        }
    } while (choice != 5);

    return 0;
}

/*  OUTPUT

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 1
Enter data: 50

Enter your choice: 1
Enter data: 30

Enter your choice: 1
Enter data: 70

Enter your choice: 1
Enter data: 20

Enter your choice: 1
Enter data: 40

Enter your choice: 2
Inorder: 20 30 40 50 70

Enter your choice: 3
Preorder: 50 30 20 40 70

Enter your choice: 4
Postorder: 20 40 30 70 50

Enter your choice: 5
Exiting...

*/
