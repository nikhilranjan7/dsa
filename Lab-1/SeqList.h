//Interface file

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

Element newElement(int k);

SeqList newList();

SeqList insertInOrder(SeqList sl, Element e);

SeqList insertAtFront(SeqList sl, Element e);

SeqList insertAtEnd(SeqList sl, Element e);

SeqList del(SeqList sl, Element e);

SeqList deleteAtFront(SeqList sl);

Element find(SeqList sl, int k);

void print(Element e);
