/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 03
DATE: 

**********Efficient Prime Number Generation**********

AIM: Implement the Sieve of Eratosthenes algorithm to generate a list of prime numbers up to a specified upper 
     limit (e.g., 10,000). This list will be used for efficient lookups in a mathematical application.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Read the upper limit n.
Step 3: Create an array prime[n+1].
Step 4: Initialize all elements of the prime array to 1, assuming all numbers are prime.
Step 5: Set prime[0] and prime[1] to 0 because 0 and 1 are not prime numbers.
Step 6: Start checking from i = 2 up to √n.
Step 7: If prime[i] is 1, consider i as a prime number.
Step 8: Mark all multiples of i, starting from i × i, as 0.
Step 9: Repeat the process for all values of i up to √n.
Step 10: Traverse the prime array from 2 to n.
Step 11: If prime[i] is 1, display i as a prime number.
Step 12: Stop.

*/

/* **********SOURCE CODE********** */
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

/* **********OUTPUT**********

Enter the Upper limit:10

Prime number upto 10 are:
2 3 5 7 

*/     
