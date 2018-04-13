#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	int label;
	int degree;
};
typedef struct Node* Vertex;

struct AL_node{
	Vertex v;
	struct AL_node* next;
};

struct AL{
	struct AL_node* head;
};

struct graph{
	int size;
	Vertex* v;
	struct AL* array;
};
typedef struct graph* Graph;

struct enumeration{
	Vertex* v;
	int size;
};
typedef struct enumeration* Enumeration;

struct AL_node* newAdjListNode(Vertex v);

Graph createGraph(int numV);

Enumeration getAdjacent(Graph G, Vertex v);

Graph addEdge(Graph G, Vertex v, Vertex vAdj);

int degree(Graph G, Vertex v);

void print(Graph G);

Vertex newVertex(int a, int name);

