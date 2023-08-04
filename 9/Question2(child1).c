#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{
	char Buffer[512];
	char size1[5];
	int iCnt = 0,iRet = 0,i=0,fd=0,fd1=0;
	
	fd = open(argv[1],O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file");
		return -1;
	}
	
	printf("%s\n In this file",argv[1]);
	while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
	{
		for(i = 0; i < iRet ; i++)
		{
			if((Buffer[i] >= 'A' ) && (Buffer[i] <='Z'))
			{
				iCnt++;
			}
		}
	}
	
	printf("NUmber of Capital characters are: %d\n",iCnt);
	
	sprintf(size1,"%d",iCnt);
	
	fd1 = open(argv[2],O_RDWR | O_APPEND);
	if(fd1 == -1)
	{
		printf("Unable to open file");
		return -1;
	}
	write(fd1,size1,strlen(size1));
	
	close(fd);
	return 0;
}

