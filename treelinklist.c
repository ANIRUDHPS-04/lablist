#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int data)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Create tree using level order
struct Node* createTree(int n)
{
    struct Node **queue;
    struct Node *root;
    int data, i, front = 0, rear = 0;

    queue = (struct Node**)malloc(n * sizeof(struct Node*));

    printf("Enter root: ");
    scanf("%d", &data);

    root = createNode(data);
    queue[rear++] = root;

    for (i = 1; i < n; )
    {
        struct Node *current = queue[front++];

        printf("Enter left child of %d (enter -1 for no node): ",
               current->data);
        scanf("%d", &data);

        if (data != -1)
        {
            current->left = createNode(data);
            queue[rear++] = current->left;
            i++;
        }

        if (i >= n)
            break;

        printf("Enter right child of %d (enter -1 for no node): ",
               current->data);
        scanf("%d", &data);

        if (data != -1)
        {
            current->right = createNode(data);
            queue[rear++] = current->right;
            i++;
        }
    }

    free(queue);

    return root;
}

// Display tree
void display(struct Node *root, int space)
{
    if (root == NULL)
        return;

    space += 6;

    display(root->right, space);

    printf("\n");

    for (int i = 6; i < space; i++)
        printf(" ");

    printf("%d", root->data);

    display(root->left, space);
}

int main()
{
    struct Node *root;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    root = createTree(n);

    printf("\nBinary Tree:\n");

    display(root, 0);

    printf("\n");

    return 0;
}