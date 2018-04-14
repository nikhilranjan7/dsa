#include "tree.h"

int main()
{
  tree t = createTree(50);
  t = add(t, 30);
  t = add(t, 70);
  t = add(t, 20);
  t = add(t, 40);
  t = add(t, 60);
  t = add(t, 80);
  t = add(t, 400);
  t = add(t, 56);
  t = add(t, 45);
  t = add(t, 22);
  print_dfs(t);
  print2D(t);
  printf("\n");
  tree f = find(t, 80);
  tree par = return_parent(t, f);
  printf("Parent:%p\n", par);
  printf("Parent:%d Child:%d\n", par->value, f->value);
  t = deleteNode(t, 30);
  print2D(t);
  // print_dfs(t);
  // t = delete(t, 30);
  // print2D(t);
}
