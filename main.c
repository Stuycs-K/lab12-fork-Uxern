#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>

int main(){
  int num_of_seconds1, num_of_seconds2, pid1;
  int fd = open("/dev/random", O_RDONLY, 0440);
  read(fd, &num_of_seconds1, 4);
  read(fd, &num_of_seconds2, 4);
  num_of_seconds1 = abs(num_of_seconds1) % 5 + 1;
  num_of_seconds2 = abs(num_of_seconds2) % 5 + 1;
  pid_t p;
  printf("%d about to create 2 child processes.\n", getpid());
  p = fork();
    if(p < 0){
     printf("%s\n",strerror(errno));
    }
  else if(p == 0){
		printf("%d %dsecs\n", getpid(), num_of_seconds1);
		sleep(num_of_seconds1);
		printf("%d finished after %d seconds\n", getpid(), num_of_seconds1);
		exit(1);
    }
  pid1 = p;
  p = fork();
     if(p < 0){
     printf("%s\n",strerror(errno));
	 }
	else if(p == 0){
		printf("%d %dsecs\n", getpid(), num_of_seconds2);
		sleep(num_of_seconds2);
		printf("%d finished after %d seconds\n", getpid(), num_of_seconds2);
		exit(1);
	  }
      int status;
      wait(&status);
	  if(num_of_seconds1 < num_of_seconds2){
      printf("Main Process %d is done. Child %d slept for %d sec\n",getpid(), pid1, num_of_seconds1);
	  }else{
      printf("Main Process %d is done. Child %d slept for %d sec\n",getpid(), p, num_of_seconds2);
	  }		  
}
