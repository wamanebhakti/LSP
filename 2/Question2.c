#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
    int fd = 0;
    char Buffer[]="Marvellous infosystems";

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

   
     write(fd, Buffer, strlen(Buffer));
    
    
    close(fd);

    return 0;
}
