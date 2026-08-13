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
