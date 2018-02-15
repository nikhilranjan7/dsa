//Implementation file
#include<stdio.h>
#include<stdlib.h>
#include "SeqList.h"

Element newElement(int k){
  Element e = (Element)malloc(sizeof(struct element));
  e->data = k;
  e->next = NULL;

  return e;
}

SeqList newList(){
  SeqList sl = (SeqList)malloc(sizeof(struct seqList));
  sl->size = 0;
  sl->front = NULL;
  sl->rear = NULL;

  return sl;
}
/*
SeqList insertInOrder(SeqList sl, Element e){
  //3cases
}
*/
SeqList insertAtFront(SeqList sl, Element e){
  if (sl->size == 0){
    sl->front = e;
    sl->rear = e;
  }
  else{
    e->next = sl->front;
    sl->front = e;
  }
  sl->size += 1;

  return sl;
}

SeqList insertAtEnd(SeqList sl, Element e){
  if (sl->size == 0){
    sl->front = e;
    sl->rear = e;
  }
  else{
    sl->rear->next = e;
    sl->rear = e;
  }
  sl->size += 1;

  return sl;
}

SeqList del(SeqList sl, Element e){
  if(sl->size == 0){
    return sl;
  }
  Element head = sl->front;
  Element prev = sl->front;
  //if first element is "e"
  if (head == e){
    //if size is one
    if (head == sl->rear){
      sl->front = sl->front->next;
      sl->rear = sl->front;
    }
    else{
      sl->front = sl->front->next;
    }
    return sl;
  }

  while (head != NULL){
    prev = head;
    head = head->next;
    if (head == e){
      //if last element is "e"
      if (head == sl->rear){
        prev->next = NULL;
        sl->rear = prev;
      }
      else{
        prev->next = head->next;
      }
      return sl;
    }
    else{
      prev = head;
      head = head->next;
    }
  }
  return sl;
}

void print(Element e){
  if (e == NULL){
    printf("Empty\n");
  }
  else{
    while(e != NULL){
      printf("%d->",e->data);
      e = e->next;
    }
  }
}
