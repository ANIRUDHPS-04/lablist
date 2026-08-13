#include<stdio.h>
int main()
{  
  int i,j,n;

  printf("Enter the Number:");
  scanf("%d",&n);

 for(i=1;i<=n;i++)
  
      printf("* ");
 printf("\n");

   for(i=1;i<=n-2;i++)
   {
    for(j=1;j<=n-i-1;j++){
         printf("  ");}
    printf("*\n");
  }
  
  for(i=1;i<=n;i++)
      printf("* ");
  printf("\n");
  
  return 0;
  }

