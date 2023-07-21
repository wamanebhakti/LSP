#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    int ret=0;

    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    
    ret=mkdir(DirName,0777); 
    if(ret==0)
    {
    	printf("Directory is created\n");
    }
    
    else
    {
    	printf("Unable to create directory\n");
    }
    return 0;
}
