#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define BLOCKSIZE 1024

int main(int argc, char*argv[])
{
	int fd= 0;
	int Ret = 0;
	char Buffer[BLOCKSIZE];
	if(argc != 2)
	{
	  printf("Invalid Number of arguments\n");
	  return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	if(fd== -1)
	{
		printf("Unable to open File");
		return -1;
	}
	
	while((Ret = read(fd,Buffer,sizeof(Buffer))) != 0)
	{
		write(1,Buffer,Ret);
		memset(Buffer,0,sizeof(Buffer));
	}
	
	close(fd);
	return 0;
}

