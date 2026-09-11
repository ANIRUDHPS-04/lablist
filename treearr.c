#include<stdio.h>

int main(){
  int tree[100];
  int n,i;

  printf("Enter the number of Nodes:");
  scanf("%d",&n);

  printf("Enter the Elements:\n");

  for(i=0;i<n;i++)
  {
    printf("Node %d: ",i+1);
    scanf("%d",&tree[i]);
  }

  printf("\nBinary Tree Elements:\n");

  for(i=0;i<n;i++)
  {
    printf("%d ",tree[i]);
  }

  printf("\n");
  return 0;
}

