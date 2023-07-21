#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
	int fd = 0 ;
	int ret = 0;
	char Arr[20] = {"abcd"};
	fd = open(argv[1],O_RDWR);
	if(fd != -1)
	{
		printf("File is Exixsting %d\n",fd);
	}
	write(fd,Arr,20);
	ret = lseek(fd,1024,2);
	printf("length till hole is%d\n",ret);
	write(1,Arr,ret);
	close(fd);
	return 0;
}


