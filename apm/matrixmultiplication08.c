/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 08
DATE: 

**********Matrix Multiplication for Image Processing**********

AIM: Implement matrix multiplication to apply a transformation matrix to an image. The program should accept
     a 2D image matrix and a transformation matrix, then output the transformed image.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare matrices a, b, and c and variables r1, c1, r2, c2, i, j, and k.
Step 3: Read the number of rows and columns of the first matrix.
Step 4: Read the elements of the first matrix.
Step 5: Read the number of rows and columns of the second matrix.
Step 6: Read the elements of the second matrix.
Step 7: Check whether the number of columns of the first matrix is equal to the number of rows of the second matrix.
Step 8: If c1 != r2, display "Matrix multiplication is not possible" and stop.
Step 9: Initialize each element of the result matrix c[i][j] to 0.
Step 10: Multiply each element of a row of the first matrix with the corresponding element of a column of the second matrix and add the products.
Step 11: Store the calculated value in the result matrix c.
Step 12: Display the resulting matrix.
Step 13: Stop.

*/

/* **********SOURCE CODE********** */
#include<stdio.h>
int main(){
  int i,j,a[10][10],b[10][10],r1,r2,c1,c2;
  int k,c[10][10];
  printf("Enter the noof rows and cols of 1st matrix\n");
  scanf("%d %d",&r1,&c1);
  printf("Enter the data\n");
  for(i=0;i<r1;i++){
    for(j=0;j<c1;j++)
      scanf("%d",&a[i][j]);
  }
  printf("Enter the noof rows and cols of 2nd matrix\n");
  scanf("%d %d",&r2,&c2);
  printf("Enter the data\n");
  for(i=0;i<r2;i++){
    for(j=0;j<c2;j++)
      scanf("%d",&b[i][j]);
  }
  if(c1!=r2){
    printf("Not possible because c1=r2\n");
    return 0;
  }
  printf("Matrix multiplication\n");
  for(i=0;i<r1;i++){
    for(j=0;j<c2;j++){
      c[i][j]=0;
      for(k=0;k<c1;k++){
        c[i][j]+=a[i][k]*b[k][j];
      }}  }
  for(i=0;i<r1;i++){
    for(j=0;j<c2;j++)
      printf("%d\t",c[i][j]);
    printf("\n");
}
  return 0;
}

/* **********OUTPUT**********

Enter the noof rows and cols of 1st matrix
2 2
Enter the data
1 2
3 4

Enter the noof rows and cols of 2nd matrix
2 2
Enter the data
5 6
7 8

Matrix multiplication
19      22
43      50

*/
