#include<stdio.h>
int main(){
  int i,j,a[10][10],b[10][10],r1,r2,c1,c2;
  int k,c[10][10];
  printf("Enter the noof rows and cols of 1st matrix\n");
  scanf("%d %d",&r1,&c1);
  printf("Enter the data\n");
  for(i=0;i<r1;i++){
    for(j=0;j<c1;j++)
      scanf("%d",&a[i][j]);
  }
  printf("Enter the noof rows and cols of 2nd matrix\n");
  scanf("%d %d",&r2,&c2);
  printf("Enter the data\n");
  for(i=0;i<r2;i++){
    for(j=0;j<c2;j++)
      scanf("%d",&b[i][j]);
  }
  if(c1!=r2){
    printf("Not possible because c1=r2\n");
    return 0;
  }
  printf("Matrix multiplication\n");
  for(i=0;i<r1;i++){
    for(j=0;j<c2;j++){
      c[i][j]=0;
      for(k=0;k<c1;k++){
        c[i][j]+=a[i][k]*b[k][j];
      }}  }
  for(i=0;i<r1;i++){
    for(j=0;j<c2;j++)
      printf("%d\t",c[i][j]);
    printf("\n");
}
  return 0;
}
