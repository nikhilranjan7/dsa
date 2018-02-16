// ADT Queue interface
struct element{
  int TASKID;
  int priority;
  struct element* next;
};
typedef struct element* Element;

struct queue{
  int size;
  Element head;
  Element tail;
};
typedef struct queue* Queue;

Element newElement(int t, int p);

Queue newQ();

int isEmptyQ(Queue q); //1 is true , 0 if false

Queue delQ(Queue q);

Element front(Queue q);

Queue addQ(Queue q, Element e);

int lengthQ(Queue q);

//to debug
void print(Element e);
