/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 01
DATE: 25-09-2026

**********Implementation  of  stacks  using  arrays**********

AIM: Create a program that allows Implementation  of  stacks  using  arrays
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare an array stack[MAX] and initialize top = -1.
Step 3: Display the stack menu and read the user's choice.
Step 4: Perform the selected operation:
  1. Push Operation
     1. Check whether top == MAX - 1.
     2. If true, display "Stack Overflow".
     3. Otherwise, read a value from the user.
     4. Increment top by one.
     5. Insert the value into stack[top].
  2. Pop Operation
     1. Check whether top == -1.
     2. If true, display "Stack Underflow".
     3. Otherwise, display the top element.
     4. Decrement top by one.
  3. Peek Operation
     1. Check whether the stack is empty.
     2. If empty, display "Stack is empty".
     3. Otherwise, display the top element.
  4. Display Operation
     1. Check whether the stack is empty.
     2. If empty, display "Stack is empty". 
     3. Otherwise, traverse from top to 0.
     4. Display all stack elements.
  5. Exit
Terminate the program.
Step 5: Repeat the menu until the user selects Exit.
Step 6: Stop.
*/

/* **********SOURCE CODE********** */

#include<stdio.h>
#define MAX 5

int stack[MAX];
int top=-1;

void push(){
  int value;

  if(top==MAX-1)
    printf("Stack Overflow\n");
  else
  {
    printf("Enter the value: ");
    scanf("%d", &value);
    top++;
    stack[top]=value;
    printf("%d pushed into stack\n",value);
  }
}

void pop(){
  if(top==-1)
    printf("Stack Underflow\n");
  else
  {
    printf("%d Popped from stack\n",stack[top]);
    top--;
  }
}

void peek(){
  if(top==-1)
    printf("stack is empty\n");
  else
    printf("Top element=%d\n",stack[top]);
}

void display()
{
  int i;

  if(top==-1)
    printf("Syack is empty\n");
  else
  {
    printf("Stack elements:\n");
    for(i=top;i>=0;i--)
      printf("%d\n",stack[i]);
  }
}

int main(){
  int choice;

  while(1)
  {
    printf("\n------STACK MENU------\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Peek\n");
    printf("4.Disply\n");
    printf("5.Exit\n");

    printf("Enter your Choice:");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
        push();
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

      default:printf("Invalid Choice\n");
    }
  }
}

/*  OUTPUT

------STACK MENU------
1.Push
2.Pop
3.Peek
4.Display
5.Exit

Enter your Choice: 1
Enter the value: 10
10 pushed into stack

Enter your Choice: 1
Enter the value: 20
20 pushed into stack

Enter your Choice: 1
Enter the value: 30
30 pushed into stack

Enter your Choice: 4
Stack elements:
30
20
10

Enter your Choice: 3
Top element=30

Enter your Choice: 2
30 Popped from stack

Enter your Choice: 4
Stack elements:
20
10

Enter your Choice: 5
*/
