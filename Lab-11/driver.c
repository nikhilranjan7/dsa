#include "graph.h"
int max;

struct stack_node
{
	int data;
	struct stack_node* next;
};

typedef struct stack_node* Stack_node;

struct stack
{
	Stack_node head;
};

typedef struct stack* Stack;

Stack_node newNode(int d)
{
	Stack_node n = (Stack_node)malloc(sizeof(struct stack_node));
	n->data = d;
	n->next = NULL;
	
	return n;
}

Graph loadData(Graph g,FILE* f)
{
    int t, p;
	f = fopen("graph0.txt", "r");

	while (!feof(f))
	{
		fscanf(f, "%d %d", &t,&p);
		int m1 = t % 27771;
		int m2 = p % 27771;
		if (max > m1 && max > m2){}
		else if (m1 > m2)
			max = m1;
		else
			max = m2;
		Vertex v1 = newVertex(10, m1);
		Vertex v2 = newVertex(10, m2);
		g = addEdge(g, v1, v2);
	}
	fclose(f);
  return g;
}

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
	int q[12] = {0};
	int visited[12] = {0};
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

Stack insertAtFront(Stack stack, int v)
{
  if (stack->head == NULL){
    stack->head = newNode(v);
  }
  else{
  	Stack_node n = newNode(v);
    n->next = stack->head;
    stack->head = n;
  }

  return stack;
}

void topologicalSortUtil(Graph g,int v, int* visited, Stack stack)
{
        // Mark the current node as visited.
        visited[v] = 1;
 
        // Recur for all the vertices adjacent to this vertex
        int i;
        for(i=0;i<g->size;i++)
        {
        	if (isAdjacent(g, v, i) == 1)
        	{
        		if (visited[i] == 0)
        		{
        			topologicalSortUtil(g, i, visited, stack);
        		}
        	}
        }
        printf("Node is no. %d\n",v);
        stack = insertAtFront(stack,v);
}

void print_stack(Stack e){
  int i=1;
  if (e->head == NULL){
    printf("Empty\n");
  }
  else{
  	Stack_node n = e->head;
    while(n != NULL){
      printf("Node no. %d-> %d\n",i,n->data);
      n = n->next;
      i++;
    }
  }
}

   
void topologicalSort(Graph g)
{
    // Mark all the vertices as not visited
    int* visited = (int*)malloc(g->size*sizeof(int));
    int i;
    for(i=0;i<g->size;i++)
    {
    	visited[i] = 0;
    }
    
    Stack stack = (Stack)malloc(sizeof(struct stack));
    stack->head = NULL;

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for(i=0;i<g->size;i++)
    { 
        if (visited[i] == 0)
            topologicalSortUtil(g,i,visited,stack);
	}
    // Print contents of stack
    print_stack(stack);
}

int main(){
  Graph g = createGraph(27771);
  printf("\n");
  FILE* f;
  g = loadData(g,f);
  print(g);
  topologicalSort(g);
  printf("\n");
}

