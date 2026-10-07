#include<stdio.h>
#define MAX 5

int queue[MAX];
int front =-1, rear=-1;

void enqueue()
{
  int value;

  if((rear+1)%MAX==front)
  {
    printf("Queue is Full\n");
    return;
  }

  printf("Enter Value: ");
  scanf("%d",&value);

  if(front==-1)
  {
    front=0;
    rear=0;
  }
  else
  {
    rear=(rear+1)%MAX;
  }

  queue[rear]=value;
  printf("%d Inserted\n",value);
}

void dequeue()
{
  if(front==-1)
  {
    printf("Queue is Empty\n

  }

  printf("%d deleted\n",queue[front]);

  if(front==rear)
  {
    front=-1;
    rear=-;
  }
  else
  {
    front=(front+1)%MAX;
  }
}

void display()
{
  int i;

  if(front==-1)
  {
    printf("Queue is Empty\n");
    return;
  }

  printf("Queue: ");

  i=front;

  while(1)
  {
    printf("%d ", queue[i]);

    if(i==rear)
      break;

    i=(i+1)%MAX
