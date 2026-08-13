#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node*next;

};

void append(struct Node**head_ref){
  int new_data;

  printf("Enter the data:");
  scanf("%d",&new_data);

  struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
  new_node->data=new_data;
  new_node->next=NULL;
    if(*head_ref==NULL){
      *head_ref=new_node;
      return;
    }
  struct Node*last=*head_ref;
  while(last->next!=NULL){
    last=last->next;}
  last->next=new_node;
}

void print(struct Node*head){
  struct Node*temp=head;
  printf("LinkedList\n");
  if(temp==NULL)
    printf("Empty Linkedlist\n");
  while(temp!=NULL){
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("NULL\n");
}

int main(){
  int c;
  do{
    printf("Menu LinkList\n");
    printf("1.Create:\n");
    printf("2.Insert:\n");
    printf("3.Display:\n");
    printf("4.Exit:\n");
    printf("Enter your Choice:\n");
    scanf("%d",&c);
    switch(c){
      case 1:
        struct Node*head=NULL;
        printf("Node Created\n");
        break;
      case 2:
        append(&head);
        break;
      case 3:
        print(head);
        break;
      case 4:
        printf("Thank you\n");
        break;
      default:
        printf("Invalid Choice\n");
        break;
    }
  }
  while(c!=4);
  return 0;
}

