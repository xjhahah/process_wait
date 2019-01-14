#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

using namespace  std;

//进程非阻塞等待
int  main()
{
  pid_t fd = fork();
  if(fd < 0)
  {
    cout<< "fork error"<<endl;
    return -1;
  }
  else if(fd == 0)
  {
    //child
    sleep(2);
    cout<< "child is running...pid: "<< getpid() <<endl;
    exit(1);
  }
  else{//parent
    int status = 0;
    pid_t ret = 0;
    do{
      ret = waitpid(-1,&status,WNOHANG);
      if(ret == 0)
      {
        cout<< "child is running..."<<endl;
      }
      sleep(1);
    }while(ret == 0);
    if(WIFEXITED(status) && ret == fd)
    {
      cout<< "wait child sucess...,child return status is : "<< WEXITSTATUS(status) <<endl;
    }
    else{
      cout<< "wait child failed..."<<endl;
      return -1;
    }
  }
  return  0;
}
