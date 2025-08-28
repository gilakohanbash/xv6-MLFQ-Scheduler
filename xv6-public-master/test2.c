#include "types.h"
#include "stat.h"
#include "user.h"

void long_cpu_task(int iterations) {
  long k = 0;
  for (long i = 0; i < iterations; i++) {
    for (int j = 0; j < 1000; j++) {
      k += i * j;
    }
    if (i % (iterations/10) == 0) {
      printf(1, "process %d at %d%%\n", getpid(), (int)(i*100/iterations));
    }
  }
}

int main() {
  printf(1, "==== PRIORITY BOOST TEST ====\n");
  
  int background_pid = fork();
  if (background_pid < 0) {
    printf(1, "fork failed\n");
    exit();
  } else if (background_pid == 0) {
    //printf(1, "background process (PID: %d) starting very long task\n", getpid());
    long_cpu_task(10000000); // Make this very long
    //printf(1, "background process finished\n");
    getpinfo(getpid());
    exit();
  }
  
  for (int i = 0; i < 10; i++) {
    int pid = fork();
    if (pid < 0) {
      printf(1, "fork failed\n");
      exit();
    } else if (pid == 0) {
      //printf(1, "priority process %d (PID: %d) starting\n", i, getpid());
      long_cpu_task(500000 + i*100000);
      //printf(1, "priority process %d finished\n", i);
      getpinfo(getpid());
      exit();
    }
    wait();
  }
  
  printf(1, "all priority processes finished waiting for background process\n");
  wait();
  printf(1, "test complete, the background process should show evidence of priority boosting.\n");
  exit();
}