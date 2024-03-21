/*Write a C program to move the content of file1.txt to file2.txt and remove the file1.txt 
from directory.*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define buffersize 10000
int main()
{
	char source[25],destination[25];
	char buffer[buffersize];
	ssize_t read_in,write_out;
	printf("Enter source file name: ");
	scanf("%s",&source);
	printf("%s",source);
	int sourcefiledesc=open(source,O_RDONLY);
	if(sourcefiledesc<0)
	{
		printf("Source file not exixt");
	}
	else
	{
		printf("\nEnter destination file name: ");
		scanf("%s",&destination);
		int destfiledesc=open(destination,O_WRONLY|O_CREAT);
		while((read_in=read(sourcefiledesc,&buffer,buffersize))>0)
		{
			write_out=write(destfiledesc,&buffer,read_in);
		}
		close(sourcefiledesc);
		close(destfiledesc);
		if(remove(source)==0)
			printf("\nFile deleted successfully");
		else
			printf("\nUnable to delete the file");
	}
	return 0;
}

