#include "graph.h"

struct AL_node* newAdjListNode(Vertex v)
{
    struct AL_node* newNode = (struct AL_node*) malloc(sizeof(struct AL_node));
    newNode->v = v;
    newNode->next = NULL;
    return newNode;
}

Vertex newVertex(int a, int name){
	Vertex v = (struct Node*)malloc(sizeof(struct Node));
	v->data = a;
	v->degree = 0;
	v->label = name;

	return v;
}

Graph createGraph(int numV){
	Graph g = (Graph)malloc(sizeof(struct graph));
	g->size = numV;
	g->array = (struct AL*)malloc(numV*sizeof(struct AL));
	int i;
  for (i = 0; i < numV; ++i)
      g->array[i].head = NULL;

	g->v = (Vertex*)malloc(numV*sizeof(Vertex));
	for (i=0; i<numV; i++)
        	g->v[i] = newVertex(10, i);

	return g;
}

Enumeration getAdjacent(Graph G, Vertex v)
{
	int i,j=0;
	Enumeration e = (Enumeration)malloc(sizeof(struct enumeration));
	e->v = (Vertex*)malloc(G->size*sizeof(struct Node));
	struct AL iter = G->array[v->label];
	while (iter.head != NULL)
	{
		e->v[j] = iter.head->v;
		j++;
		iter.head = iter.head->next;
	}
	e->v = (Vertex*)realloc(e->v, j*sizeof(struct Node));
	e->size = j;

	return e;
}

Graph addEdge(Graph G, Vertex v, Vertex vAdj){
	if (G->array[v->label].head == NULL)
	{
		G->array[v->label].head = newAdjListNode(vAdj);
		v->degree += 1;

		return G;
	}

	struct AL_node* iter = G->array[v->label].head;

	while (iter->next != NULL)
	{
		iter = iter->next;
	}
	iter->next = newAdjListNode(vAdj);
	v->degree += 1;

	return G;
}

int degree(Graph G, Vertex v){
	return v->degree;
}

void print(Graph G){
	int i,j;
	for(i=0; i<G->size; i++)
	{
		struct AL iter = G->array[i];
		printf("From vertex %d:",i);
		while (iter.head != NULL)
		{
			printf("%d->",iter.head->v->label);
			iter.head = iter.head->next;
		}
		printf("\n");
	}
}
