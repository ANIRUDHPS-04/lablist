/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 9
DATE: 

**********Symmetry Checker for Geometric Designs**********

AIM: Develop a program to check if a given design (represented as a matrix) is symmetric. This program can be 
     useful for analyzing symmetry in architectural or geometric design patterns.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a matrix a[10][10] and variables n, i, j, and symmetric.
Step 3: Read the size n of the square matrix.
Step 4: Read all the elements of the matrix.
Step 5: Display the entered matrix.
Step 6: Compare each element a[i][j] with its corresponding transpose element a[j][i].
Step 7: If any pair of elements is different, set symmetric = 0.
Step 8: If symmetric = 1, display "The Matrix is symmetric."
Step 9: Otherwise, display "The Matrix is not symmetric."
Step 10: Stop.

*/

/* **********SOURCE CODE********** */
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

/* **********OUTPUT**********

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
