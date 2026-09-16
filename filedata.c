#include<stdio.h>

int main(int argc, char*argv[])
{
  FILE*source,*destination;
  char ch;

  if(argc!=3)
  {
    printf("Usage:%s source_file 
        destination_file\n",argv[0]);
    return 1;
  }

  source=fopen(argv[1],"r");
  destination=fopen(argv[2],"w");

  if(source==NULL||destination==NULL)
  {
    printf("Error Opening file.\n");
    return 1;
  }

  while((ch=fgetc(source))!=EOF)
  {
    f
