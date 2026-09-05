#include<stdio.h>

int main(){
  int matrix[10][10], sparse[100][3];
  int r,c,i,j,a=1,b=0;

  printf("Enter Rows and Columns:");
  scanf("%d%d",&r,&c);

  printf("Enter the matrix elements:\n");
  for(i=0;i<r;i++)
    for(j=0;j<c;j++)
      scanf("%d",&matrix[i][j]);

  // to count the non zero elements

  for(i=0;i<r;i++)
    for(j=0;j<c;j++)
      if(matrix[i][j]!=0)
        b++;


  //stores  rows amd columns

  sparse[0][0]=r;
  sparse[0][1]=c;
  sparse[0][2]=b;

  //stores non zero elements

  for(i=0;i<r;i++) {
    for(j=0;j<c;j++) {
      if(matrix[i][j]!=0) {
        sparse[a][0]=i;
        sparse[a][1]=j;
        sparse[a][2]=matrix[i][j];
        a++;
      }
    }
  }

  printf("\n------Sparse Matrix---------\n");
  printf("Rows\tColumns\tValues\n");
  for(i=0;i<b;i++)
  printf("%d\t%d\t%d\n",sparse[i][0],sparse[i][1],sparse[i][2]);

  return 0;
}
