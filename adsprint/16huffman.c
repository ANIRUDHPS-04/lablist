/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 16
DATE: 13-07-2026

**********Implementation  of  Huffman  algorithm**********

AIM: Create a program that allows Implementation  of  Huffman  algorithm
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Read the number of characters and their corresponding frequencies.
Step 3: Create a leaf node for each character with its frequency.
Step 4: Select the two nodes having the smallest frequencies.
Step 5: Create a new internal node by adding the frequencies of the two selected nodes.
Step 6: Make the first selected node the left child and the second selected node the right child.
Step 7: Insert the new node into the list and remove the two selected nodes.
Step 8: Repeat Steps 4 to 7 until only one node remains.
Step 9: Assign 0 to every left branch and 1 to every right branch.
Step 10: Traverse the Huffman tree from root to leaf to obtain the binary code for each character.
Step 11: Display the Huffman codes.
Step 12: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char ch, int freq) {
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void printCodes(struct Node* root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c : ", root->ch);

        for (int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\n");
    }
}

int main() {
    int n, i, j, code[100];

    char ch[100];
    int freq[100];

    struct Node* nodes[100];

    printf("Enter number of characters: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter character and frequency: ");
        scanf(" %c %d", &ch[i], &freq[i]);

        nodes[i] = createNode(ch[i], freq[i]);
    }

    int size = n;

    while (size > 1) {
        int min1 = 0, min2 = 1;

        if (nodes[min1]->freq > nodes[min2]->freq) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }

        for (i = 2; i < size; i++) {
            if (nodes[i]->freq < nodes[min1]->freq) {
                min2 = min1;
                min1 = i;
            }
            else if (nodes[i]->freq < nodes[min2]->freq) {
                min2 = i;
            }
        }

        struct Node* newNode = createNode(
            '$',
            nodes[min1]->freq + nodes[min2]->freq
        );

        newNode->left = nodes[min1];
        newNode->right = nodes[min2];

        nodes[min1] = newNode;

        for (i = min2; i < size - 1; i++)
            nodes[i] = nodes[i + 1];

        size--;
    }

    printf("\nHuffman Codes:\n");
    printCodes(nodes[0], code, 0);

    return 0;
}

/*  OUTPUT

Enter number of characters: 5

Enter character and frequency: A 5
Enter character and frequency: B 9
Enter character and frequency: C 12
Enter character and frequency: D 13
Enter character and frequency: E 16

Huffman Codes:

C : 00
D : 01
E : 10
A : 110
B : 111
*/
