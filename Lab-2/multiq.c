#include <stdio.h>
#include <stdlib.h>
#include "que.h"
#include "multiq.h"

MultiQ createMQ(int num){
  MultiQ mq = (MultiQ)malloc(num*sizeof(struct multiQ));
  mq->size = num;
  int i;
  for(i = 0; i < num; i++){
    mq[i].q = newQ();
  }
  return mq;
}

MultiQ addMQ(MultiQ mq, Element t){
  mq[t->priority].q = addQ(mq[t->priority].q, t);
  return mq;
}

Task nextMQ(MultiQ mq){
  return front(mq[(mq->size)-1].q);
}

MultiQ delNextMQ(MultiQ mq){
  mq[(mq->size)-1].q = delQ(mq[(mq->size)-1].q);
  return mq;
}

int isEmptyMQ(MultiQ mq){ //0 if all are empty else 1
  int i = 0;
  for(i = 0; i < mq->size; i++){
    if(isEmptyQ(mq[i].q) == 1){
      return 1;
    }
  }
  return 0;
}

int sizeMQ(MultiQ mq){
  int count = 0, i = 0;
  for(i = 0; i < mq->size; i++){
    count += lengthQ(mq[i].q);
  }
  return count;
}

int sizeMQbyPriority(MultiQ mq, int p){
  int count = 0;
  count += lengthQ(mq[p].q);
  return count;
}

Queue getQueueFromMQ(MultiQ mq, int p){
  return mq[p].q;
}

void printq(MultiQ mq){
  int i;
  for(i=0;i<mq->size;i++){
    print(mq[i].q->head);
  }
}
