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

