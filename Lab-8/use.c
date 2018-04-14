#include "tree.h"

int main()
{
  tree t = createTree(50);
  t = add(t, t, 30);
  t = add(t, t, 70);
  t = add(t, t, 20);
  t = add(t, t, 40);
  t = add(t, t, 60);
  t = add(t, t, 80);
  t = add(t, t, 800);
  t = add(t, t, 900);
  t = add(t, t, 1000);
  print_dfs(t);
  print2D(t);
  printf("Height:%d\n",getBalance(t));
  /*
  printf("\n");
  printf("Height:%d\n",height(t));
  tree k = rotate(t, find(t, 80), find(t, 70), find(t, 50));
  printf("Height:%d\n",height(k));
  print2D(k);
  k = find(k, 70);
  k = rotate(k,k->left->left,k->left,k);
  printf("Height:%d\n",height(k));
  print2D(k);
  */
}
