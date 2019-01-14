#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

using namespace  std;

//进程等待
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
    cout<< "child quit..."<<endl;
    exit(0);
  }
  else{//parent
    int ret = wait(&fd);
    if(ret>0)
    {
      cout<< "parent quit...ret :"<< ret <<endl;
    }
  }
  return  0;
}
