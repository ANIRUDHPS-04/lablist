#include<stdio.h>

int main()
{
  int n,i,j;
  printf("Enter the Upper limit:");
  scanf("%d",&n);
  
  int prime[n+1];

  for(i=0;i<=n;i++)
    prime[i]=1;

  prime[0]=prime[1]=0;

  for(i=2;i*i<=n;i++){
    if(prime[i]){
      for(j=i*i;j<=n;j+=i)

        prime[j]=0;
    }
}

printf("\nPrime number upto %d are:\n",n);

for(i=2;i<=n;i++)
{
  if(prime[i]){
    printf("%d ",i);
  }
}

return 0;}
