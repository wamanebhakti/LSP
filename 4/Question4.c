#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd=0;
    int fd1=0;
    int iSize=10;
    int ret=0;
    
    struct dirent *entry = NULL;
    DIR *dp=NULL;
    char buffer[20];
    struct stat sobj;
    char name[20];
    
    if(argc!=3)
    {
    	printf("Insufficient Arguments");
    }
    
    dp=opendir(argv[1]);
    if(dp==NULL)
    {
    	printf("can't open directory");
    	return -1;
    }
    
    fd=creat(argv[2],0777);
    if(fd==-1)
    {
    	printf("File is not created successfully");
    	return -1;
    }
    
    while((entry=readdir(dp))!=NULL)
    {
    	sprintf(name,"%s/%s",argv[1],entry->d_name);
    	stat(name,&sobj);
    	if(S_ISREG(sobj.st_mode))
    	{
    		fd1=open(name,O_RDWR);
    		ret=read(fd1,buffer,iSize);
    		write(fd,buffer,ret);
    	}
    }
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
