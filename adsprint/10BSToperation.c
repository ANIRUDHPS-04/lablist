/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 10
DATE: 25-09-2026

**********Implementation  of  binary  search  trees  and  perform  the    operations  on  BST**********

AIM: Create a program that allows Implementation  of  binary  search  trees  and  perform  the  operations  on  BST
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Initialize the root of the Binary Search Tree as NULL.
Step 3: Display the menu containing the following operations:
- Insert
- Delete
- Search
- Inorder Traversal
- Preorder Traversal
- Postorder Traversal
- Display Tree
- Exit
Step 4: Read the user's choice.
Step 5: Perform the selected operation:
      - Insertion: If the tree is empty, create a new node as the root. Otherwise, compare the value with the current node and insert it into the left subtree if smaller or the right subtree if greater.
      - Deletion: Search for the node to be deleted. If it has no children, remove it directly. If it has one child, replace it with its child. If it has two children, replace its value with the minimum value in its right subtree and delete that node.
      - Searching: Compare the required value with the current node. If equal, the value is found. If smaller, search the left subtree; otherwise, search the right subtree.
      - Inorder Traversal: Visit the left subtree, root node, and right subtree.
      - Preorder Traversal: Visit the root node, left subtree, and right subtree.
      - Postorder Traversal: Visit the left subtree, right subtree, and root node.
      - Display Tree: Display the nodes of the BST in tree format.
Step 6: Repeat Steps 4 and 5 until the user selects Exit.
Step 7: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate values are not allowed.\n");

    return root;
}

struct Node* search(struct Node *root, int value)
{
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

struct Node* findMin(struct Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

struct Node* deleteNode(struct Node *root, int value)
{
    struct Node *temp;

    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

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

void display(struct Node *root, int space)
{
    int i;

    if (root == NULL)
        return;

    space += 5;

    display(root->right, space);

    printf("\n");
    for (i = 5; i < space; i++)
        printf(" ");

    printf("%d\n", root->data);

    display(root->left, space);
}

int main()
{
    struct Node *root = NULL;
    struct Node *result;
    int choice, value;

    while (1)
    {
        printf("\n\n--- BST OPERATIONS ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Display Tree\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                if (search(root, value) == NULL)
                    printf("Value not found.\n");
                else
                {
                    root = deleteNode(root, value);
                    printf("Value deleted successfully.\n");
                }
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);

                result = search(root, value);

                if (result != NULL)
                    printf("Value found in BST.\n");
                else
                    printf("Value not found in BST.\n");
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                    display(root, 0);
                break;

            case 8:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

/*

--- BST OPERATIONS ---
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Display Tree
8. Exit
Enter your choice: 1
Enter value to insert: 50

Enter your choice: 1
Enter value to insert: 30

Enter your choice: 1
Enter value to insert: 70

Enter your choice: 1
Enter value to insert: 20

Enter your choice: 1
Enter value to insert: 40

Enter your choice: 4
Inorder: 20 30 40 50 70

Enter your choice: 5
Preorder: 50 30 20 40 70

Enter your choice: 6
Postorder: 20 40 30 70 50

Enter your choice: 3
Enter value to search: 40
Value found in BST.

Enter your choice: 2
Enter value to delete: 30
Value deleted successfully.

Enter your choice: 4
Inorder: 20 40 50 70

*/
