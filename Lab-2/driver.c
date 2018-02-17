#include <stdio.h>
#include <stdlib.h>
#include "que.h"
#include "multiq.h"
#include "file.h"

int main(){
  MultiQ mq = createMQ(10);
  FILE* f = NULL;
  mq = loadData(f);
  printq(mq);
  printf("\n\n");
  mq = testDel(mq, 10);
  printq(mq);
}


/*
gcc -c que.c -o que.o
gcc -c driver.c -o driver.o
gcc -c multiq.c -o multiq.o
gcc -c file.c -o file.o
gcc que.o multiq.o driver.o file.o -o prog
./prog
*/
