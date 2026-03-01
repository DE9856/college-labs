#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
  mkfifo("AtoB",0666);
  mkfifo("BtoA",0666);
  int fd_read = open("AtoB",O_RDONLY);
  int fd_write = open("BtoA",O_WRONLY);
  char send[100],recv[100];
  while(1){
    read(fd_read,recv,100);
    printf("A: %s",recv);
    printf("B: ");
    fgets(send,100,stdin);
    write(fd_write,send,100);
  }
  close(fd_read);
  close(fd_write);
  return 0;
}
