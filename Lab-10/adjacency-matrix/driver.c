#include "graph.h"
 
void bfs(Graph g, Vertex v) {
	int front = 0;
	int rear = 0;
	int q[16] = { 0 };
	int visited[4] = {0};
    // make vertex v visited
    visited[v->label] = 1;
    // enqueue vertex v
    q[rear] = v->label; // insert at rear
    rear++; // increment rear
 
    while (rear != front) // condition for empty queue
    {
        // dequeue
        int u = q[front];
        printf("%d ", u);
        front++;
 
        // check adjacent nodes from u
        int i = 0, k;
        for (i = 0; i < (g->size); i++) {
            // if there is adjacent vertex enqueue it
            if (!visited[i] && g->am[u][i]) {
                q[rear] = i;
                rear++;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main(){
	Graph g = createGraph(4);
	print(g);
	Vertex v = newVertex(99, 2);
	g = addEdge(g, v, newVertex(99, 3));
	g = addEdge(g, v, newVertex(99, 0));
	g = addEdge(g,  newVertex(99, 0), newVertex(99, 1));


	
	int i;
	
	print(g);
	printf("\n");
	bfs(g, v);
}
