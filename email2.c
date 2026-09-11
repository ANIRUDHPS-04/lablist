#include<stdio.h>

int main(){
  int n,i,j,k;
  int same;

  printf("Enter the Number of Customers:");
  scanf("%d",&n);

  char email[n][100];

  printf("Enter Customers Addresses:\n");

  for(i=0;i<n;i++){
  scanf("%s",email[i]);
  }

  //Remove Duplicates

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){

      same=1;
      k=0;

      //Compare character by character
      while(email[i][k]!='\0' || email[j][k]!='\0'){
        if(email[i][k]!=email[j][k]){
          same=0;
          break;
        }
          k++;
      }
      
      if(same==1){

        //shift elements to the left
        for(k=j;k<n;k++){
          int x=0;
          while(email[k+1][x]!='\0'){
            email[k][x]=email[k+1][x];
            x++;
          }

          email[k][x]='\0';
        }
      
        n--;
        j--;
      }
    }
  }


printf("\nEmail Addresses after Removing Duplicates:\n");

for(i = 0;i < n;i++){
  printf("%s\n",email[i]);
}

return 0;
}
