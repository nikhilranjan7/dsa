#include "graph.h"

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
	g->am = (int**)malloc(numV*sizeof(int*));
	int i;
	for (i=0; i<numV; i++)
         g->am[i] = (int *)malloc(g->size * sizeof(int));
 
	g->v = (Vertex*)malloc(numV*sizeof(Vertex));
	for (i=0; i<numV; i++)
        	g->v[i] = newVertex(10, i);
	int j;
				
	for(i=0;i<numV;i++)
		for(j=0;j<numV;j++)
			(g->am)[i][j] = 0;
	return g;
}

Enumeration getAdjacent(Graph G, Vertex v)
{
	int i,j=0;
	Enumeration e = (Enumeration)malloc(G->size*sizeof(Vertex));
	for(i=0; i<G->size; i++){
		if(G->am[v->label][i] == 1)
		{
			e[j] = v;
			j++;	
		}
	}
	Enumeration a = (Enumeration)realloc(e, j*sizeof(Vertex));	
	
	return a;
}

Graph addEdge(Graph G, Vertex v, Vertex vAdj){
	G->v[v->label]->degree += 1;
	G->am[v->label][vAdj->label] = 1;
	return G;
}

int degree(Graph G, Vertex v){
	return G->v[v->label]->degree;
}

void print(Graph G){
	int i,j;
	for(i=0;i<G->size;i++)
	{	
		printf("\n");
		for(j=0;j<G->size;j++)
			printf("%d ",G->am[i][j]);
	}
	printf("\n");
}























