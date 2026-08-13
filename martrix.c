#include<stdio.h>
#define MAX 10

//function to calculate row sum

void rowSum(int matrix[MAX][MAX],int r, int c) {
  printf("\nRow Sums:\n");
  for(int i=0;i<r;i++){
    int sum=0;
    for(int j=0;j<c;j++){
      sum+=matrix[i][j];
    }
    printf("Row %d=%d\n",i+1,sum);
  }
}

//function to calculate Colum sum
void columnSum(int matrix[MAX][MAX],int r, int c) {
  printf("\nColumn Sums:\n");
  for(int j=0;j<c;j++){
    int sum=0;
    for(int i=0;i<r;i++){
      sum+=matrix[i][j];
    }
    printf("Column %d=%d\n",j+1,sum);
  }
}



//function to calculate diagonal sum
void rowSum(int matrix[MAX][MAX],int r, int c) {
  if(r!=c){
    printf("\nDiagonal sum can onl;y be calculated for a square matrix.\n");
    return;
  }
    int sum=0;
    for(int i=0;i<r;i++){
      sum+=matrix[i][j];
    }
    printf("Main Diagonal Sum= %d=%d\n",j+1,sum);
  }

//function to calculate Transpose of the matrix
void rowSum(int matrix[MAX][MAX],int r, int c) {
    printf("\nTranspose of the Matrix:");
    for(j=0;j<c;j++){
    for(int i=0;i<r;i++){
      printf("%d\t",matrix[i][j]);
    }
    prinf("\n");
  }
}


int main(){
  int matrix[MAX][MAX];
  int rows,cols;

  printf("Enter Number of Rows:");
  scanf("%d",&rows);

  printf("Enter Number of Columns:");
  scanf("%d",&cols);

  printf("\nEnter the transaction Matrix:\n");
  for(int i=0;i<roes;i++){
for(int j=0;j<cols;j++){
scanf("%d",&matrix[i]);
}
}

printf("\nMATRIX:");
for(i=0;i<rows;i++){
  for(j=0;j<cols;j++){
    printf("%d\t",matrix[i][j]);
    }
  printf("\n");
}

rowSum(matrix,rows,cols);
colmnSum(matrix,rows,cols);

