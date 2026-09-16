#include<stdio.h>
#include<stdlib.h>

struct Node {
int data;
struct Node*right;
struct Node*left;
};

//create Node
struct Node*createnode(int value)
{
  struct Node*newnode=malloc(sizeof(struct Node));
newnode->data=value;
newnode->right=NULL;
newnode->left=NULL;

return newnode;
}

//Insert a value into the tree
struct Node*insert(struct Node*root,int value){
if(root==NULL)
  return createnode(value);
  if(value<root->data)
    root->left=insert(root->left,value);
  else if(value>root->data)
    root->right=insert(root->right,value);
return root;
}

//search
void search(struct Node*root,int value){
  if(root==NULL){
    printf("Value not found\n");
    return;
  }

  if(root->data==value)
    printf("value found\n");
  else if(value<root->data)
    search(root->left,value);
  else
    search(root->right,value);
}

//Find Minimum value
struct Node*minNode(struct Node*root){
  while(root->left!=NULL)
    root=root->left;
  return root;
}

//Deletion
struct Node*delete(struct Node*root,int value){
  if(root==NULL)
    return root;

  if(value<root->data)
  root->left=delete(root->left,value);
  else if(value>root->data)
    root->right=delete(root->right,value);

  else {
    //No left child
    if(root->left==NULL){
      struct Node*temp=root->right;
      free(root);
      return temp;
    }

    //No right child
    if(root->right==NULL){
      struct Node*temp=root->right;
     free(root);
     return temp;
    }

    //Two Children
    struct Node*temp=minNode(root->right);
    root->data=temp->data;
    root->right=delete(root->right,temp->data);
  }
  return root;
}

//display
void display(struct Node*root)
{
  if(root!=NULL){
    display(root->left);
    printf("%d ",root->data);
    display(root->right);
  }
}

int main(){
  struct Node*root=NULL;
  int choice,value;

  while(1){
    printf("\n-------TREE MENU------\n");
    printf("\n1.Insert");
    printf("\n2.Delete");
    printf("\n3.Search");
    printf("\n4.Display");
    printf("\n5.Exit");
    printf("\nEnter Choice:");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        printf("Enter Value to Insert: ");
        scanf("%d",&value);
        root=insert(root,value);
        printf("Value Inserted");
        break;

      case 2:
         printf("Enter Value to delete: ");
         scanf("%d",&value);
         root=delete(root,value);
         printf("Value Deleted");
         break;

      case 3:
         printf("Enter Value to search: ");
         scanf("%d",&value);
         search(root,value);
         break;

      case 4:
         printf("Tree: ");
         display(root);
         break;

      case 5:
         exit(0);

      default:
         printf("Invalid Choice");
    }
  }

  return 0;
}

     

