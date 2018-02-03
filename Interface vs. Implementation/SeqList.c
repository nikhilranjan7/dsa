struct element {
  int data;
  struct element* next;
};
typedef struct element* Element;

struct seqList{
  int size;
  Element front;
  Element rear;
};
typedef struct seqList* SeqList;

SeqList newList(){
  SeqList sl = (SeqList)malloc(sizeof(struct seqList));
  sl->size = 0;
  sl->front = NULL;
  sl->rear = NULL;

  return sl;
}

SeqList insertInOrder(SeqList sl, Element e){
  //3cases
}

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

SeqList delete(SeqList sl, Element e){
  //3cases
}

S
