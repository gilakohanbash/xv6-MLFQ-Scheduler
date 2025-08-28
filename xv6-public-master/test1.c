#include "types.h"
#include "stat.h"
#include "user.h"

void cpu_intensive() {
  int i, j, k = 0;
  for (i = 0; i < 500000; i++) {
    for (j = 0; j < 1000; j++) {
      k = k + i * j;
    }
  }
}

void io_intensive() {
  int i;
  for (i = 0; i < 100; i++) {
    sleep(1); 
  }
}

int main() {
  int pid = fork();
  
  if (pid < 0) {
      exit();
  } 
  else if (pid == 0) {
    // child
    cpu_intensive();
    getpinfo(getpid());
    exit();
  } else {
    // parent
    io_intensive();
    wait();
    getpinfo(getpid());
    exit();
  }
}