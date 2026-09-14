#include<stdio.h>

int main()
{
  int a[10][10],n,i,j,symmetric=1;
  printf("Enter the size of matrix:");
  scanf("%d",&n);

  printf("Enter the matrix:\n");
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      scanf("%d",&a[i][j]);
    }
  }

  printf("\nMatrix:\n");
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
   printf("%d ",a[i][j]);
    }
    printf("\n");
  }

  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      if(a[i][j] !=a[j][i]) {
        symmetric= 0;
        break;
      }
    }
  }

  if(symmetric)
    printf("\nThe Matrix is symmetric.\n");
  else
    printf("\nThe Matrix is not symmetric,\n");

  return 0;
}

//Output
/*
Enter the size of matrix:3
Enter the matrix:
1 2 3
2 4 5
3 5 6

Matrix:
1 2 3 
2 4 5 
3 5 6 

The Matrix is symmetric.
*/
