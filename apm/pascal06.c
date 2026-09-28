/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 06
DATE: 

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
