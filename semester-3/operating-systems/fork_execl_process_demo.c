#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
  pid_t pid;
  int status;
  pid = fork();
  if(pid<0){
    printf("Fork not working");
    return 0;
  }
  else if(pid==0){
    printf("Child Process has been created\n");
    printf("Child Process PID: %d\nParent Process PID: %d\n",getpid(),getppid());
    char cwd[10240];
    getcwd(cwd,sizeof(cwd));
    printf("Execl will run inside directory: %s\n",cwd);
    execl("/bin/ls","ls","-l",(char*)NULL);
    printf("Execl failed in child.\n");
    exit(1);
  }
  else{
    printf("Waiting for child to finish\n");
    wait(&status);
    if(WIFEXITED(status))
      printf("Child Exit Status: %d\n",WEXITSTATUS(status));
    printf("Parent Exiting Now\n");
    exit(0);
  }
}
