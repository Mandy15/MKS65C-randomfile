#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int randomnum(){
  int fd = open("/dev/random", O_RDWR);
  int *buf = malloc(4);
  read(fd, buf, sizeof(int));
  close(fd);
  return *buf;
}

int main(){
  int first_random[10];
  printf("Generating random numbers:\n");
  for(int i=0; i<10; i++){
    first_random[i] = randomnum();
    printf("\trandom %d: %d\n", i, first_random[i]);
  }

  printf("\nWriting numbers to file...\n");
  int fd = open("file.txt", O_WRONLY | O_CREAT, 0600);
  write(fd, first_random, 10*sizeof(int));
  close(fd);

  printf("\nReading numbers from file...\n");
  fd = open("file.txt", O_RDONLY);
  int *second_random = malloc(10*sizeof(int));
  read(fd, second_random, 10*sizeof(int));
  close(fd);

  printf("\nVerification that written values were the same:\n");
  for(int i = 0; i < 10; i++) {
    printf("\trandom %d: %d\n", i, second_random[i]);
  }

  return 0;
}
