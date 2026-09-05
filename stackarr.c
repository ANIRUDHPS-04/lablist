#include<stdio.h>
#define MAX 5

int stack[MAX];
int top=-1;

void push(int value){

  if(top==MAX-1){
printf("Stack Overflow\n");
  }
  else
  {
   top++;
  stack[top]=value;
  printf("%d Pushed into the stack\n",value);
}
}

int main(){
int n,value;
printf("Enter the Number of elements to push:");
scanf("%d",&n);

for(int i=0;i<n;i++)
{
  printf("Enter Value:");
  scanf("%d",&value);
  push(value);
}

return 0;
}
