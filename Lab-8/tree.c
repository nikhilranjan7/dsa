#include "tree.h"

tree createTree(int v)
{
  tree t = (tree)malloc(sizeof(struct tree_node));
  t->value = v;
  t->left = NULL;
  t->right = NULL:
  t->h_info = 0;

  return t;
}



tree add(tree t, int v);
int find(tree t, int v);
tree delete(tree t, int v);
void print_dfs(tree t);
