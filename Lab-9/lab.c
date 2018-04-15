#include "lab.h"

int hasMoreElements(Iterator it)
{
  if(it->next != NULL) return 1;
  return 0;
}

Element getNextElement(Iterator it)
{
  return it->next->e;
}

Tree createTree(int no_of_children, int v)
{
  Tree t = (Tree)malloc(sizeof(struct tree));
  t->value = v;
  t->children = (Iterator)malloc(no_of_children*sizeof(struct iterator));
  int i;
  for(i=0; i<no_of_children; i++)
  {
    t->children[i].e = (Element)malloc(sizeof(struct element));
    t->children[i].e->pointer = NULL;
  }
  t->num = no_of_children;

  return t;
}

int isEmptyTree(Tree t) //If no child then tree is empty
{
  if (t->num == 0) return 1;
  return 0;
}

Iterator getChildren(Tree t)
{
  Iterator i = t->children;
  return i;
}
