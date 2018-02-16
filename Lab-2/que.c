#include <stdio.h>
#include <stdlib.h>
#include "que.h"

Element newElement(int t, int p){
  Element e = (Element)malloc(sizeof(struct element));
  e->TASKID = t;
  e->priority = p;
  e->next = NULL;

  return e;
}

Queue newQ(){
  Queue q = (Queue)malloc(sizeof(struct queue));
  q->size = 0;
  q->head = NULL;
  q->tail = NULL;

  return q;
}

int isEmptyQ(Queue q){ //0 if empty else 1
  if (q->size == 0){
    return 0;
  }
  else{
    return 1;
  }
}

Queue delQ(Queue q){
  if(q->size == 0){
    return q;
  }
  else{
    if(q->size == 1){
      q->head = NULL;
      q->tail = NULL;
      q->size -= 1;
      return q;
    }
    else{
      q->head = q->head->next;
      q->size -= 1;
      return q;
    }
  }
}

Element front(Queue q){
  return q->head;
}

Queue addQ(Queue q, Element e){
  if(q->size == 0){
    q->head = e;
    q->tail = e;
    q->size += 1;
    return q;
  }
  else{
    q->tail->next = e;
    q->tail = e;
    q->size += 1;
    return q;
  }
}

int lengthQ(Queue q){
  return q->size;
}

void print(Element e){
  if (e == NULL){
    printf("Empty\n");
  }
  else{
    while(e != NULL){
      printf("%d, %d->",e->TASKID, e->priority);
      e = e->next;
    }
  }
  printf("\n");
}
