#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    int Ret1=0;
    
    
    
    Ret = fork();
    
    if(Ret==0)
    {
    	printf("Child with pid :%d\n",getpid());
    	
    	Ret1=fork();
    	if(Ret1==0)
    	{
    		printf("Child with pid:%d\n",getpid());
    	}
    }
       else
       {
       	 printf("Parent: %d\n",getpid());
       }
    
    
    return 0;
}
