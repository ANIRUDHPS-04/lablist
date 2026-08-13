#include<stdio.h>
#include<stdlib.h>

struct Node{
   int data;
   struct Node*next;
};

struct Node*head=NULL;

//Insert at begining
void insertBegining()
{
  struct Node*new_node;

  printf("Enter data:");
  scanf("%d",&new_node->data);

  new_node=(struct Node*)malloc(sizeof(struct Node));

  new_node->next=head;
  head=new_node;

  printf("Node Inserted at the Begining.\n");
}

void display()
{
  struct Node*temp=head;

  if(head==NULL)
  {
    printf("LinkedList is empty");
    return;
  }

  printf("LinkedList:");

  while (temp!=NULL)
  {
     printf("%d->", temp->data);
     temp=new_node;
       
  }

  printf("NULL\n")
}

int main()
{
  int choice;
   
  do
  {

    printf("------menu-----");
    printf("1.Insert Begining\n");
    printf("2.display\n");
    printf("3.exit\n");


    printf("Enter your Choice:");
    scanf("%d",&pos);

    switch(choice)
    {
      case 1:
        inserbegining();
        display();
        break;

      case 2:
        display();
        break;

       case 3:
        printf("Exiting..\n");
        break;

    default:
        printf("Invalid Choice");

        while(!=3)
        {
          
        }
