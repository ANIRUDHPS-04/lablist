/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 06
DATE: 20-09-2026 

**********Dynamic Data Display(Patterns)**********

AIM: •	Develop an application that displays Pascal's Triangle dynamically based on user input for the number of rows.
     •	Also, create a pattern generator (e.g., number or star pattern) that can be customized with user input.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare integer variables i, j, and n.
Step 3: Read the value of n from the user.
Step 4: Print n stars in the first row.
Step 5: Print a newline.
Step 6: Print the middle rows with spaces followed by a star, decreasing the number of spaces in each row.
Step 7: Print n stars in the last row.
Step 8: Stop.

*/

/* **********SOURCE CODE********** */
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

/* **********OUTPUT**********

Enter the Number:5
* * * * *
      *
    *
  *
* * * * *

*/

// **********Pascal's Triangle**********

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare integer variables n, i, j and a long long variable num.
Step 3: Read the number of rows n from the user.
Step 4: Repeat the following steps for each row from 0 to n-1.
Step 5: Set num = 1 at the beginning of each row.
Step 6: Print spaces before the numbers to arrange the triangle shape.
Step 7: Print the values of the current row.
Step 8: Calculate the next value using the formula:
        num = num * (i-j) / (j+1)
Step 9: Repeat until all values in the current row are printed.
Step 10: Move to the next row.
Step 11: Continue until n rows are printed.
Step 12: Stop.
 */

/* **********SOURCE CODE********** */
  #include<stdio.h>
  #include<stdio.h>
 
  int main(){
  int n,i,j;
  long long num;
 
  printf("Enter the Number of Rows:");
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    num=1;
 
    for(j=0;j<n-i-1;j++)
      printf(" ");
 
    for(j=0;j<=i;j++){
    printf(" %lld",num);
    num=num*(i-j)/(j+1);
 }
 
 printf("\n");
 }
 return 0;
 }


/* **********OUTPUT**********
  
  Enter the Number of Rows:5
       1
      1 1
     1 2 1
    1 3 3 1
   1 4 6 4 1
  
  */

