#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

typedef struct tree_node Node;
typedef struct tree_node* tree;

struct tree_node
{
  int value;
  tree left;
  tree right;
  int height;
};

tree createTree(int v);
tree add(tree root, tree t, int v);
tree find(tree t, int v);
tree deleteNode(tree root, int key);
void print_dfs(tree t);
tree rotate(tree root, tree X, tree Y, tree Z);

int height(tree root);
int isleaf(tree t);
tree return_parent(tree root, tree child);
tree inOrderSuccessor(tree root, tree n);
tree minValue(tree node);
void print2DUtil(Node *root, int space);
void print2D(Node *root);
tree balance(tree t);
int getBalance(tree t);
