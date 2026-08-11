#include<stdio.h>
#include<stdlib>

struct Node {
  int data;
  struct Node*next;
};

struct Node*head=NULL;
void append(struct Node**head_ref){
  int newd;

  printf("Enter the Data:");
  scanf("%d",&newd);

  struct Node*newd=(struct Node*)malloc(sizeof(struct Node));
  newd->data=newd;
  newd->next=NULL;
  if(*head_ref==NULL);
  *head_ref=newd;
  return;
}


void insertb(struct Node*head){
  
  printf("LinkedList\n");
  if(temp==NULL)

