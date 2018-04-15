#include <stdio.h>
#include <stdlib.h>

typedef struct tree* Tree;

struct element
{
  Tree pointer;
};
typedef struct element* Element;

struct iterator
{
  Element e;
  struct iterator* next;
};
typedef struct iterator* Iterator;

struct tree
{
  int value;
  Iterator children;
  int num;
};

int hasMoreElements(Iterator it);
Element getNextElement(Iterator it);

Tree createTree(int no_of_children, int v);
int isEmptyTree(Tree t);
Iterator getChildren(Tree t);
