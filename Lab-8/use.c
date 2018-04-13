#include "tree.h"
#define COUNT 5
typedef struct tree_node Node;

void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(Node *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

int main()
{
  tree t = createTree(50);
  t = add(t, 30);
  t = add(t, 70);
  t = add(t, 20);
  t = add(t, 40);
  t = add(t, 60);
  t = add(t, 80);
  print_dfs(t);
  print2D(t);
  printf("\n");
  int i;
  i = find(t, 400);
  printf("%d\n", i);
}
