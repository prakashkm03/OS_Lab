#include  <stdio.h>
#include  <sys/types.h>
#include<unistd.h>


void  ChildProcess(void)
{
     int   i;

     for (i = 1; i <= 200; i++)
          printf("   Child Process :, value = %d\n", i);
     printf("  Child process is done \n");
}

void  ParentProcess(void)
{
     int   i;

     for (i = 1; i <= 200; i++)
          printf(" Parent Process :, value = %d\n", i);
     printf("Parent is done\n");
}
              

int  main()
{
     pid_t  pid;

     pid = fork();
     if (pid == 0) 
          ChildProcess();
     else 
          ParentProcess();


 return 0;
}
