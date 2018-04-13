#include "tree.h"

tree createTree(int v)
{
  tree t = (tree)malloc(sizeof(struct tree_node));
  t->value = v;
  t->left = NULL;
  t->right = NULL;
  t->h_info = 0;

  return t;
}



tree add(tree t, int v)
{
    tree a = t;
    if(t->value > v)
    {
      if(t->left == NULL)
        t->left = createTree(v);
      else
        t = add(t->left, v);
    }
    else
    {
      if(t->right == NULL)
        t->right = createTree(v);
      else
        t = add(t->right, v);
    }

    return a;
}

int find(tree t, int v)
{
  if (t == NULL)
    return 0;
  else if (t->value == v)
    return 1;
  else
  {
    if(t->value > v)
      return find(t->left, v);
    else
      return find(t->right, v);
  }
}

tree delete(tree t, int v);

void print_dfs(tree t)
{
  if (t == NULL)
        return;

     // first recur on left subtree
     print_dfs(t->left);

     // then recur on right subtree
     print_dfs(t->right);

     // now deal with the node
     printf("%d->",t->value);
    /*
  if (t != NULL)
    print_dfs(t->left);
    print_dfs(t->right);
    printf("%d->",t->value);
    */
}
