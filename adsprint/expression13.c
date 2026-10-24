/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 13
DATE: 25-09-2026

**********Implementation  of  graphs  and  graph  traversals**********

AIM: Create a program that allows Implementation  of  graphs  and  graph  traversals.
*/

/* **********ALGORITHM**********

Step 1: Start.

Step 2: Initialize an empty stack and set `top = -1`.

Step 3: Read the infix expression from the user.

Step 4: Scan the infix expression from left to right.

Step 5: For each character in the expression:

      - If the character is an operand (letter or digit), add it to the postfix expression.
      - If the character is '(', push it onto the stack.
      - If the character is ')', pop operators from the stack and add them to the postfix expression until
        '(' is found. Remove '(' from the stack.
      - If the character is an operator (`+`, `-`, `*`, `/`, `^`):
          - Pop operators with higher precedence from the stack and add them to the postfix expression.
          - If the precedence is equal, pop the operator unless the current operator is `^`.
          - Push the current operator onto the stack.

Step 6: Repeat Step 5 until the entire infix expression is scanned.

Step 7: Pop all remaining operators from the stack and add them to the postfix expression.

Step 8: Add the null character (`'\0'`) at the end of the postfix expression.

Step 9: Display the postfix expression.

Step 10: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int priority(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isalnum((unsigned char)ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && stack[top] != '(' &&
                   (priority(stack[top]) > priority(ch) ||
                   (priority(stack[top]) == priority(ch) &&
                    ch != '^')))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

/*  OUTPUT

Enter infix expression: (A+B)*C
Postfix expression: AB+C*

*/
