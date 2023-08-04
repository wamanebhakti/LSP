#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(int argc, char* argv[])
{
	char Buffer[512];
	char size[5];
	int iCnt = 0,iRet = 0,i=0,fd=0,fd1=0;
	
	printf("%s\n",argv[0]);
	printf("%s\n",argv[1]);
	printf("%s\n",argv[2]);
	
	fd = open(argv[0],O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file");
		return -1;
	}
	
	printf("In this file%s\n",argv[0]);
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
	
	printf("Number of Capital characters are: %d\n",iCnt);
	
	sprintf(size,"%d",iCnt);
	printf("%s\n",size);
	fd1 = creat(argv[2],0777);
	if(fd1 == -1)
	{
		printf("Unable to create file");
		return -1;
	}
	
	write(fd1,size,strlen(size));
	
	close(fd);
	return 0;
}

