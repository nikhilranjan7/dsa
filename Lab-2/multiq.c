#include <stdio.h>
#include <stdlib.h>
#include "que.h"
#include "multiq.h"

MultiQ createMQ(int num){
  MultiQ mq = (MultiQ)malloc(num*sizeof(struct multiq));
  mq->size = num;
  int i;
  for(i = 0; i < num; i++){
    mq->q[i] = (Queue)malloc(sizeof(struct queue));
    mq->q[i]->size = 0;
    mq->q[i]->head = NULL;
    mq->q[i]->tail = NULL;
  }
  return mq;
}

MultiQ addMQ(MultiQ mq, Task t){
  mq->q[t->Priority] = addQ(mq->q[t->Priority], t);
  return mq;
}

Task nextMQ(MultiQ mq){
  return front(mq->q[mq->size-1]);
}

MultiQ delNextMQ(MultiQ mq){
  mq->q[mq->size-1] = delQ(mq->q[mq->size-1]);
  return mq;
}

Task isEmptyQ(MultiQ mq){ //0 if all are empty else 1
  int i = 0;
  for(i = 0; i < num; i++){
    if(isEmptyQ(mq->q[i]) == 1){
      return 1;
    }
  }
  return 0;
}

int sizeMQ(MultiQ mq){
  int count = 0;
  for(i = 0; i < num; i++){
    count += lengthQ(mq->q[i]);
  }
  return count;
}

int sizeMQbyPriority(MultiQ mq, int p){
  int count = 0;
  count += lengthQ(mq->q[p]);
  return count;
}

Queue getQueueFromMQ(MultiQ, int p){
  return mq->q[p];
}
