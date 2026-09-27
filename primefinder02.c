/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 02
DATE: 

**********Prime Number Finder for Data Processing**********

AIM: Write a program that scans a list of numbers and identifies which ones are prime. It should store the prime 
     numbers separately for further processing.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Define a function isPrime() to check whether a number is prime.
Step 3: In isPrime(), if the number is less than or equal to 1, return 0.
Step 4: Check whether the number is divisible by any integer from 2 to n/2.
Step 5: If the number is divisible by any of them, return 0 because it is not prime.
Step 6: If it is not divisible by any number, return 1 because it is prime.
Step 7: In main(), read the number of elements n.
Step 8: Declare arrays arr and prime.
Step 9: Read n numbers into the array arr.
Step 10: Check each element using the isPrime() function.
Step 11: If an element is prime, store it in the prime array.
Step 12: Display all the prime numbers stored in the prime array.
Step 13: Stop.

*/

/* **********SOURCE CODE********** */
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

/* **********OUTPUT**********

Enter the Number of Elements:4
Enter 4 Numbers:
1
2
3
4

Prime Numbers are:2 3

*/     
