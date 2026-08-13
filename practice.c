#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;

  struct Node*next;
};

struct Node*head=NULL;

void insertBegining(int value){

 struct Node*new_Node=(struct Node*)malloc(sizeof(struct Node));

 new_Node->data=value;
 new_Node->next=head;
}

void insertEnd(int value){

  struct Node*new_Node=(struct Node*)malloc(sizeof(struct Node));

  new_Node->data=value;
  new_Node->next=NULL;
 
}

if(head==NULL)
{
  head=new_Node;
  return;
}


struct Node*temp=head;
while(temp->next!=NULL){
  temp=temp->next;
}
temp->next=new_Node;
}


// Display the Node

void display(){
  struct Node*temp=head;

  if(head==NULL){
    printf("List is Empty.\n");
    return;
  }


  printf("LinkList:");
  while(temp!=NULL){
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("NULL
