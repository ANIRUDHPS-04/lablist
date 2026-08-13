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
