#include<stdio.h>
#include<string.h>

int main(){
  int n,i,j,k;

  printf("Enter Number of Customers:");
  scanf("%d",&n);

  char email[n][100];

  printf("Enter the Customer Email Addresses:\n");
  for(i=0;i<n;i++){
    scanf("%s",email[i]);
} 

//REmove Duplicates
for(i=0;i<n;i++){
  for(j=i+1;j<n;j++){
    if(strcmp(email[i], email[j]) == 0){

        //shift elements to left

        for(k=j;k<n-1;k++){
        strcpy(email[k],email[k+1]);
        }
        n--;
        j--;
        }
        }
        }

printf("\nEmail Addresses after Removing the Duplicates:\n");
for(i=0;i<n;i++){
  printf("%s\n",email[i]);
}

return 0;
}

