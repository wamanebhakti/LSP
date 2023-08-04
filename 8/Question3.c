#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    int Ret1=0;
    
    int PID = 0;

    Ret = fork();
    Ret1=fork();

    if(Ret > 0 && Ret1 > 0)
    {
    	printf("Parent\n");
    }
    
    else if(Ret==0 && Ret1 > 0)
    {
    	printf("Process2 with pid %d\n",getpid());
    }
    else if(Ret>0 && Ret1==0)
    {
    	printf("Process3 with pid %d\n",getpid());
    }
    else
    {
    	printf("Process4 with pid %d\n",getpid());
    }
    
    return 0;
}
