#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[])
{
	int ret1=0,ret2=0;
	int pid1,pi2;
	int status1,status2;
	
	ret1= fork();
	if(ret1 ==0)
	{
		execl("./Process1",argv[1],argv[2],argv[3],NULL);
	}
	wait(&status1);
	
	ret2= fork();
	if(ret2 ==0)
	{
		execl("./Process2",argv[1],argv[2],argv[3],NULL);
	}
	wait(&status2);
	
	return 0;
}

