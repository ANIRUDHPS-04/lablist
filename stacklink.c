#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node*next;
};

struct Node*top=NULL;

//push
void push(int value){
  struct Node*newNode=malloc(sizeof(struct Node));

  newNode->data=value;
  newNode->next=top;
  top=newNode;

  printf("%d Pushed into the stack.\n",value);
}


//pop
void pop(){
  struct Node*temp;

  if(top==NULL){
    printf("Stack Underflow!\n");
    return;
  }

  temp=top;
  printf("%d Popped from the stack.\n",top->next);
  top=top->next;
  free(temp);
}

//peek
void peek(){
  if(top==NULL)
    printf("Stack is empty.\n");
    else
      printf("Top Element=%d\n",top->data);
  }

  //Display
void display(){
  struct Node*temp=top;

  if(top==NULL){
    printf("Stak is empty.\n");
    return;
  }

printf("Stack: ");
while(temp!=NULL){
printf("%d ",temp->data);
temp=temp->next;
}
printf("\n");
}



