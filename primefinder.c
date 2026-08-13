#include<stdio.h>

int isPrime(int n)
{
int i;

if(n<=1)
  return 0;

for(i=2;i<=n/2;i++)
{
  if(n%i==0)
    return 0;
}
return 1;
}

int main() {
  int n,i,j=0;

  printf("Enter the Number of Elements:");
  scanf("%d",&n);

  int arr[n], prime[n];

  printf("Enter %d Numbers:\n",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);

    if(isPrime(arr[i])) 
    { 
      prime[j]=arr[i];
      j++;
    }

  }

  printf("\nPrime Numbers are:");
  for(i=0;i<j;i++){
    printf("%d ",prime[i]);}
  return 0;
}


  

