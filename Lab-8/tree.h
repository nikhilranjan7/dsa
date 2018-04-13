#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node* tree;

struct tree_node
{
  int value;
  tree left;
  tree right;
  int h_info;
}

tree createTree(int v);
tree add(tree t, int v);
int find(tree t, int v);
tree delete(tree t, int v);
void print_dfs(tree t);
