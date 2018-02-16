#include <stdio.h>
#include <stdlib.h>
#include "que.h"
#include "multiq.h"

int main(){
  /*
  Queue q = newQ();
  q = addQ(q, newElement(1,2));
  print(q->head);

  q = delQ(q);
  print(q->head);
  return 0;
  */
  MultiQ mq = createMQ(5);
}


/*
gcc -c que.c -o que.o
gcc -c driver.c -o driver.o
gcc -c multiq.c -o multiq.o
gcc que.o multiq.o driver.o -o prog
./prog
*/
