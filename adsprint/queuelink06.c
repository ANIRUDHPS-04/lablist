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
