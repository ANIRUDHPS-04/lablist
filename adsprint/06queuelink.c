/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 06
DATE: 15-07-2026

**********Implementation  of  queue  using  linkedlist**********

AIM: Create a program that allows Implementation  of  queue  using  linkedlist
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Initialize front = NULL and rear = NULL.
Step 3: Display the queue menu and read the user's choice.
Step 4: Perform the operation based on the choice:
  1. Enqueue
     1. Create a new node using malloc().
     2. Read the value from the user.
     3. If the queue is empty, set front = rear = newNode.
     4. Otherwise, insert the new node at the rear.
  2. Dequeue
     1. Check whether the queue is empty.
     2. If empty, display "Queue Underflow".
     3. Otherwise, delete the front node.
     4. Update front and free the deleted node.
     5. If the queue becomes empty, set rear = NULL.
  3. Peek
     1. Check whether the queue is empty.
     2. If not empty, display the front element.
  4. Count
     1. Initialize count = 0.
     2. Traverse the queue and increment count.
     3. Display the total number of elements.
  5. Display
     1. Check whether the queue is empty.
     2. Traverse from front to rear.
     3. Display all elements.
  6. Exit
Terminate the program.
Step 5: Repeat the menu until the user selects Exit.
Step 6: Stop.

/* **********SOURCE CODE********** */

#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;

  struct Node*next;
};

struct Node*front=NULL;
struct Node*rear=NULL;

//Enqueue operation
void enq(){
  int value;

  printf("Enter the value:");
  scanf("%d",&value);

  struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));


  newNode->data=value;
  newNode->next=NULL;

  if(rear==NULL){
    front=rear=newNode;
  }else {
    rear->next=newNode;
    rear=newNode;
  }

  printf("%d inserted into the queue.\n",value);
}
  //delete element

  void deq(){
    if(front==NULL){
      printf("Queue Underflow!\n");
      return;
    }

    struct Node*temp=front;

    printf("%d Deleted from the queue.\n",front->data);

    front=front->next;

    if(front==NULL)
      rear=NULL;

    free(temp);
  }


// Peek element

void peek(){
  if(front==NULL){
    printf("Queue is Empty!\n");
  }else{
    printf("Front Element=%d\n",front->data);
  }
}

//Count Element

void count(){
  int count=0;
  struct Node*temp=front;

  while(temp!=NULL){
    count++;
    temp=temp->next;
  }

  printf("Number of elements=%d\n",count);
}


  //display elements
  void display(){
    struct Node*temp=front;

    if(front==NULL){
      printf("Queue is Empty.\n");
      return;
    }

    printf("Queue: ");

    while(temp!=NULL){
      printf("%d ->",temp->data);
      temp=temp->next;
    }
     
    printf("\n");
  }

  int main(){
    int choice;
int n=1;
      while(n){
        printf("------QUEUE MENU-----\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Count\n");
        printf("5.Display\n");
        printf("6.Exit\n");

        printf("Enter your Choice:");
        scanf("%d",&choice);

        switch(choice){
case 1:
          enq();
          break;
case 2:
          deq();
          break;
case 3:
          peek();
          break;
case 4:
          count();
          break;
case 5:
          display();
          break;
case 6:
          printf("Program ended\n");
          n=0;
          break;
default:
          printf("Invalid Program\n");
        }
      }
    return 0;
  }

/* OUTPUT

------QUEUE MENU-----
1.Enqueue
2.Dequeue
3.Peek
4.Count
5.Display
6.Exit

Enter your Choice: 1
Enter the value: 10
10 inserted into the queue.

------QUEUE MENU-----
1.Enqueue
2.Dequeue
3.Peek
4.Count
5.Display
6.Exit

Enter your Choice: 1
Enter the value: 20
20 inserted into the queue.

------QUEUE MENU-----
1.Enqueue
2.Dequeue
3.Peek
4.Count
5.Display
6.Exit

Enter your Choice: 1
Enter the value: 30
30 inserted into the queue.

------QUEUE MENU-----
Enter your Choice: 5
Queue: 10 ->20 ->30 ->

------QUEUE MENU-----
Enter your Choice: 3
Front Element=10

------QUEUE MENU-----
Enter your Choice: 4
Number of elements=3

------QUEUE MENU-----
Enter your Choice: 2
10 Deleted from the queue.

------QUEUE MENU-----
Enter your Choice: 5
Queue: 20 ->30 ->

------QUEUE MENU-----
Enter your Choice: 6
Program ended

*/
