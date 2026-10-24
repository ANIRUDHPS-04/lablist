/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 19
DATE: 25-09-2026

**********Implementation of   AVL  tree (balanced  tree)**********

AIM: Create a program that allows Implementation of   AVL  tree (balanced  tree)
*/

/* **********ALGORITHM**********

Step 1: Start.

Step 2: Create a node containing data, height, left pointer, and right pointer.

Step 3: Display the menu with the following operations:
1. Insert
2. Delete
3. Inorder traversal
4. Preorder traversal
5. Postorder traversal
6. Exit
Step 4: Insertion
      - Insert the new node according to the Binary Search Tree (BST) property.
      - Update the height of each affected node.
      - Calculate the balance factor.
      - If the tree becomes unbalanced, perform the appropriate rotation (LL, RR, LR, or RL).
Step 5: Deletion
      - Search for the node to be deleted.
      - Delete the node according to BST deletion rules.
      - Update the height of affected nodes.
      - Calculate the balance factor and perform the required rotations to balance the tree.
Step 6: Inorder Traversal
      - Traverse the left subtree.
      - Display the root node.
      - Traverse the right subtree.
Step 7: Preorder Traversal
      - Display the root node.
      - Traverse the left subtree.
      - Traverse the right subtree.
Step 8: Postorder Traversal
      - Traverse the left subtree.
      - Traverse the right subtree.
      - Display the root node.
Step 9: Repeat Steps 3–8 until the user selects Exit.

Step 10: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int height;
    struct Node *left, *right;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

struct Node* createNode(int data)
{
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

int balanceFactor(struct Node *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

struct Node* rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct Node* leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct Node* insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
    {
        printf("Duplicate values are not allowed!\n");
        return root;
    }

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int b = balanceFactor(root);

    // LL Case
    if (b > 1 && data < root->left->data)
        return rightRotate(root);

    // RR Case
    if (b < -1 && data > root->right->data)
        return leftRotate(root);

    // LR Case
    if (b > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (b < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct Node* minNode(struct Node *root)
{
    struct Node *current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            struct Node *temp = root->left ?
                                root->left : root->right;

            if (temp == NULL)
            {
                free(root);
                return NULL;
            }
            else
            {
                *root = *temp;
                free(temp);
            }
        }
        else
        {
            struct Node *temp = minNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int b = balanceFactor(root);

    if (b > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    if (b > 1 && balanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    if (b < -1 && balanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
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

int main()
{
    struct Node *root = NULL;
    int choice, data;

    while (1)
    {
        printf("\n\n--- AVL TREE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/*  OUTPUT 

--- AVL TREE MENU ---
1. Insert
2. Delete
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1
Enter value to insert: 30

Enter your choice: 1
Enter value to insert: 20

Enter your choice: 1
Enter value to insert: 10

Enter your choice: 3
Inorder: 10 20 30

Enter your choice: 4
Preorder: 20 10 30

*/    
