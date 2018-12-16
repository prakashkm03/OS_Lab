#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
 #include <unistd.h>
 
extern int errno;

using namespace std;

int main()
{
   int f = open("pkfile1.txt", O_RDONLY | O_CREAT);
    
   cout<<"f ="<<f;
   close(f);


   if(f==-1)
   {
   	cout<<"Error Number :" <<errno;
   	
   }
   return 0;

}
