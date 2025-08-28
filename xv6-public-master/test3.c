#include "types.h"
#include "stat.h"
#include "user.h"


//yield a lot before time expires so we always stay in high pq
void gaming_scheduler() {
  int i;
  int iterations = 100;
  
  for (i = 0; i < iterations; i++) {
    int j;
    int sum = 0;
    for (j = 0; j < 1; j++) {
      sum += j;
      sleep(1); 
    }
  
  }
}

//same thing but dont yield
void normal_process() {
  printf(1, "normal process started\n");
  int i;
  int iterations = 100000;
  
  for (i = 0; i < iterations; i++) {
    int j;
    int sum = 0;
    for (j = 0; j < 1000; j++) {
      sum += j;
    }
    
    if (i % 10000 == 0) {
      printf(1, "normal process: %d/%d iterations\n", i, iterations);
    }
  }
  
  printf(1, "normal process completed\n");
}

int main() {  
  int pid = fork();
  
  if (pid < 0) {
    printf(1, "fork failed\n");
    exit();
  } 
  else if (pid == 0) {
    gaming_scheduler();
    getpinfo(getpid());
    exit();
  } 
  else {
    normal_process();
    wait();
    getpinfo(getpid());
    exit();
  }
}