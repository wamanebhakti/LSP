#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
	DIR *dp=NULL;
	struct dirent * entry = NULL;
	struct stat sobj;
	char DirName[20];
	char name[20];
	
	printf("Enter the of directory");
	scanf("%s",DirName);
	
	dp=opendir(DirName);
	
	if(dp==NULL)
	{
		printf("Unable to open directoty\n");
		return -1;
	}
	
	else
	{
		printf("Directoty is successfully open\n");
	}
	
	
	while((entry = readdir(dp))!=NULL)
	{
		
		sprintf(name,"%s/%s",DirName,entry->d_name);
		stat(name,&sobj);
		if(S_ISREG(sobj.st_mode))
		{
			printf("File name :%s It is regular file\n",name);
		}
		
		else if(S_ISDIR(sobj.st_mode))
		{
			printf("File name :%s It is directoty file\n",name);
		}
		
		else if(S_ISLNK(sobj.st_mode))
		{
			printf("File name :%s It is symbolic file\n",name);
		}
	
	}
	
	
	
	closedir(dp);
	
	
	return 0;
	

}
