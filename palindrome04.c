/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 04
DATE: 

**********Palindrome Checker for Database Records**********

AIM: Write a program to check if a given set of product codes (stored as strings in a database) are palindromes, 
     and generate a report of the results.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Define a function palindrome() to check whether a product code is a palindrome.
Step 3: Declare a 2D character array code[20][30] to store the product codes.
Step 4: Read the number of product codes n.
Step 5: Read all the product codes from the user.
Step 6: For each product code, call the palindrome() function.
Step 7: Find the length of the product code using strlen().
Step 8: Compare the characters from the beginning and end of the string.
Step 9: If any pair of characters is different, return 0, indicating that the code is not a palindrome.
Step 10: If all corresponding characters are equal, return 1, indicating that the code is a palindrome.
Step 11: Display each product code and whether it is a Palindrome or Not Palindrome.
Step 12: Stop.

*/

/* **********SOURCE CODE********** */
#include<stdio.h>
#include<string.h>

int palindrome(char str[]){

  int i,len;
  len = strlen(str);

  for(i=0;i<len/2;i++)
  {
    if(str[i]!=str[len-i-1])
      return 0;
  }

  return 1;

}

int main()
{

  int i,n;
  char code[20][30];

  printf("Enter the Number of Product Codes:");
  scanf("%d",&n);

  printf("Enter the product Codes:\n");
  for(i=0;i<n;i++)
  {
    scanf("%s",code[i]);
  }

  printf("\nProduct Report\n");
  printf("---------------\n");

  for(i=0;i<n;i++)
  {
    if(palindrome(code[i]))
      printf("%s:Palindrome\n",code[i]);
    else
      printf("%s:Not Palindrome\n",code[i]);
  }

  return 0;
}

/* **********OUTPUT**********

Enter the Number of Product Codes:2
Enter the product Codes:
madam
ani

Product Report
---------------
madam:Palindrome
ani:Not Palindrome

*/
