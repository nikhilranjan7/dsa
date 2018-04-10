#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	int label;
	int degree;
};
typedef struct Node* Vertex;

struct graph{
	int size;
	int** am;
	Vertex* v;
};
typedef struct graph* Graph;

typedef Vertex* Enumeration;

Graph createGraph(int numV);

Enumeration getAdjacent(Graph G, Vertex v);

Graph addEdge(Graph G, Vertex v, Vertex vAdj);

int degree(Graph G, Vertex v);

void print(Graph G);

Vertex newVertex(int a, int name);

