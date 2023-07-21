#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/dir.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
	
	struct dirent *entry = NULL;
	DIR *dp = NULL;
	struct stat sobj;
	char name[30];
	char Buffer[100];
	char fname[20];
	int fd=0;
	int fd1 = 0;
	if(argc != 3)
	{
	 	printf("Insufficient Arguments");
	 	return -1;
	}
	 
	dp = opendir(argv[1]);
	if(dp == NULL)
	{
		printf("Cant open the Directory");
		return -1;
	}
	
	fd = creat(argv[2],0777);
	while((entry = readdir(dp)) != NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&sobj);
		if(S_ISREG(sobj.st_mode))
		{
			fd1 = open(name,O_RDWR);
			read(fd1,Buffer,sizeof(Buffer));
			strcpy(fname,name);
			write(fd,fname,sizeof(fname));
			write(fd,Buffer,sizeof(Buffer));
			memset(Buffer,0,sizeof(Buffer));
			}
	}
	
	return 0;
}	
