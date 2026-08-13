#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
char str[100];
int alpha=0,digit=0,punct=0;
printf("Enter the String:");
fgets(str,100,stdin);
printf("Character Breakdown:<br>");

for(int i=0;i<strlen(str);i++)
{
  char c = tolowerstr[i];

  if(isalpha(str[i]))
  {
    switch(c){
   case 'a':
   case 'e':
   case 'i':
   case 'o':
   case 'u':
     break;
    alpha++;
  } 
  else if(isdigit(str[i]))
  {
    printf("Consonanat");
    digit++;
  } else if(ispunct(str[i])){
    printf("Others");
    punct++;
  }

  printf("<br>");
}
printf("\nSummary: %d Alphabets, %d Consonanat, %d Others<br>",alpha,digit,punct);

return 0;
}
