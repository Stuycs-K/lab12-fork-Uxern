#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>

int main(){
  pid_t p;
  printf("_PID_ about to create 2 child processes.\n");
  p = fork();
  if(p < 0){
    printf("%s\n",strerror(errno));
    }
  else if(p == 0){
      int fd = open("/dev/random", O_RDONLY, 0440);
      int num_of_seconds;
      num_of_seconds = (read(fd, &x, 4) % 5) + 1;
      printf("%d %dsecs", getpid(), num_of_seconds);
      sleep(num_of_seconds);
      exit(1);
    }
    else{
      int *status;
      wait(&status);
      
    }
}
