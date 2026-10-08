/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 07
DATE: 07-09-2026 

**********Matrix Operations for Financial Modeling**********

AIM: Write a program to perform matrix operations that calculate the row sum, column sum, and diagonal sum 
     of a financial transaction matrix. Additionally, include a function to transpose the matrix for further 
     analysis.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a matrix a[10][10] and variables for rows, columns, row sum, column sum, and trace.
Step 3: Read the number of rows and columns of the matrix.
Step 4: Read all the elements of the matrix.
Step 5: Calculate the sum of each row and display it.
Step 6: Calculate the sum of each column and display it.
Step 7: Calculate the trace by adding the elements where the row index and column index are equal (i == j).
Step 8: Display the trace of the matrix.
Step 9: Call the transpose() function.
Step 10: In the transpose() function, interchange the rows and columns by displaying a[j][i].
Step 11: Display the transpose of the matrix.
Step 12: Stop.

*/

/* **********SOURCE CODE********** */
#include<stdio.h>
int i,j,a[10][10];
  int transpose(int r,int c){
    printf("transpose:\n");
     for(i=0;i<c;i++){
       for(j=0;j<r;j++){
                printf("%d\t",a[j][i]);
        }
    printf("\n");
     }}
int main(){
  int rsum,csum,t=0,r,c;
  printf("enter no.of rows and columns\n");
  scanf("%d %d",&r,&c);
  printf("enter data\n");
  for(i=0;i<r;i++){
    for(j=0;j<c;j++)
      scanf("%d",&a[i][j]);}
for(i=0;i<r;i++){
        rsum=0;
       for(j=0;j<c;j++){
                rsum+=a[i][j];}
       printf("sum of row %d is %d\n",i+1,rsum);}
for(j=0;j<c;j++){
  csum=0;
  for(i=0;i<r;i++){
      csum+=a[i][j];}
  printf("sum of col %d is %d\n",j+1,csum);
}
for(i=0;i<r;i++){
         for(j=0;j<c;j++){
           if(i==j)
                t+=a[i][j];
         }}
printf("trace= %d\n",t);
transpose(r,c);
return 0;}matrix operation

/* **********OUTPUT**********

enter no.of rows and columns
3 3
enter data
1 2 3
4 5 6
7 8 9

sum of row 1 is 6
sum of row 2 is 15
sum of row 3 is 24

sum of col 1 is 12
sum of col 2 is 15
sum of col 3 is 18

trace= 15

transpose:
1       4       7
2       5       8
3       6       9

*/

