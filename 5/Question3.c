#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/dir.h>
#include<sys/stat.h>

#pragma pack(1)
struct fileinfo
{
	char filename[20];
	int size;
	int ino;
	int block;
	int link;
};	

int main(int argc, char* argv[])
{
	struct fileinfo fobj;
	struct dirent *entry = NULL;
	DIR *dp = NULL;
	struct stat sobj;
	char name[30];
	int fd=0;
	int Ret =0;
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
			strcpy(fobj.filename,name);
			fobj.size = sobj.st_size;
			fobj.ino = sobj.st_ino;	
			fobj.block = sobj.st_blocks;
			fobj.link = sobj.st_nlink;
			
		}
		write(fd,&fobj,sizeof(fobj));
		memset(&fobj,0,sizeof(fobj));
	}
	fd = open(argv[2],O_RDONLY);
	while(Ret = read(fd,&fobj,sizeof(fobj)) != 0)
	{
		printf("file name is:%s\n",fobj.filename);
		printf("file size is:%d\n",fobj.size);
		printf("Inode Number is:%d\n",fobj.ino);
		printf("Block number is:%d\n",fobj.block);
		printf("Link Count is:%d\n",fobj.link);
	}
	return 0;
}	
