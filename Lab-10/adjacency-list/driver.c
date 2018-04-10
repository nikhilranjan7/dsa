#include "graph.h"

int isAdjacent(Graph g, int a, int b)
{
  //If A has a arrow towards b return 1 else return 0;
  Enumeration e = getAdjacent(g, g->v[a]);
  int i = 0;
  for (i=0; i<e->size;i++){
    if (e->v[i]->label == b){
      return 1;
    }
  }
  return 0;
}


void bfs(Graph g, Vertex v) {
	int front = 0;
	int rear = 0;
	int q[4] = {0};
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
            if (!visited[i] && isAdjacent(g, u, i)) {
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
  printf("\n");
  Vertex v = newVertex(1,0);
  g = addEdge(g, v, newVertex(1,1));

  g = addEdge(g, v, newVertex(1,3));
  g = addEdge(g, newVertex(1,1), newVertex(1,2));
  print(g);
  bfs(g, v);

}
